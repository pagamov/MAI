#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List * createList() {
  List * list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

int sizeList(List * list) {
  return list->size;
}

int isNullList(List * list) {
  if (list->size != 0) {
    return 0;
  } else {
    return 1;
  }
}

int popList(List * list) {
  if (list->size == 0) {
    return -1;
  } else if (list->size == 1) {
    int res = list->head->value;
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    return res;
  } else {
    int res = list->tail->value;
    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;
    list->size--;
    return res;
  }
}

void pushList(List * list, int number) {
  Node * tmp = (Node *)malloc(sizeof(Node));
  if (list->size == 0) {
    list->head = tmp;
    list->tail = tmp;
    tmp->next = NULL;
    tmp->prev = NULL;
  } else {
    tmp->next = NULL;
    tmp->prev = list->tail;
    list->tail->next = tmp;
    list->tail = tmp;
  }
  list->size++;
  tmp->value = number;
}

int shiftList(List * list) {
  if (list->size == 0) {
    return -1;
  } else if (list->size == 1) {
    int res = list->head->value;
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    return res;
  } else {
    int res = list->head->value;
    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
    list->size--;
    return res;
  }
}

void unshiftList(List * list, int number) {
  Node * tmp = (Node *)malloc(sizeof(Node));
  if (list->size == 0) {
    list->head = tmp;
    list->tail = tmp;
    tmp->value = number;
    tmp->next = NULL;
    tmp->prev = NULL;
  } else {
    tmp->next = list->head;
    list->head->prev = tmp;
    tmp->prev = NULL;
    list->head = tmp;
  }
  list->size++;
  tmp->value = number;
}

void sliceList(List * list, int start, int count) {
    if (list->size > start) {
      Node * tmp = (Node *)malloc(sizeof(Node));
      tmp->prev = list->head;
      for (int i = 0; i < start; i++) {
        tmp->prev = tmp->prev->next;
      }
      tmp->next = tmp->prev;
      for (int i = 0; i < count - 1; i++) {
        if (tmp->next->next != NULL)
          tmp->next = tmp->next->next;
      }
      if (list->head == tmp->prev && list->tail == tmp->next) {
        list->head = NULL;
        list->tail = NULL;
      } else if (list->head == tmp->prev && list->tail != tmp->next) {
        list->head = tmp->next->next;
        tmp->next->next->prev = NULL;
      } else if (list->head != tmp->prev && list->tail == tmp->next) {
        list->tail = tmp->prev->prev;
        tmp->prev->prev->next = NULL;
      } else {
        tmp->next->next->prev = tmp->prev->prev;
        tmp->prev->prev->next = tmp->next->next;
      }
      while (tmp->prev != tmp->next) {
        tmp->prev = tmp->prev->next;
        free(tmp->prev->prev);
      }
      free(tmp->prev);
      list->size -= count;
      free(tmp);
    }
}

void printList(List * list) {
  if (list->size != 0) {
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->next = list->head;
    for (int i = 0; i < list->size; i++) {
      printf("%d ", tmp->next->value);
      tmp->next = tmp->next->next;
    }
    free(tmp);
  }
}

void insertList(List * list, int position, int value) {
  if (position <= list->size && position >= 0) {
    if (list->size == 0 || position == list->size) {
      pushList(list, value);
    } else if (list->size == 1 || position == 0) {
      if (position == 1) {
        pushList(list, value);
      } else if (position == 0) {
        unshiftList(list, value);
      }
    } else {
      Node * tmp = (Node *)malloc(sizeof(Node));
      if (position < list->size / 2) {
        tmp->prev = list->head;
        for (int i = 0; i < position; i++)
          tmp->prev = tmp->prev->next;
      } else {
        tmp->prev = list->tail;
        for (int i = 0; i < list->size - position - 1; i++)
          tmp->prev = tmp->prev->prev;
      }
      tmp->prev = tmp->prev->prev;
      tmp->next = tmp->prev->next;
      tmp->prev->next = tmp;
      tmp->next->prev = tmp;
      tmp->value = value;
      list->size++;
    }
  }
}

void reverseList(List * list) {
  if (list->size != 0 && list->size != 1) {
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->next = list->head;
    list->head = list->tail;
    list->tail = tmp->next;
    //
    tmp->next = list->head;
    while (tmp->next != NULL) {
      tmp->prev = tmp->next->next;
      tmp->next->next = tmp->next->prev;
      tmp->next->prev = tmp->prev;
      //
      tmp->next = tmp->next->next;
    }
    free(tmp);
  }
}

int indexList(List * list, int target) {
  if (list->size != 0) {
    Node * tmp = (Node *)malloc(sizeof(Node));
    int w = 0;
    tmp->next = list->head;
    while (tmp->next != NULL) {
      if (tmp->next->value == target) {
        free(tmp);
        return w;
      }
      tmp->next = tmp->next->next;
      w++;
    }
    free(tmp);
    return -1;
  }
  return -2;
}

void removeList(List * list, int target) {
  if (list->size != 0) {
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->next = list->head;
    while (tmp->next != NULL) {
      if (tmp->next->value == target)
        break;
      tmp->next = tmp->next->next;
    }
    if (tmp->next != NULL) {
      if (tmp->next == list->tail) {
        sliceList(list, list->size - 1, 1);
      } else if (tmp->next == list->head) {
        sliceList(list, 0, 1);
      } else {
        tmp->next->next->prev = tmp->next->prev;
        tmp->next->prev->next = tmp->next->next;
        list->size--;
        free(tmp->next);
      }
    }
    free(tmp);
  }
}

int countList(List * list, int target) {
  if (list->size != 0) {
    Node * tmp = (Node *)malloc(sizeof(Node));
    int count = 0;
    tmp->next = list->head;
    while (tmp->next != NULL) {
      if (tmp->next->value == target)
        count++;
      tmp->next = tmp->next->next;
    }
    free(tmp);
    return count;
  } else {
    return 0;
  }
}

void clearList(List * list) {
  sliceList(list, 0, list->size);
}

void deleteList(List ** list) {
  sliceList(*list, 0, (*list)->size);
  free(*list);
  *list = NULL;
}

void unconventionalList(List * list, int position, int value, int count) {
  if (list->size == 0) {
    for (int i = 0; i < count; i++)
      pushList(list, value);
  } else {
    int delta = count - countList(list, value);
    if (position == 0) {
      for (int i = 0; i < delta; i++)
        unshiftList(list, value);
    } else if (position == list->size) {
      for (int i = 0; i < delta; i++)
        pushList(list, value);
    } else {
      Node * tmp = (Node *)malloc(sizeof(Node));
      if (position < list->size / 2) {
        tmp->prev = list->head;
        for (int i = 0; i < position; i++)
          tmp->prev = tmp->prev->next;
      } else {
        tmp->prev = list->tail;
        for (int i = 0; i < list->size - position - 1; i++)
          tmp->prev = tmp->prev->prev;
      }
      for (int i = 0; i < delta; i++) {
        Node * pivet = (Node *)malloc(sizeof(Node));
        pivet->prev = tmp->prev;
        //
        pivet->prev = pivet->prev->prev;
        pivet->next = pivet->prev->next;
        pivet->prev->next = pivet;
        pivet->next->prev = pivet;
        pivet->value = value;
        list->size++;
      }
      free(tmp);
    }
  }
}
