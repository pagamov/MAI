#include <stdlib.h>
#include <stdio.h>
#include "bTree.h"

int main(int argc, char ** argv) {
    int glob_size = 30;
    char * input = (char *)calloc(257, sizeof(char));
    unsigned long long number;
    T_B_Tree * tree = CreateBTree(glob_size);
    T_B_Tree * ret = NULL;
    while (scanf("%s", input) > 0) {
        if (strcmp(input, "+\0") == 0) {
            scanf("%s\t%llu", input, &number);
            RegDown(input);
            switch (InBTree(tree, input)) {
                case 1:
                    printf("Exist\n");
                    break;
                case 0:
                    switch (AddBTree(tree, input, number, NULL, NULL)) {
                        case 1:
                            tree = RestrictBTree(tree);
                            printf("OK\n");
                            break;
                        case 0:
                            printf("ERROR: in adding\n");
                            exit(1);
                            break;
                    }
                    break;
            }
        } else if (strcmp(input, "-\0") == 0) {
            scanf("%s", input);
            RegDown(input);
            if (InBTree(tree, input)) {
                DeleteFromBTree(tree, input);
                tree = RestrictBTree(tree);
                printf("OK\n");
            } else {
                printf("NoSuchWord\n");
            }
        } else if (strcmp(input, "!\0") == 0) {
            scanf("%s", input);
            if (strcmp(input, "Save\0") == 0) {
                scanf("%s", input);
                Save(tree, input);
                printf("OK\n");
            } else if (strcmp(input, "Load\0") == 0) {
                scanf("%s", input);
                ret = Load(input);
                if (ret != NULL) {
                    DeletebTree(&tree);
                    tree = NULL;
                    tree = ret;
                    ret = NULL;
                    printf("OK\n");
                } else {
                    printf("ERROR: in Load\n"); //
                }
            }
        } else {
            RegDown(input);
            T_Node * pivet = FindSpot(tree, input);
            if (pivet == NULL) {
                printf("NoSuchWord\n");
            } else {
                printf("OK:\t%llu\n", pivet->value);
            }
        }
    }
    DeletebTree(&tree);
    free(input);
    return 0;
}
