#ifndef SOME_H
#define SOME_H

#include <stdio.h>
#include <stdlib.h>

//typedef struct Node;

typedef struct {
	int value;
	struct Node * next;
} Node;

Node * createHead() {
  Node * Q = (Node *)malloc(sizeof(Node));
  Q->value = NULL;
  Q->next = NULL;
  return Q;
}

#endif
