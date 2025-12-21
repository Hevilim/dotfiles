#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080


int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024] = 0;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct socketaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd)
        exit(EXIT_FAILURE)
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        close(server_fd)
        exit(EXIT_FAILURE)
    }

    printf("Server is running on htpp://localhost:%d/\n", PORT);

    client_fd = accept(server_fd, NULL, NULL);
    


    return 0;
}