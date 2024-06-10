#include "bTree.h"

int InsertBTree(T_B_Tree * tree, char * key, unsigned long long value, T_B_Tree * left, T_B_Tree * right) {
    int i = 0;
    if (tree->capacity == 0) {
        strcpy(tree->object[i]->key, key);
        tree->object[i]->value = value;
        tree->ptr[i] = left;
        tree->ptr[i + 1] = right;
        tree->capacity++;
        return i;
    }
    for (i = 0; i < tree->capacity; i++) {
        if (StrcmpReg(key, tree->object[i]->key) == 1) {
            for (int j = tree->capacity; j != i; j--)
                Swap(tree, j - 1, j);
            strcpy(tree->object[i]->key, key);
            tree->object[i]->value = value;
            tree->ptr[i] = left;
            tree->capacity++;
            return i;
        }
    }
    strcpy(tree->object[i]->key, key);
    tree->object[i]->value = value;
    tree->ptr[i + 1] = right;
    tree->capacity++;
    return i;
}

void InsertBTreeforce(T_B_Tree * tree, char * key, unsigned long long value, T_B_Tree * left, T_B_Tree * right) {
    int pos = InsertBTree(tree, key, value, left, right);
    tree->ptr[pos] = left;
    tree->ptr[pos + 1] = right;
}

int DivideBTree(T_B_Tree * tree) {
    T_B_Tree * nleft = CreateBTree(tree->t_size);
    if (tree->list == 0) {
        nleft->list = 0;
    }
    for (int i = tree->t_size; i < 2 * tree->t_size - 1; i++) {
        InsertBTree(nleft, tree->object[i]->key, tree->object[i]->value, tree->ptr[i], tree->ptr[i + 1]);
        if (tree->ptr[i] != NULL) {
            tree->ptr[i]->parent = nleft;
        }
        if (tree->ptr[i + 1] != NULL) {
            tree->ptr[i + 1]->parent = nleft;
        }
        tree->capacity--;
    }
    if (tree->parent == NULL) {
        T_B_Tree * nroot = CreateBTree(tree->t_size);
        nroot->list = 0;
        tree->parent = nroot;
    }
    nleft->parent = tree->parent;
    InsertBTreeforce(tree->parent, tree->object[tree->t_size - 1]->key, tree->object[tree->t_size - 1]->value, tree, nleft);
    tree->capacity--;
    if (tree->parent->capacity == 2 * tree->t_size - 1) {
        DivideBTree(tree->parent);
    }
    return 1;
}

int AddBTree(T_B_Tree * tree, char * key, unsigned long long value, T_B_Tree * left, T_B_Tree * right) {
    if (tree != NULL) {
        if (tree->list) {
            InsertBTree(tree, key, value, left, right);
            if (tree->capacity == 2 * tree->t_size - 1) {
                DivideBTree(tree);
            }
            return 1;
        } else {
            int pos = BinarySearch(tree, key);
            return AddBTree(tree->ptr[pos], key, value, left, right);
        }
    }
    return 0;
}
