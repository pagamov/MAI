#include "bTree.h"

void Merge(T_B_Tree * tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->parent == NULL) {
        return;
    }
    T_B_Tree * l = FindLeft(tree->parent, tree);
    T_B_Tree * r = FindRight(tree->parent, tree);
    int l_div = FindDiv(tree->parent, l, tree);
    int r_div = FindDiv(tree->parent, tree, r);

    if (r != NULL) {
        if (r->capacity > tree->t_size - 1) {
            InsertBTree(tree, tree->parent->object[r_div]->key, tree->parent->object[r_div]->value, NULL, r->ptr[0]);
            r->ptr[0]->parent = tree;
            strcpy(tree->parent->object[r_div]->key, r->object[0]->key);
            tree->parent->object[r_div]->value = r->object[0]->value;
            Erase(r, tree->parent->object[r_div]->key);
            return;
        }
    }

    if (l != NULL) {
        if (l->capacity > tree->t_size - 1) {
            InsertBTree(tree, tree->parent->object[l_div]->key, tree->parent->object[l_div]->value, l->ptr[l->capacity], NULL);
            l->ptr[l->capacity]->parent = tree;
            strcpy(tree->parent->object[l_div]->key, l->object[l->capacity - 1]->key);
            tree->parent->object[l_div]->value = l->object[l->capacity - 1]->value;
            Erase(l, tree->parent->object[l_div]->key);
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
            InsertBTree(tree, tree->parent->object[r_div]->key, tree->parent->object[r_div]->value, NULL, NULL);
            for (int i = 0; i < r->capacity + 1; i++) {
                r->ptr[i]->parent = tree;
            }
            for (int i = 0; i < r->capacity; i++) {
                InsertBTreeforce(tree, r->object[i]->key, r->object[i]->value, r->ptr[i], r->ptr[i + 1]);
            }
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
            InsertBTree(tree, tree->parent->object[l_div]->key, tree->parent->object[l_div]->value, NULL, NULL);
            for (int i = 0; i < l->capacity + 1; i++) {
                l->ptr[i]->parent = tree;
            }
            for (int i = 0; i < l->capacity; i++) {
                InsertBTreeforce(tree, l->object[i]->key, l->object[i]->value, l->ptr[i], l->ptr[i + 1]);
            }
            Erase(tree->parent, tree->parent->object[l_div]->key);
            tree->parent->ptr[l_div] = tree;
            Clear(l);
            free(l);
            return;
        }
    }
}
