#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

//structure
typedef struct Node {
    Tree * tree;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct List {
  Node * head;
  Node * tail;
  int size;
} List;

//functions
List * createList();
char * popList(List * list);
void pushList(List * list, char * input);
char * shiftList(List * list);
void unshiftList(List * list, char * input);
void printList(List * list);
int notEmpty(List * list);
void deleteList(List ** list);
Tree * deleteNode(List * list, Node * node);
Tree * createOperandTree(List ** list);
void pushListTree(List * list, Tree * tree);

#endif
