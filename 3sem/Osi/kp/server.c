#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

/*
200 OK
Standard response for successful HTTP requests.
The actual response will depend on the request method used.
In a GET request, the response will contain an entity corresponding to the requested resource.
In a POST request, the response will contain an entity describing or containing the result of the action.

400 Bad Request
The server cannot or will not process the request due to an apparent client error
(e.g., malformed request syntax, size too large, invalid request message framing,
or deceptive request routing).

404 Not Found
The requested resource could not be found but may be available in the future.
Subsequent requests by the client are permissible.
*/

void make_responde(char * buffer, long size, int socket);

int PORT;
char * PATH;

int main(int argc, char const *argv[])
{
    PATH = malloc(1000);
    if (argc == 3) {
        PORT = atoi(argv[1]);
        strcpy(PATH, argv[2]);
    } else if (argc == 1 || argc == 2) {
        PORT = 8080;
        strcpy(PATH, "");
    } else {
        printf("error : port + local path\n");
        return 1;
    }


    printf("work on port %d and path %s\n", PORT, PATH);

    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // char * hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n";
    // char * context = "\nHello world!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT); /*В архитектуре i80x86 узловой
    порядок расположения байтов - это такой порядок, при котором
    последний значимый байт стоит в начале числа, а при сетевом
    порядке расположения байтов, используемом в интернет, наоборот:
    первый значимый байт стоит в начале числа. #include <netinet/in.h>*/

    memset(address.sin_zero, '\0', sizeof address.sin_zero); /*Функция memset заполняет первые n
    байт области памяти, на которую указывает аргумент destination, символом,
    код которого указывается аргументом c.*/

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0) /*второй параметр - число поддерживаемых пользователей*/
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*) &addrlen)) < 0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        valread = read(new_socket , buffer, 30000);
        printf("%s\n", buffer);

        make_responde(buffer, valread, new_socket);

        /*разбор request сообщения поиск в нем слов контекста типа html и других.
        далее будем формировать ответ согласно сообщению и результату.*/

        printf("------------------Hello message sent-------------------\n");
        close(new_socket);
    }
    return 0;
}


void make_responde(char buffer[30000], long size, int socket) {
    char * file_name = (char *)malloc(20);
    memset(file_name, '\0', 20);
    int file_size = 0;
    int i = 5;
    while (buffer[i] != ' ') {
        if (i >= 20) {
            char * mess = "HTTP/1.1 400 Bad Request";
            write(socket , mess , strlen(mess));
            return;
        }
        file_name[i - 5] = buffer[i];
        file_size++;
        i++;
    }
    char * path = malloc(100);
    memset(path, '\0', 100);
    int glob_size = 0;
    for (size_t i = 0; i < strlen(PATH); i++) path[glob_size++] = PATH[i];
    for (size_t i = 0; i < strlen(file_name); i++) path[glob_size++] = file_name[i];
    printf("file : %s\n", path);
    FILE * file = fopen(path, "r");
    if (file == NULL) {
        printf("not found\n");
        char * mess = "HTTP/1.1 404 Not Found";
        write(socket , mess , strlen(mess));
        return;
    }
    char content[30000] = {0};
    int content_size = fread(content, 30000, 1, file);
    content_size = strlen(content);
    char * mess1 = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=utf-8\nContent-Length: ";
    char mess[30000] = {0};
    int var_glob = 0;
    for (size_t i = 0; i < strlen(mess1); i++)  mess[var_glob++] = mess1[i];
    char aaa[10];
    sprintf(aaa, "%d", content_size);
    for (size_t i = 0; i < strlen(aaa); i++)    mess[var_glob++] = aaa[i];
    mess1 = "\n\n";
    for (size_t i = 0; i < strlen(mess1); i++)  mess[var_glob++] = mess1[i];
    for (size_t i = 0; i < strlen(content); i++)mess[var_glob++] = content[i];
    write(socket , mess , strlen(mess));
    fclose(file);
    free(file_name);
    free(path);
}
