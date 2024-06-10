#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

//struct
typedef struct Tree {
  int value;
  struct Tree * son;
  struct Tree * brother;
} Tree;


//functions
Tree * createTree();
void printTree(Tree * tree);
int addNode(Tree ** root);
int delNode(Tree ** tree);
void deleteTree(Tree ** tree);
//
int neterTree(Tree * tree);

#endif
