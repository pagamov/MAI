#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int size;

void requestS(FILE * base, int * size) {
  fscanf(base, "%d\n", size);
}

void requesttaC(FILE * base, char (*mass)[SIZE], int size) {
  for (int i = 0; i < size; i++) {
    fscanf(base, "%s\n", mass[i]);
  }
}

void requesttaCR(FILE * base, char (*mass)[SIZE], int *massR, int size) {
  for (int i = 0; i < size; i++) {
    fscanf(base, "%s\t%d\n", mass[i], &massR[i]);
  }
}

void requesttaIR(FILE * base, int * mass, int * massR, int size) {
  for (int i = 0; i < size; i++) {
    fscanf(base, "%d\t%d\n", &mass[i], &massR[i]);
  }
}
