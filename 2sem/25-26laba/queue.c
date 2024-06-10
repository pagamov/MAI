#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int findEmptyQueue(Queue * Q) {
  for (int i = 0; i < Q->size; i++) {
    if (Q->index[i] == -2) {
      return i;
    }
  }
  return -1;
}

void resizeQueue(Queue * Q, int delta) {
  Q->data = (int *)realloc(Q->data, delta * sizeof(int));
  Q->index = (int *)realloc(Q->index, delta * sizeof(int));
  for (size_t i = Q->size; i < delta; i++) {
    Q->index[i] = -2;
  }
  Q->size = delta;
}

int getCountQueue(Queue * Q) {
  if (Q->head == -1) {
    return 0;
  }
  int pivet = Q->head;
  int count = 0;
  while (1) {
    if (Q->index[pivet] == -2) {
      break;
    } else if (Q->index[pivet] == -1) {
      count++;
      break;
    } else {
      pivet = Q->index[pivet];
      count++;
    }
  }
  return count;
}

void printQueue(Queue * Q) {
  int pivet = Q->head;
  if (getCountQueue(Q) != 0) {
    do {
      printf("%d ", Q->data[pivet]);
      pivet = Q->index[pivet];
    } while(pivet != -1);
  } else {
    printf("empty\n");
  }
}

Queue * createQueue(int size) {
  Queue * Q = (Queue *)malloc(sizeof(Queue));
  Q->data = (int *)malloc(size * sizeof(int));
  Q->index = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    Q->index[i] = -2;
  }
  Q->head = -1;
  Q->size = size;
  return Q;
}

void addQueue(Queue * Q) {
  int a;
  int pivet = Q->head;
  int new;

  printf("how many new? ");
  scanf("%d", &a);
  printf("write: ");
  if (Q->size < a + getCountQueue(Q)) {
    resizeQueue(Q, a + getCountQueue(Q));
  }
  if (Q->head == -1) {
    Q->head = findEmptyQueue(Q);
  }
  while (a > 0) {
    if (Q->index[pivet] == -1) {
      new = findEmptyQueue(Q);
      scanf("%d", &Q->data[new]);
      Q->index[new] = -1;
      Q->index[pivet] = new;
      a--;
    } else if (Q->index[pivet] == -2) {
      Q->index[pivet] = -1;
      scanf("%d", &Q->data[pivet]);
      a--;
    } else {
      pivet = Q->index[pivet];
    }
  }
}

void deleteElemQueue(Queue * Q) {
  if (Q->head != -1) {
    int target;
    int pivet = Q->head;
    int prev;

    printf("write: ");
    scanf("%d", &target);

    while (pivet != -1) {
      if (Q->data[pivet] == target) {
        if (pivet == Q->head) {
          Q->head = Q->index[pivet];
          Q->index[pivet] = -2;
          pivet = Q->head;
        } else {
          Q->index[prev] = Q->index[pivet];
          Q->index[pivet] = -2;
          pivet = Q->index[prev];
        }
      } else {
        prev = pivet;
        pivet = Q->index[pivet];
      }
    }
    printf("done\n");
  }
}

int popQueue(Queue * Q) {
  if (getCountQueue(Q) != 0) {
    int res;
    int pivet = Q->head;
    Q->head = Q->index[pivet];
    res = Q->data[pivet];
    Q->index[pivet] = -2;
    return res;
  } else {
    printf("empty\n");
    return -1;
  }
}

void pushQueue(Queue * Q, int number) {
  if (Q->size > 0) {
    int pivet = Q->head;
    int empty;

    if (Q->size == getCountQueue(Q))
      resizeQueue(Q, Q->size + 1);

    empty = findEmptyQueue(Q);
    if (Q->head == -1) {
      Q->head = empty;
    } else {
      while (Q->index[pivet] != -1) {
        pivet = Q->index[pivet];
      }
      Q->index[pivet] = empty;
    }
    Q->index[empty] = -1;
    Q->data[empty] = number;
  } else {
    printf("no queue\n");
  }
}

void deleteQueue(Queue * Q) {
  for (int i = 0; i < Q->size; i++) {
    Q->index[i] = -2;
  }
  Q->head = -1;
}

int isEmptyQueue(Queue * Q) {
  if (getCountQueue(Q) > 0) {
    return 0;
  } else {
    return 1;
  }
}

Queue * mergeQueue(Queue * Q, Queue * R) {
  int new = getCountQueue(R);
  for (int i = 0; i < new; i++) {
    pushQueue(Q, popQueue(R));
  }
  deleteQueue(R);
  return Q;
}
