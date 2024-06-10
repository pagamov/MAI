// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <pthread.h>

#include <string.h>

#include "queue.h"

#define true 1

void help() {
    printf("push + word - to push\npop - to get elem\nprint - to print que\nexit - to exit prog\n");
    return;
}

int main(int argv, char ** argc) {
    char * msg = (char *)malloc(sizeof(char) * 10);
    char * word = (char *)malloc(sizeof(char) * 257);
    Queue * que = createQ(); //redo
    printf("dont forget to 'help' first\n");
    while (true) {
        scanf("%s", msg);
        //
        if (strcmp("push", msg) == 0 || strcmp("pu", msg) == 0) {
            scanf("%s", word);
            pushQ(que, word); //redo
        }  else if (strcmp("pop", msg) == 0 || strcmp("po", msg) == 0) {
            if (popQ(que, word)) {
                printf("res : %s\n", word);
            } else {
                printf("no word\n");
            }
        } else if (strcmp("print", msg) == 0 || strcmp("p", msg) == 0) {
            printf("que : \n");
            printQ(que);
        } else if (strcmp("exit", msg) == 0 || strcmp("e", msg) == 0) {
            break;
        } else if (strcmp("help", msg) == 0 || strcmp("h", msg) == 0) {
            help();
        }
    }
    printf("exit\n");
    deleteQ(&que); //redo
    free(word);
    free(msg);
    return 0;
}
