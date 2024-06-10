#include "bTree.h"

void Clear(T_B_Tree * tree) {
    for (int i = 0; i < 2 * tree->t_size; i++) {
        free(tree->object[i]->key);
        free(tree->object[i]);
    }
    free((tree)->object);
    free((tree)->ptr);
}

void DeleteSubbTree(T_B_Tree * tree) {
    if (tree != NULL) {
        for (int i = 0; i < tree->capacity + 1; i++) {
            DeleteSubbTree(tree->ptr[i]);
            tree->ptr[i] = NULL;
        }
        Clear(tree);
        free(tree);
    }
}

void DeletebTree(T_B_Tree ** tree) {
    if ((*tree) != NULL) {
        for (int i = 0; i < (*tree)->capacity + 1; i++) {
            DeleteSubbTree((*tree)->ptr[i]);
            (*tree)->ptr[i] = NULL;
        }
        Clear(*tree);
        free(*tree);
        *tree = NULL;
    }
}
