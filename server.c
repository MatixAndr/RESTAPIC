#include <microhttpd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8080

struct MHD_Response *create_response(const char *json, int status_code) {
    struct MHD_Response *response = MHD_create_response_from_buffer(strlen(json), (void *)json, MHD_RESPMEM_PERSISTENT);
    return response;
}

int request_handler(void *cls, struct MHD_Connection *connection,
                    const char *url, const char *method,
                    const char *version, const char *upload_data,
                    size_t *upload_data_size, void **con_cls) {
    const char *response_text = "{\"message\": \"Hello, World!\"}";
    struct MHD_Response *response = create_response(response_text, MHD_HTTP_OK);
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int main() {
    struct MHD_Daemon *daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                                                 &request_handler, NULL, MHD_OPTION_END);
    if (NULL == daemon) {
        fprintf(stderr, "Failed to start server\n");
        return 1;
    }
    printf("Server started on port %d\n", PORT);
    getchar();
    MHD_stop_daemon(daemon);
    return 0;
}
