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

#define true 1
#define EXIT -2
#define STACK_SIZE 3
#define ALIVE -4
#define DEAD -5
#define PRIME -10
#define NOT_PRIME -24
#define ERROR -30
#define WAIT -45
#define ok 0
#define error 1

int pow_2(int a) { return a*a; }

typedef struct {
    int number;
    int stack[STACK_SIZE];
    pthread_mutex_t mutex_1;
    pthread_mutex_t mutex_2;
} shared_data;

static shared_data * data = NULL;

void create_shared_data() {
    int prot = PROT_READ | PROT_WRITE;
    int flags = MAP_SHARED | MAP_ANONYMOUS;
    // int flags = MAP_SHARED;
    data = (shared_data*)mmap(NULL, sizeof(shared_data), prot, flags, -1, 0);
    if (data == MAP_FAILED) {
        exit(-3);
    }
    for (size_t i = 0; i < STACK_SIZE; i++)
        data->stack[i] = 0;

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&data->mutex_1, &attr);

    pthread_mutexattr_t attr_permission;
    pthread_mutexattr_init(&attr_permission);
    pthread_mutexattr_setpshared(&attr_permission, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&data->mutex_2, &attr_permission);
}

int run_prime() {
    if (data->number <= 0) {
        data->stack[1] = ERROR;
        exit(error);
    }
    if (data->number < pow_2(data->stack[2])) {
        data->stack[1] = PRIME;
        exit(ok);
    }
    if (data->number % data->stack[2] == 0) {
        data->stack[1] = NOT_PRIME;
        exit(ok);
    }
    data->stack[2] += 1;
    pid_t pid;
    switch (pid = fork()) {
        case -1:
            printf("alt : cannot create server procces\n");
            data->stack[1] = ERROR;
            exit(error);
            break;
        case 0:
            run_prime();
            break;
        default:
            wait(NULL);
            exit(ok);
    }
    return 0;
}

int run_alt() {
    while (true) {
        pthread_mutex_lock(&data->mutex_2);
        if (data->stack[1] == EXIT) {
            printf("alt : exit\n");
            pthread_mutex_unlock(&data->mutex_1);
            exit(ok);
        }
        data->stack[2] = 2;
        pid_t pid;
        switch (pid = fork()) {
            case -1:
                printf("alt : cannot create server procces\n");
                break;
            case 0:
                run_prime();
                break;
            default:
                wait(NULL);
        }
        pthread_mutex_unlock(&data->mutex_1);
    }
}

int run_main() {
    printf("p - check number\ne - exit\n");
    char call;
    while (true) {
        pthread_mutex_lock(&data->mutex_1);
        switch (data->stack[1]) {
            case ERROR:
                printf("main : some errors\n");
                break;
            case PRIME:
                printf("main : %d : is prime\n", data->number);
                data->number = 0;
                break;
            case NOT_PRIME:
                printf("main : %d : is not prime\n", data->number);
                data->number = 0;
                break;
        }
        data->stack[1] = WAIT;
        //
        while(true) {
            call = getchar();
            if (call == '\n')
                break;
            switch (call) {
                case 'p':
                    scanf("%d", &(data->number));
                    break;
                case 'e':
                    data->stack[1] = EXIT;
                    pthread_mutex_unlock(&data->mutex_2);
                    // wait(NULL);
                    printf("main : exit\n");
                    return ok;
            }
        }
        pthread_mutex_unlock(&data->mutex_2);
    }
}

int main(int argc, char ** argv) {
    create_shared_data();
    pid_t serverPid = fork();
    switch (serverPid) {
        case -1:
            printf("Cannot create server procces\n");
            exit(error);
        case 0:
            printf("Create server procces\n");
            // data->stack[0] = ALIVE;
            run_alt();
            break;
        default:
            pthread_mutex_lock(&data->mutex_2);
            run_main();
    }
    munmap(data, sizeof(data));
    return 0;
}
