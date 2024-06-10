#include "list.h"
#include "array.h"

List * createList()
{
  List * list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

char * popList(List * list)
{
  if (list->size == 0) {
    return NULL;
  } else if (list->size == 1) {
    char * res = list->tail->tree->data;
    free(list->tail->tree);
    free(list->tail);
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    return res;
  } else {
    char * res = list->tail->tree->data;
    free(list->tail->tree);
    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;
    list->size--;
    return res;
  }
}

void pushList(List * list, char * input)
{
  Node * tmp = (Node *)malloc(sizeof(Node));
  tmp->tree = createNode(input);
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
}

void pushListTree(List * list, Tree * tree)
{
  Node * tmp = (Node *)malloc(sizeof(Node));
  tmp->tree = tree;
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
}

char * shiftList(List * list)
{
  if (list->size == 0) {
    return NULL;
  } else if (list->size == 1) {
    char * res = list->head->tree->data;
    free(list->head->tree);
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    return res;
  } else {
    char * res = list->head->tree->data;
    free(list->head->tree);
    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
    list->size--;
    return res;
  }
}

void unshiftList(List * list, char * input)
{
  Node * tmp = (Node *)malloc(sizeof(Node));
  tmp->tree = createNode(input);
  if (list->size == 0) {
    list->head = tmp;
    list->tail = tmp;
    tmp->next = NULL;
    tmp->prev = NULL;
  } else {
    tmp->next = list->head;
    list->head->prev = tmp;
    tmp->prev = NULL;
    list->head = tmp;
  }
  list->size++;
}

void printList(List * list)
{
  printf("list: ");
  if (list->size != 0) {
    Node * tmp = list->head;
    int j = 0;
    for (int i = 0; i < list->size; i++) {
      while (tmp->tree->data[j] != '\0') {
        printf("%c", tmp->tree->data[j]);
        j++;
      }
      j = 0;
      putchar(' ');
      tmp = tmp->next;
    }
    putchar('\n');
  }
}

int notEmpty(List * list)
{
  if (list->size != 0)
    return 1;
  return 0;
}
void deleteList(List ** list)
{
  if ((*list) != NULL) {
    int size = (*list)->size;
    Node * tmp = (*list)->head;
    for (int i = 0; i < size; i++) {
      deleteTree(&(tmp->tree));
      if ((*list)->size == 1) {
        free((*list)->head);
        (*list)->head = NULL;
        (*list)->tail = NULL;
        (*list)->size--;
      } else {
        tmp = tmp->next;
        (*list)->head = tmp;
        free(tmp->prev);
        tmp->prev = NULL;
        (*list)->size--;
      }
    }
    free(*list);
    *list = NULL;
  }
}

Tree * deleteNode(List * list, Node * node)
{
  Tree * res = node->tree;
  if (list->head == node) {
    list->head = node->next;
    node->next->prev = NULL;
  } else if (list->tail == node) {
    list->tail = node->prev;
    node->prev->next = NULL;
  } else {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  free(node);
  list->size--;
  return res;
}

Tree * createOperandTree(List ** list)
{
  Node * tmp = (*list)->head;
  Tree * left;
  Tree * right;
  while ((*list)->size != 1) {
    if (is_needToDeAdded(tmp->tree->data) || treeGoDeep(tmp->tree)) {
      tmp = tmp->next;
      if (is_needToDeAdded(tmp->tree->data) || treeGoDeep(tmp->tree)) {
        tmp = tmp->next;
        if (is_needToDeAddedMinus(tmp->tree->data) && !(treeGoDeep(tmp->tree))) {
          left = deleteNode((*list), tmp->prev->prev);
          right = deleteNode((*list), tmp->prev);
          tmp->tree->left = left;
          tmp->tree->right = right;
          tmp = (*list)->head;
        } else {
          tmp = tmp->prev;
        }
      }
    } else {
      tmp = tmp->next;
    }
  }
  Tree * res = (*list)->head->tree;
  free((*list)->head);
  free(*list);
  (*list) = NULL;
  return res;
}
