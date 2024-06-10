// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

#include "queue.h"

#define true 1

void help() {
    printf("push + word - to push\npop - to get elem\nprint - to print que\nexit - to exit prog\n");
    return;
}

Queue * create_Q()
{
	void *dl_handle;
	Queue *(*func)();
	char *error;
	dl_handle = dlopen("libqueue.so", RTLD_LAZY);
	if (!dl_handle) {
		printf("#%s\n", dlerror());
		return NULL;
	}
	func = (Queue* (*)())dlsym(dl_handle, "createQ");
	error = dlerror();
	if (error != NULL) {
		printf("#%s\n", error);
		return NULL;
	}
	Queue * out = func();
	dlclose(dl_handle);
	return out;
}

void push_Q(Queue * queue, char * arg)
{
	void *dl_handle;
	void (*func)(Queue*, char*);
	char *error;
	dl_handle = dlopen("libqueue.so", RTLD_LAZY);
	if (!dl_handle) {
		printf("# %s\n", dlerror());
		return;
	}
	func = (void (*)(Queue*, char*))dlsym(dl_handle, "pushQ");
	error = dlerror();
	if (error != NULL) {
		printf("# %s\n", error);
		return;
	}
	func(queue, arg);
	dlclose(dl_handle);
	return;
}

int pop_Q(Queue * queue, char * arg)
{
	void *dl_handle;
	int (*func)(Queue*, char*);
	char *error;
	dl_handle = dlopen("libqueue.so", RTLD_LAZY);
	if (!dl_handle) {
		printf("# %s\n", dlerror());
		return 0;
	}
	func = (void (*)(Queue*, char*))dlsym(dl_handle, "popQ");
	error = dlerror();
	if (error != NULL) {
		printf("# %s\n", error);
		return 0;
	}
	int res = func(queue, arg);
	dlclose(dl_handle);
	return res;
}

void print_Q(Queue * queue)
{
	void *dl_handle;
	void (*func)(Queue*);
	char *error;
	dl_handle = dlopen("libqueue.so", RTLD_LAZY);
	if (!dl_handle) {
		printf("# %s\n", dlerror());
		return;
	}
	func = (void (*)(Queue*, char*))dlsym(dl_handle, "printQ");
	error = dlerror();
	if (error != NULL) {
		printf("# %s\n", error);
		return;
	}
	func(queue);
	dlclose(dl_handle);
	return;
}

void delete_Q(Queue ** queue)
{
	void *dl_handle;
	void (*func)(Queue**);
	char *error;
	dl_handle = dlopen("libqueue.so", RTLD_LAZY);
	if (!dl_handle) {
		printf("# %s\n", dlerror());
		return;
	}
	func = (void (*)(Queue*, char*))dlsym(dl_handle, "deleteQ");
	error = dlerror();
	if (error != NULL) {
		printf("# %s\n", error);
		return;
	}
	func(queue);
	dlclose(dl_handle);
	return;
}

int main(int argv, char ** argc) {
    char * msg = (char *)malloc(sizeof(char) * 10);
    char * word = (char *)malloc(sizeof(char) * 257);
    Queue * que = create_Q();
    printf("dont forget to 'help' first\n");
    while (true) {
        scanf("%s", msg);
        if (strcmp("push", msg) == 0 || strcmp("pu", msg) == 0) {
            scanf("%s", word);
            push_Q(que, word);
        }  else if (strcmp("pop", msg) == 0 || strcmp("po", msg) == 0) {
            if (pop_Q(que, word)) {
                printf("res : %s\n", word);
            } else {
                printf("no word\n");
            }
        } else if (strcmp("print", msg) == 0 || strcmp("p", msg) == 0) {
            printf("que : \n");
            print_Q(que);
        } else if (strcmp("exit", msg) == 0 || strcmp("e", msg) == 0) {
            break;
        } else if (strcmp("help", msg) == 0 || strcmp("h", msg) == 0) {
            help();
        }
    }
    printf("exit\n");
    delete_Q(&que);
    free(word);
    free(msg);
    return 0;
}
