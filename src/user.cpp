//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#include <stdio.h>
#include <string.h>
#include "user.h"

static User users[MAX_USERS];
static int user_count = 0;

int add_user(const char* name, const char* lastname) {
    if (user_count >= MAX_USERS) {
        return -1;
    }

    User new_user;
    new_user.id = user_count + 1;
    strncpy(new_user.name, name, MAX_NAME_LENGTH - 1);
    strncpy(new_user.lastname, lastname, MAX_NAME_LENGTH - 1);
    new_user.name[MAX_NAME_LENGTH - 1] = '\0';
    new_user.lastname[MAX_NAME_LENGTH - 1] = '\0';

    users[user_count++] = new_user;
    return new_user.id;
}

User* get_user_by_id(int id) {
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            return &users[i];
        }
    }
    return NULL;
}

int update_user_partial(int id, const char* name, const char* lastname) {
    User* user = get_user_by_id(id);
    if (!user) return 0;

    if (name) strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    if (lastname) strncpy(user->lastname, lastname, MAX_NAME_LENGTH - 1);

    return 1;
}

int update_user_full(int id, const char* name, const char* lastname) {
    User* user = get_user_by_id(id);
    if (!user) {
        return add_user(name, lastname);
    }

    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    strncpy(user->lastname, lastname, MAX_NAME_LENGTH - 1);
    return 1;
}

int delete_user(int id) {
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            for (int j = i; j < user_count - 1; j++) {
                users[j] = users[j + 1];
            }
            user_count--;
            return 1;
        }
    }
    return 0;
}

User* get_all_users(int* count) {
    *count = user_count;
    return users;
}