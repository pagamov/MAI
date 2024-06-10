#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


Tree * createTree()
{
  return NULL;
}

Tree * createNode(int value)
{
  Tree * node = (Tree *)malloc(sizeof(Tree));
  node->value = value;
  node->son = NULL;
  node->brother = NULL;
  //
  return node;
}

int moveBrother(Tree * tmp)
{
  if (tmp->son->brother != NULL)
    tmp->son = tmp->son->brother;
  else
    return 1;
  return 0;
}

int moveSon(Tree * tmp)
{
  if (tmp->son->son != NULL)
    tmp->son = tmp->son->son;
  else
    return 1;
  return 0;
}

Tree ** findTreeVal(Tree ** tree, int target)
{
  Tree ** path;
	if ((*tree)->value == target)
		return tree;
	if ((*tree)->son != NULL) {
		path = findTreeVal(&((*tree)->son), target);
    if (path)
      return path;
	}
	if ((*tree)->brother != NULL) {
		path = findTreeVal(&((*tree)->brother), target);
    if (path)
      return path;
	}
	return NULL;
}

int addNode(Tree ** tree)
{
  int pass = 1;
  char c;
  //
  if (*tree == NULL) {
    c = getchar();
    switch (c) {
      case 'r':
        scanf(" %d", &pass);
        *tree = createNode(pass);
        return 0;
        break;
      default:
        printf("?\n");
        return 0;
    }
  } else {
    Tree * tmp = createNode(0);
    tmp->son = *tree;
    //
    while (pass) {
      c = getchar();
      switch (c) {
        case 'r':
          if (*tree != NULL) {
            printf("?\n");
            return 0;
          }
          break;
        case 'v':
          scanf(" %d ", &pass);
          tmp->son = *findTreeVal(tree, pass);
          if(tmp->son == NULL)
            return 1;
          pass = 0;
          break;
        case 'b':
          if (moveBrother(tmp)) {
            free(tmp);
            return 1;
          }
          break;
        case 's':
          if (moveSon(tmp)) {
            free(tmp);
            return 1;
          }
          break;
        case ' ':
          pass = 0;
          break;
      }
    }
    //
    Tree * node = createNode(0);
    if (tmp->son->son == NULL) {
      tmp->son->son = node;
    } else {
      tmp->son = tmp->son->son;
      while (tmp->son->brother != NULL)
        tmp->son = tmp->son->brother;
      tmp->son->brother = node;
    }
    scanf("%d", &node->value);
    free(tmp);
    return 0;
  }
}

void del_node_supp(Tree ** tree)
{
	if ((*tree)->son != NULL)
		del_node_supp(&((*tree)->son));
	if ((*tree)->brother != NULL)
		del_node_supp(&((*tree)->brother));
	free(*tree);
	*tree = NULL;
}

Tree ** pathNode(Tree ** tree)
{
  int pass = 1;
  char c;
  Tree ** tmp = tree;
  while (pass) {
    c = getchar();
    switch (c) {
      case 'r':
        return tree;
      case 'v':
        scanf(" %d", &pass);
        return findTreeVal(tree, pass);
      case 'b':
        tmp = &((*tmp)->brother);
        if (*tmp == NULL)
          return NULL;
        break;
      case 's':
        tmp = &((*tmp)->son);
        if (*tmp == NULL)
          return NULL;
        break;
      default:
        return tmp;
    }
  }
  return NULL;
}

int delNode(Tree ** tree)
{
  if (*tree == NULL) {
    printf("null\n");
    return 0;
  } else {
    Tree ** tmp = pathNode(tree);
    if (*tmp == NULL)
      return 1;
    if ((*tmp)->son != NULL)
      del_node_supp(&((*tmp)->son));
    if ((*tmp)->brother != NULL) {
      Tree * pivet = *tmp;
      *tmp = (*tmp)->brother;
      free(pivet);
    } else {
      if (*tmp == *tree)
        printf("no root\n");
      free(*tmp);
      *tmp = NULL;
    }
	}
  return 0;
}

void print_sup(Tree * node, int deep)
{
	for (int i = 0; i < deep - 1; i++) {
    putchar('|');
    putchar('\t');
  }
  if (deep != 0)
    printf("|----> ");
	printf("%d\n", node->value);
	if (node->son != NULL)
		print_sup(node->son, deep + 1);
	if (node->brother != NULL)
		print_sup(node->brother, deep);
}

void printTree(Tree * tree)
{
  if (tree == NULL)
    printf("no tree\n");
  else
    print_sup(tree, 0);
}

void deleteTree(Tree ** tree)
{
  if (*tree != NULL) {
    if ((*tree)->son != NULL) {
      del_node_supp(&((*tree)->son));
    }
    free(*tree);
    *tree = NULL;
  }
  //printf("no root\n");
}

void countTree(Tree * node, int ** count)
{
  if (node->son != NULL) {
    **count = **count + 1;
    countTree(node->son, count);
  }
  if (node->brother != NULL)
    countTree(node->brother, count);
}

int neterTree(Tree * tree)
{
  int count = 0;
  int * p = &(count);
  //
  if (tree->son != NULL) {
    count++;
    countTree(tree->son, &p);
  }
  if (tree->brother != NULL)
    countTree(tree->brother, &p);
  return count;
}
