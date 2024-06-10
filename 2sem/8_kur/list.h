#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

//structure
typedef struct Node {
    int value;
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
int popList(List * list);
void pushList(List * list, int number);
int shiftList(List * list);
void unshiftList(List * list, int number);
void sliceList(List * list, int start, int count);
void printList(List * list);
void insertList(List * list, int position, int value);
void reverseList(List * list);
int indexList(List * list, int target);
void removeList(List * list, int target);
int sizeList(List * list);
int isNullList(List * list);
int countList(List * list, int target);
void clearList(List * list);
void deleteList(List ** list);
//
void unconventionalList(List * list, int position, int value, int count);

#endif
