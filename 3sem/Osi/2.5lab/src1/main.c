// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define SIZE 100

#include "stringW.h"

int main(int argc, char ** argv) {
    printf("c - start server\nb - stop server\np - check sentence\ne - exit\n");

    int cr = 0, piv, fd1[2], fd2[2];
    char call, mess[SIZE], * m;
    m = (char *)malloc(sizeof(char) * SIZE);
    pid_t pid;
    while (1) {
        call = getchar();
        switch (call) {
            case 'p':
                if (cr != 0) {
                    scanf("%s", m);
                    printf("UI : %s\n", m);
                    write(fd1[1], m, strlen(m) + 1);
                    while ((piv = read(fd2[0], m, SIZE)) > 0) {
                        if (strcmp(m, "error\0") == 0) {
                            printf("UI : server : %s\n", m);
                            break;
                        } else if (strcmp(m, "end\0") == 0) {
                            printf("UI : end of tree\n");
                            break;
                        } else if (strcmp(m, "endl\0") == 0) {
                            printf("\n");
                        } else {
                            printf("%s", m);
                        }
                    }
                } else {
                    printf("UI : need to create server\n");
                }
                break;
            case 'c':
                if (cr == 0) {
                    if (pipe(fd1) == -1) {
                        perror("main pipe");
                        exit(-1);
                    }
                    if (pipe(fd2) == -1) {
                        perror("main pipe");
                        exit(-1);
                    }
                    switch (pid = fork()) {
                        case -1:
                            perror("main fork");
                            exit(1);
                            break;
                        case 0:
                            execl("server", " ", intToChar(fd1[0]), intToChar(fd2[1]), NULL);
                            break;
                        default:
                            while ((piv = read(fd2[0], mess, SIZE)) > 0) {
                                if (strcmp(mess, "started\0") == 0) {
                                    printf("UI : server started\n");
                                    cr = 1;
                                } else {
                                    printf("UI : server error\n");
                                }
                                break;
                            }
                            break;
                    }
                } else {
                    printf("UI : server is already running\n");
                }
                break;
            case 'b':
                strcpy(m, "exit\0");
                write(fd1[1], m, strlen(m) + 1);
                printf("UI : server shout down\n");
                cr = 0;
                break;
            case 'e':
                if (cr != 0) {
                    strcpy(m, "exit\0");
                    write(fd1[1], m, strlen(m) + 1);
                }
                free(m);
                printf("Exit...\n");
                return 0;
            default:
                break;
        }
    }
}
