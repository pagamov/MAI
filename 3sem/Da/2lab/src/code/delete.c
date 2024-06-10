#include "bTree.h"

void DeleteFromBTree(T_B_Tree * tree, char * key) {
    T_B_Tree * ptr = FindNode(tree, key);
    if (ptr->list) {
        if (ptr->capacity < tree->t_size - 1 && ptr->capacity > 0) {
            Erase(ptr, key);
            return;
        }
        if (ptr->capacity > tree->t_size - 1) {
            Erase(ptr, key);
        } else if (ptr->capacity == tree->t_size - 1) {
            EasyCase(ptr, key);
        }
    } else {
        BadCase(ptr, key);
    }
}

T_B_Tree * FindNode(T_B_Tree * tree, char * key) {
    int pos = BinarySearch(tree, key);
    if (pos < 0) {
        return tree;
    } else {
        return FindNode(tree->ptr[pos], key);
    }
}

void Erase(T_B_Tree * tree, char * key) {
    int pos = BinarySearch(tree, key);
    int i = -(pos + 1);
    for (int j = i ; j < tree->capacity - 1; j++) {
        Swup(tree, j, j + 1);
    }
    tree->capacity--;
}

T_B_Tree * FindLeft(T_B_Tree * tree, T_B_Tree * tar) {
    int i = 0;
    while (i < tree->capacity + 1) {
        if (tree->ptr[i] == tar) {
            return i != 0 ? tree->ptr[i - 1] : NULL;
        }
        i++;
    }
    return NULL;
}

T_B_Tree * FindRight(T_B_Tree * tree, T_B_Tree * tar) {
    int i = 0;
    while (i < tree->capacity + 1) {
        if (tree->ptr[i] == tar) {
            return i != tree->capacity ? tree->ptr[i + 1] : NULL;
        }
        i++;
    }
    return NULL;
}

int FindDiv(T_B_Tree * parent, T_B_Tree * tar1, T_B_Tree * tar2) {
    for (int i = 0; i < parent->capacity; i++) {
        if (parent->ptr[i] == tar1 && parent->ptr[i + 1] == tar2) {
            return i;
        }
    }
    return -1;
}

void EasyCase(T_B_Tree * tree, char * key) {
    if (tree->parent == NULL) {
        Erase(tree, key);
    } else {
        T_B_Tree * l = FindLeft(tree->parent, tree);
        T_B_Tree * r = FindRight(tree->parent, tree);
        int l_div = FindDiv(tree->parent, l, tree);
        int r_div = FindDiv(tree->parent, tree, r);
        if (r != NULL) {
            if (r->capacity > tree->t_size - 1) {
                Erase(tree, key);
                InsertBTree(tree, tree->parent->object[r_div]->key, tree->parent->object[r_div]->value, NULL, NULL);
                strcpy(tree->parent->object[r_div]->key, r->object[0]->key);
                tree->parent->object[r_div]->value = r->object[0]->value;
                Erase(r, tree->parent->object[r_div]->key);
                return;
            }
        }
        if (l != NULL) {
            if (l->capacity > tree->t_size - 1) {
                Erase(tree, key);
                InsertBTree(tree, tree->parent->object[l_div]->key, tree->parent->object[l_div]->value, NULL, NULL);
                strcpy(tree->parent->object[l_div]->key, l->object[l->capacity - 1]->key);
                tree->parent->object[l_div]->value = l->object[l->capacity - 1]->value;
                Erase(l, l->object[l->capacity - 1]->key);
                return;
            }
        }
        if (r != NULL) {
            if (r->capacity == tree->t_size - 1) {
                if (tree->parent->capacity <= tree->t_size - 1) {
                    Merge(tree->parent);
                }
                r = FindRight(tree->parent, tree);
                r_div = FindDiv(tree->parent, tree, r);
                Erase(tree, key);
                InsertBTree(tree, tree->parent->object[r_div]->key, tree->parent->object[r_div]->value, NULL, NULL);
                for (int i = 0; i < r->capacity; i++) {
                    InsertBTree(tree, r->object[i]->key, r->object[i]->value, r->ptr[i], r->ptr[i + 1]);
                }
                r->capacity = 0;
                Erase(tree->parent, tree->parent->object[r_div]->key);
                tree->parent->ptr[r_div] = tree;
                Clear(r);
                free(r);
                return;
            }
        }
        if (l != NULL) {
            if (l->capacity == tree->t_size - 1) {
                if (tree->parent->capacity <= tree->t_size - 1) {
                    Merge(tree->parent);
                }
                l = FindLeft(tree->parent, tree);
                l_div = FindDiv(tree->parent, l, tree);
                Erase(tree, key);
                InsertBTree(l, tree->parent->object[l_div]->key, tree->parent->object[l_div]->value, NULL, NULL);
                for (int i = 0; i < tree->capacity; i++)
                    InsertBTree(l, tree->object[i]->key, tree->object[i]->value, tree->ptr[i], tree->ptr[i + 1]);
                tree->capacity = 0;
                for (int i = 0; i < l->capacity; i++)
                    InsertBTreeforce(tree, l->object[i]->key, l->object[i]->value, l->ptr[i], l->ptr[i + 1]);
                l->capacity = 0;
                Erase(tree->parent, tree->parent->object[l_div]->key);
                tree->parent->ptr[l_div] = tree;
                Clear(l);
                free(l);
                return;
            }
        }
    }
    return;
}

