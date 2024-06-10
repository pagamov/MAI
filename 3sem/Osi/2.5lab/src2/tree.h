#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

//struct
typedef struct Tree {
  char * data;
  int size;
  struct Tree * left;
  struct Tree * right;
} Tree;

//functions
Tree * createTree();
void printTree(Tree * tree, int file);
Tree * createNode(char * data);
void deleteTree(Tree ** tree);
int treeGoDeep(Tree * tree);
Tree * copyTree(Tree * tree);
void reBuildTree(Tree ** tree);
void calculateAsUCan(Tree ** tree);

#endif
