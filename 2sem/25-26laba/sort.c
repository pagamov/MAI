#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

Queue * qSortQueue(Queue * Q) {
  if (getCountQueue(Q)) {
    Queue * L = createQueue(1);
    Queue * R = createQueue(1);
    int pivet;
    int size = getCountQueue(Q);
    if (size != 1) {
      pivet = popQueue(Q);
      int data;
      for (int i = 0; i < size - 1; i++) {
        data = popQueue(Q);
        if (data > pivet) {
          pushQueue(R, data);
        } else {
          pushQueue(L, data);
        }
      }
      if (getCountQueue(L))
        L = qSortQueue(L);
      if (getCountQueue(R))
        R = qSortQueue(R);
      pushQueue(L, pivet);
      L = mergeQueue(L, R);
      return L;
    } else {
      return Q;
    }
  } else {
    return Q;
  }
}
