// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// prime.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>

#define SIZE 10

// int pow(int a, int b) {
//   res = 1;
//   for (size_t i = 0; i < b; i++) {
//     res = res * a;
//   }
//   return res;
// }

#include "stringW.h"

int main(int argc, char ** argv) {
    pid_t pid;
    int file = charToInt(argv[1]),
        target = charToInt(argv[2]),
        p = charToInt(argv[3]), s, fd[2];
    char mess[SIZE], * m = NULL;

    if (target < pow(p, 2)) {
        m = "1";
        write(file, m, strlen(m) + 1);
        exit(0);
    }
    if (target % p == 0) {
        m = "0";
        write(file, m, strlen(m) + 1);
        exit(0);
    }

    if (pipe(fd) == -1) {
        perror("prime pipe");
        m = "error";
        write(file, m, strlen(m) + 1);
        exit(1);
    }

    switch (pid = fork()) {
        case -1:
            perror("prime fork");
            m = "error";
            write(file, m, strlen(m) + 1);
            exit(1);
            break;
        case 0:
            execl("prime", " ", intToChar(fd[1]), argv[2], intToChar(p + 1), NULL);
            break;
        default:
            while ((s = read(fd[0], mess, SIZE)) > 0) {
                if (isNumber(mess)) {
                    write(file, mess, strlen(mess) + 1);
                    exit(0);
                } else if (strcmp(mess, "error") == 0) {
                    perror("prime dumb");
                    write(file, mess, strlen(mess) + 1);
                    exit(1);
                }
            }
            break;
    }
    return 0;
}
