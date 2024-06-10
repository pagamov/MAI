// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <string.h>

#define SIZE 10

#include "stringW.h"

int main(int argc, char ** argv) {
    printf("c - start alt\nb - stop alt\np - check number\ne - exit\n");
    int target, cr = 0, piv, fd1[2], fd2[2];
    char call, mess[32], * m;
    pid_t pid;
    while (1) {
        call = getchar();
        switch (call) {
            case 'p':
                if (cr != 0) {
                    scanf("%d", &target);
                    m = intToChar(target);
                    write(fd1[1], m, strlen(m) + 1);
                    while ((piv = read(fd2[0], mess, SIZE)) > 0) {
                        if (isNumber(mess)) {
                            if (mess[0] == '1')
                                printf("number %d is prime\n", target);
                            else
                                printf("number %d is not prime\n", target);
                        } else if (strcmp(mess, "error") == 0) {
                            printf("Error in system\nTry later\n");
                        } else if (strcmp(mess, "abort") == 0) {
                            printf("We lost our rel\n");
                            cr = 0;
                        } else if (strcmp(mess, "repeat") == 0) {
                            printf("wrong number\n");
                        }
                        break;
                    }
                } else {
                    printf("Need to create proc\n");
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
                            execl("alt", " ", intToChar(fd1[0]), intToChar(fd2[1]), NULL);
                            break;
                        default:
                            printf("Alt started\n");
                            break;
                    }
                    cr = 1;
                } else {
                    printf("Alt already running\n");
                }
                break;
            case 'b':
                m = "exit";
                write(fd1[1], m, strlen(m) + 1);
                printf("Alt shout down\n");
                cr = 0;
                break;
            case 'e':
                if (cr != 0) {
                    m = "exit";
                    write(fd1[1], m, strlen(m) + 1);
                }
                if (m != NULL) {
                    m = NULL;
                }
                printf("Exit...\n");
                return 0;
            default:
                break;
        }
    }
}
