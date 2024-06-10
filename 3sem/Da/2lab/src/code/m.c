#include "bTree.h"

char Toolover(char a) {
    return a >= 'A' && a <= 'Z' ? a + ('a' - 'A') : a;
}

void RegDown(char * str) {
    if (str == NULL) {
        return;
    }
    int i = 0;
    while (str[i] != '\0') {
        str[i] = Toolover(str[i]);
        i++;
    }
}

int StrcmpReg(char * str1, char * str2) {
    int a = strcmp(str1, str2);
    if (a > 0) {
        return 1;
    } else if (a < 0) {
        return -1;
    }
    return 0;
}

int BinarySearch(T_B_Tree * tree, char * key) {
    int l = 0;
    int r = tree->capacity - 1;
    if (tree->capacity == 0) {
        return 0;
    }
    if (tree->capacity == 1) {
        int pos = StrcmpReg(tree->object[l]->key, key);
        if (pos == 1) {
            return l + 1;
        } else if (pos == -1) {
            return l;
        } else {
            return -l - 1;
        }
    }
    int mid;
    int res;
    while (l != r - 1) {
        mid = (l + r) / 2;
        res = StrcmpReg(tree->object[mid]->key, key);
        if (res == 1) {
            l = mid;
        } else if (res == -1) {
            r = mid;
        } else if (res == 0) {
            return -mid - 1;
        }
    }
    int lRes = StrcmpReg(tree->object[l]->key, key);
    if (lRes == 0) {
        return -l - 1;
    } else if (lRes == -1) {
        return l;
    }
    int rRes = StrcmpReg(tree->object[r]->key, key);
    if (rRes == 0) {
        return -r - 1;
    } else if (rRes == 1) {
        return r + 1;
    }
    return r;
}

T_B_Tree * CreateBTree(int t_s) {
    T_B_Tree * tree = (T_B_Tree *)calloc(1, sizeof(T_B_Tree));
    tree->t_size = t_s;
    tree->parent = NULL;
    tree->capacity = 0;
    tree->list = 1;
    tree->object = (T_Node **)calloc((2 * tree->t_size), sizeof(T_Node *));
    tree->ptr = (T_B_Tree **)calloc((2 * tree->t_size + 1), sizeof(T_B_Tree *));
    int i;
    for (i = 0; i < (2 * tree->t_size); i++) {
        tree->object[i] = (T_Node *)calloc(1, sizeof(T_Node));
        tree->object[i]->key = (char *)calloc(257, sizeof(char));
        tree->ptr[i] = NULL;
    }
    tree->ptr[i] = NULL;
    return tree;
}

int InBTree(T_B_Tree * tree, char * key) {
    if (tree != NULL) {
        int pos = BinarySearch(tree, key);
        if (pos < 0) {
            return 1;
        } else {
            return InBTree(tree->ptr[pos], key);
        }
    } else {
        return 0;
    }
}

T_Node * FindSpot(T_B_Tree * tree, char * key) {
    if (tree == NULL) {
        return NULL;
    }
    int pos = BinarySearch(tree, key);
    if (pos < 0) {
        return tree->object[-(pos + 1)];
    } else {
        return FindSpot(tree->ptr[pos], key);
    }
}

T_B_Tree * RestrictBTree(T_B_Tree * tree) {
    if (tree->capacity == 0 && tree->ptr[0] != NULL) {
        tree = tree->ptr[0];
        Clear(tree->parent);
        free(tree->parent);
        tree->parent = NULL;
        return RestrictBTree(tree);
    }
    return tree->parent != NULL ? RestrictBTree(tree->parent) : tree;
}

void Swap(T_B_Tree * tree, int a, int b) {
    char * pivc = NULL;
    unsigned long long pivn;
    pivc = tree->object[a]->key;
    pivn = tree->object[a]->value;
    tree->object[a]->key = tree->object[b]->key;
    tree->object[a]->value = tree->object[b]->value;
    tree->object[b]->key = pivc;
    tree->object[b]->value = pivn;
    tree->ptr[b + 1] = tree->ptr[b];
    tree->ptr[a + 1] = tree->ptr[a];
    return;
}

void Swup(T_B_Tree * tree, int a, int b) {
    char * pivc = NULL;
    unsigned long long pivn;
    pivc = tree->object[a]->key;
    pivn = tree->object[a]->value;
    tree->object[a]->key = tree->object[b]->key;
    tree->object[a]->value = tree->object[b]->value;
    tree->object[b]->key = pivc;
    tree->object[b]->value = pivn;
    tree->ptr[a] = tree->ptr[a + 1];
    tree->ptr[b] = tree->ptr[b + 1];
    return;
}
