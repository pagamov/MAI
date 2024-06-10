#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct T_Node {
    char * key;
    unsigned long long value;
} T_Node;

typedef struct T_B_Tree {
    int t_size;
    int list;
    struct T_B_Tree * parent;
    int capacity;
    struct T_Node ** object;
    struct T_B_Tree ** ptr;
} T_B_Tree;


// clear.c
void DeletebTree(T_B_Tree ** tree);
void DeleteSubbTree(T_B_Tree * tree);
void Clear(T_B_Tree * tree);

// delete.c
void Merge(T_B_Tree * tree);
void DeleteFromBTree(T_B_Tree * tree, char * key);
T_B_Tree * FindNode(T_B_Tree * tree, char * key);
void Erase(T_B_Tree * tree, char * key);
T_B_Tree * FindLeft(T_B_Tree * tree, T_B_Tree * tar);
T_B_Tree * FindRight(T_B_Tree * tree, T_B_Tree * tar);
int FindDiv(T_B_Tree * parent, T_B_Tree * tar1, T_B_Tree * tar2);
void EasyCase(T_B_Tree * tree, char * key);
void BadCase(T_B_Tree * tree, char * key);

// insert.c
int InsertBTree(T_B_Tree * tree, char * key, unsigned long long value, T_B_Tree * left, T_B_Tree * right);
void InsertBTreeforce(T_B_Tree * tree, char * key, unsigned long long value, T_B_Tree * left, T_B_Tree * right);
int DivideBTree(T_B_Tree * tree);
int AddBTree(T_B_Tree * tree, char * key, unsigned long long value, T_B_Tree * left, T_B_Tree * right);

// m.c
char Toolover(char a);
void RegDown(char * str);
int StrcmpReg(char * str1, char * str2);
int BinarySearch(T_B_Tree * tree, char * key);
T_B_Tree * CreateBTree(int t_s);
int InBTree(T_B_Tree * tree, char * key);
T_Node * FindSpot(T_B_Tree * tree, char * key);
T_B_Tree * RestrictBTree(T_B_Tree * tree);
void Swap(T_B_Tree * tree, int a, int b);
void Swup(T_B_Tree * tree, int a, int b);

// merge.c
void Merge(T_B_Tree * tree);

// saveload.c
void Save(T_B_Tree * tree, char * file);
void SaveSub(T_B_Tree * tree, FILE * f);
T_B_Tree * Load(char * file);
void LoadSub(T_B_Tree * tree, FILE * f, int size, int list);

#endif
