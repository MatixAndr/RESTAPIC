//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "routes.h"
#include "server.h"
#include "user.h"

void handle_request(const char* raw_request, SOCKET client_socket) {
    HttpRequest request;
    HttpResponse response;

    if (!parse_http_request(raw_request, &request)) {
        prepare_http_response(&response, 400, "application/json",
                              "{\"error\": \"Invalid request\"}");
        send_http_response(client_socket, &response);
        return;
    }

    if (strcmp(request.method, "GET") == 0) {
        if (strcmp(request.path, "/users") == 0) {
            handle_get_users(client_socket);
        } else if (strncmp(request.path, "/users/", 7) == 0) {
            int user_id = atoi(request.path + 7);
            handle_get_user_by_id(user_id, client_socket);
        }
    } else if (strcmp(request.method, "POST") == 0 &&
               strcmp(request.path, "/users") == 0) {
        handle_post_user(request.body, client_socket);
    } else if (strcmp(request.method, "PATCH") == 0 &&
               strncmp(request.path, "/users/", 7) == 0) {
        int user_id = atoi(request.path + 7);
        handle_patch_user(user_id, request.body, client_socket);
    } else if (strcmp(request.method, "PUT") == 0 &&
               strncmp(request.path, "/users/", 7) == 0) {
        int user_id = atoi(request.path + 7);
        handle_put_user(user_id, request.body, client_socket);
    } else if (strcmp(request.method, "DELETE") == 0 &&
               strncmp(request.path, "/users/", 7) == 0) {
        int user_id = atoi(request.path + 7);
        handle_delete_user(user_id, client_socket);
    }
}

void handle_get_users(SOCKET client_socket) {
    int count;
    User* users = get_all_users(&count);
    HttpResponse response;

    json_object* json_array = json_object_new_array();
    for (int i = 0; i < count; i++) {
        json_object* user_obj = json_object_new_object();
        json_object_object_add(user_obj, "id",
            json_object_new_int(users[i].id));
        json_object_object_add(user_obj, "name",
            json_object_new_string(users[i].name));
        json_object_object_add(user_obj, "lastname",
            json_object_new_string(users[i].lastname));
        json_object_array_add(json_array, user_obj);
    }

    const char* json_str = json_object_to_json_string(json_array);
    prepare_http_response(&response, 200, "application/json", json_str);
    send_http_response(client_socket, &response);

    json_object_put(json_array);
}

void handle_get_user_by_id(int user_id, SOCKET client_socket) {
    HttpResponse response;
    User* user = get_user_by_id(user_id);

    if (user) {
        json_object* user_obj = json_object_new_object();
        json_object_object_add(user_obj, "id",
            json_object_new_int(user->id));
        json_object_object_add(user_obj, "name",
            json_object_new_string(user->name));
        json_object_object_add(user_obj, "lastname",
            json_object_new_string(user->lastname));

        const char* json_str = json_object_to_json_string(user_obj);
        prepare_http_response(&response, 200, "application/json", json_str);

        json_object_put(user_obj);
    } else {
        prepare_http_response(&response, 400, "application/json",
                              "{\"error\": \"User not found\"}");
    }

    send_http_response(client_socket, &response);
}

void handle_post_user(const char* body, SOCKET client_socket) {
    HttpResponse response;
    json_object* parsed_json = json_tokener_parse(body);

    if (parsed_json &&
        json_object_object_get_ex(parsed_json, "name", NULL) &&
        json_object_object_get_ex(parsed_json, "lastname", NULL)) {

        const char* name = json_object_get_string(
            json_object_object_get(parsed_json, "name"));
        const char* lastname = json_object_get_string(
            json_object_object_get(parsed_json, "lastname"));

        int new_id = add_user(name, lastname);

        char response_body[128];
        snprintf(response_body, sizeof(response_body),
                 "{\"id\": %d}", new_id);

        prepare_http_response(&response, 201, "application/json", response_body);
    } else {
        prepare_http_response(&response, 400, "application/json",
                              "{\"error\": \"Invalid request body\"}");
    }

    send_http_response(client_socket, &response);
    json_object_put(parsed_json);
}

void handle_patch_user(int user_id, const char* body, SOCKET client_socket) {
    HttpResponse response;
    json_object* parsed_json = json_tokener_parse(body);

    if (parsed_json &&
        (json_object_object_get_ex(parsed_json, "name", NULL) ||
         json_object_object_get_ex(parsed_json, "lastname", NULL))) {

        const char* name = json_object_object_get_ex(parsed_json, "name", NULL)
            ? json_object_get_string(json_object_object_get(parsed_json, "name"))
            : NULL;

        const char* lastname = json_object_object_get_ex(parsed_json, "lastname", NULL)
            ? json_object_get_string(json_object_object_get(parsed_json, "lastname"))
            : NULL;

        if (update_user_partial(user_id, name, lastname)) {
            prepare_http_response(&response, 204, "application/json", "");
        } else {
            prepare_http_response(&response, 400, "application/json",
                                  "{\"error\": \"User not found\"}");
        }
    } else {
        prepare_http_response(&response, 400, "application/json",
                              "{\"error\": \"Invalid request body\"}");
    }

    send_http_response(client_socket, &response);
    json_object_put(parsed_json);
}

void handle_put_user(int user_id, const char* body, SOCKET client_socket) {
    HttpResponse response;
    json_object* parsed_json = json_tokener_parse(body);

    if (parsed_json &&
        json_object_object_get_ex(parsed_json, "name", NULL) &&
        json_object_object_get_ex(parsed_json, "lastname", NULL)) {

        const char* name = json_object_get_string(
            json_object_object_get(parsed_json, "name"));
        const char* lastname = json_object_get_string(
            json_object_object_get(parsed_json, "lastname"));

        update_user_full(user_id, name, lastname);
        prepare_http_response(&response, 204, "application/json", "");
    } else {
        prepare_http_response(&response, 400, "application/json",
                              "{\"error\": \"Invalid request body\"}");
    }

    send_http_response(client_socket, &response);
    json_object_put(parsed_json);
}

void handle_delete_user(int user_id, SOCKET client_socket) {
    HttpResponse response;

    if (delete_user(user_id)) {
        prepare_http_response(&response, 204, "application/json", "");
    } else {
        prepare_http_response(&response, 400, "application/json",
                              "{\"error\": \"User not found\"}");
    }

    send_http_response(client_socket, &response);
}