void BadCase(T_B_Tree * tree, char * key) {
    T_B_Tree * pivl = NULL;
    T_B_Tree * pivr = NULL;

    int pos = BinarySearch(tree, key);
    int i = -(pos + 1);

    if (tree->ptr[i]->capacity > tree->t_size - 1) {
        pivl = tree->ptr[i];
        pivr = tree->ptr[i + 1];
        InsertBTree(pivr, tree->object[i]->key, tree->object[i]->value, pivl->ptr[pivl->capacity], NULL);
        if (pivl->ptr[pivl->capacity] != NULL) {
            pivl->ptr[pivl->capacity]->parent = pivr;
        }
        strcpy(tree->object[i]->key, pivl->object[pivl->capacity - 1]->key);
        tree->object[i]->value = pivl->object[pivl->capacity - 1]->value;
        Erase(pivl, tree->object[i]->key);
        DeleteFromBTree(pivr, pivr->object[0]->key);
        if (pivr->capacity == 2 * tree->t_size - 1) {
            DivideBTree(pivr);
        }
        return;
    }

    if (tree->ptr[i + 1]->capacity > tree->t_size - 1) {
        pivl = tree->ptr[i];
        pivr = tree->ptr[i + 1];
        InsertBTree(pivl, tree->object[i]->key, tree->object[i]->value, NULL, pivr->ptr[0]);
        if (pivr->ptr[0] != NULL) {
            pivr->ptr[0]->parent = pivl;
        }
        strcpy(tree->object[i]->key, pivr->object[0]->key);
        tree->object[i]->value = pivr->object[0]->value;
        Erase(pivr, tree->object[i]->key);
        DeleteFromBTree(pivl, pivl->object[pivl->capacity - 1]->key);
        if (pivl->capacity == 2 * tree->t_size - 1) {
            DivideBTree(pivl);
        }
        return;
    }

    if (tree->ptr[i]->capacity == tree->t_size - 1 && tree->ptr[i + 1]->capacity == tree->t_size - 1) {
        if (tree->capacity <= tree->t_size - 1) {
            Merge(tree);
        }
        int pos2 = BinarySearch(tree, key);
        i = -(pos2 + 1);
        pivl = tree->ptr[i];
        pivr = tree->ptr[i + 1];
        InsertBTree(pivl, tree->object[i]->key, tree->object[i]->value, NULL, NULL);
        for (int j = 0; j < pivr->capacity + 1; j++) {
            if (pivr->ptr[i] != NULL) {
                pivr->ptr[i]->parent = pivl;
            }
        }
        for (int j = 0; j < pivr->capacity; j++) {
            InsertBTreeforce(pivl, pivr->object[j]->key, pivr->object[j]->value, pivr->ptr[j], pivr->ptr[j + 1]);
        }
        Clear(pivr);
        free(pivr);
        Erase(tree, tree->object[i]->key);
        tree->ptr[i] = pivl;
        DeleteFromBTree(pivl, pivl->object[tree->t_size - 1]->key);
        if (pivl->capacity == 2 * tree->t_size - 1) {
            DivideBTree(pivl);
        }
        return;
    }
    return;
}
