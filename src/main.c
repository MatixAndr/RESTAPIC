//
// Created by MateuszAndruszkiewic on 3.12.2024.
//
#include <winsock2.h>
#include <stdio.h>
#include "routes.h"

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;
    char client_message[MAX_REQUEST_LENGTH];

    // Initialize Winsock
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
    }

    printf("Socket created.\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d", WSAGetLastError());
        return 1;
    }

    puts("Bind done");

    // Listen to incoming connections
    listen(server_socket, 3);

    // Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    while ((client_socket = accept(server_socket, (struct sockaddr*)&client, &c)) != INVALID_SOCKET) {
        puts("Connection accepted");

        // Receive a message from client
        int read_size;
        while ((read_size = recv(client_socket, client_message, MAX_REQUEST_LENGTH, 0)) > 0) {
            client_message[read_size] = '\0';
            handle_request(client_message, client_socket);
        }

        if (read_size == 0) {
            puts("Client disconnected");
        } else if (read_size == -1) {
            printf("recv failed with error code : %d", WSAGetLastError());
        }
    }

    if (client_socket == INVALID_SOCKET) {
        printf("accept failed with error code : %d", WSAGetLastError());
        return 1;
    }

    closesocket(server_socket);
    WSACleanup();

    return 0;
}
