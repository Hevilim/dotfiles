#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    socklen_t addrlen = sizeof(server_addr);
    char buffer[1024] = {0};

    // Создание сокета
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Настройка адреса
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Слушать на всех IP
    server_addr.sin_port = htons(PORT);

    // Привязка сокета
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Ожидание подключений
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    // Обработка подключений
    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&server_addr, &addrlen);
        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }

        read(client_fd, buffer, sizeof(buffer));
        printf("Request:\n%s\n", buffer);

        const char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 13\r\n"
            "\r\n"
            "Hello world!";

        write(client_fd, response, strlen(response));
        close(client_fd);
    }

    close(server_fd);
    return 0;
}