#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int * data;
	int * index;
  int head;
  int size;
} Queue;

Queue * createQueue(int size);
void printQueue(Queue * Q);
void addQueue(Queue * Q);
void deleteElemQueue(Queue * Q);
int popQueue(Queue * Q);
void pushQueue(Queue * Q, int number);
void deleteQueue(Queue * Q);
Queue * mergeQueue(Queue * Q, Queue * R);
int getCountQueue(Queue * Q);

#endif
