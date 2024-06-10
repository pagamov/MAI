// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// alt.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 10

#include "stringW.h"

int main(int argc, char ** argv) {
    if (argc != 3) {
        perror("alt no discriptor");
        exit(1);
    }
    int fd1[2], fd2[2], s;
    char mess[SIZE], * m;
    pid_t pid;
    fd1[0] = charToInt(argv[1]);
    fd1[1] = charToInt(argv[2]);
    while ((s = read(fd1[0], mess, SIZE)) > 0) {
        if (isNumber(mess) && charToInt(mess) >= 0) {
            if (pipe(fd2) == -1) {
                perror("alt pipe");
                m = "abort";
                write(fd1[1], m, strlen(m) + 1);
                exit(2);
            }
            switch (pid = fork()) {
                case -1:
                    perror("alt pipe");
                    m = "abort";
                    write(fd1[1], m, strlen(m) + 1);
                    exit(2);
                    break;
                case 0:
                    execl("prime", " ", intToChar(fd2[1]), mess, intToChar(2), NULL);
                    break;
                default:
                    while ((s = read(fd2[0], mess, SIZE)) > 0) {
                        if (isNumber(mess)) {
                            write(fd1[1], mess, strlen(mess) + 1);
                        } else {
                            printf("rel : we lost our prime\n");
                            m = "error";
                            write(fd1[1], m, strlen(m) + 1);
                        }
                        break;
                    }
                    break;
            }
        } else if (strcmp(mess, "exit") == 0) {
            exit(0);
        } else {
            m = "repeat";
            write(fd1[1], m, strlen(m) + 1);
        }
    }
    return 0;
}
