#include "bTree.h"

void Save(T_B_Tree * tree, char * file) {
    if (tree != NULL) {
        FILE * f = fopen(file, "wb");
        if (f == NULL) {
            return;
        }
        fwrite(&(tree->t_size), sizeof(tree->t_size), 1, f);
        SaveSub(tree, f);
        fclose(f);
    }
}

void SaveSub(T_B_Tree * tree, FILE * filedis) {
    fwrite(&(tree->capacity), sizeof(tree->capacity), 1, filedis);
    fwrite(&(tree->list), sizeof(tree->list), 1, filedis);
    for (int i = 0; i < tree->capacity; i++) {
        fwrite(tree->object[i]->key, 257, 1, filedis);
        fwrite(&(tree->object[i]->value), sizeof(tree->object[i]->value), 1, filedis);
    }
    if (tree->list == 0) {
        for (int i = 0; i < tree->capacity + 1; i++) {
            SaveSub(tree->ptr[i], filedis);
        }
    }
}

T_B_Tree * Load(char * file) {
    FILE * f = fopen(file, "rb");
    if (f == NULL) {
        return NULL;
    }
    int t_s;
    fread(&(t_s), sizeof(t_s), 1, f);
    T_B_Tree * tree = CreateBTree(t_s);
    int size, list;
    fread(&(size), sizeof(size), 1, f);
    fread(&(list), sizeof(list), 1, f);
    LoadSub(tree, f, size, list);
    fclose(f);
    return tree;
}

void LoadSub(T_B_Tree * tree, FILE * f, int size, int list) {
    tree->capacity = size;
    tree->list = list;
    for (int i = 0; i < size; i++) {
        fread(tree->object[i]->key, 257, 1, f);
        fread(&(tree->object[i]->value), sizeof(tree->object[i]->value), 1, f);
    }
    if (list == 0) {
        int size_, list_;
        for (int i = 0; i < size + 1; i++) {
            fread(&(size_), sizeof(size_), 1, f);
            fread(&(list_), sizeof(list_), 1, f);
            tree->ptr[i] = CreateBTree(tree->t_size);
            tree->ptr[i]->parent = tree;
            LoadSub(tree->ptr[i], f, size_, list_);
        }
    }
}
