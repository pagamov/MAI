#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Node {
  float key;
  char * value;
} Node;

typedef struct Table {
  Node * data;
  int size, sorted;
} Table;

Table * createTable();
void addToTable(Table * table);
void printTable(Table * table);
void deleteTable(Table ** table);
int binarySearchByKey(Table * table, float value);
void insertionSort(Table * table);
void deleteFromTable(Table * table, float key);
void randomizer(Table * table);

// void complete(Table * table, int size);
// void reverse(Table * table, int size);
// void normal(Table * table, int size);

#endif
