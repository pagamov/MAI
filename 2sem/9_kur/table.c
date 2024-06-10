#include "table.h"

float epsilon() {
  float e = 1;
  while (e + 1 != 1) {
    e/=2;
  }
  return e;
}

Table * createTable()
{
  int size = 0;
  Table * table = (Table *)malloc(sizeof(Table));
  Node * array = (Node *)malloc(sizeof(Node) * size);
  table->data = array;
  table->size = size;
  table->sorted = 0;
  return table;
}

void addToTable(Table * table)
{
  Node * array = table->data;
  array = (Node *)realloc(array, sizeof(Node) * (table->size + 1));
  table->data = array;
  char * arr = (char *)malloc(sizeof(char) * 120);
  table->data[table->size].value = arr;
  scanf(" %g %s", &(table->data[table->size].key), table->data[table->size].value);
  table->size++;
  table->sorted = 0;
}

int binarySearchByKey(Table * table, float value)
{
  if (!(table->sorted))
    insertionSort(table);
  float e = epsilon();
  int low = 0, top = table->size - 1, mid;
  while (low <= top) {
    mid = (low + top) / 2;
    if (fabs(table->data[mid].key - value) < e)
      return mid;
    else if (value > table->data[mid].key)
      low = mid + 1;
    else
      top = mid - 1;
  }
  return -1;
}

void printTable(Table * table)
{
  for (int i = 0; i < table->size; i++)
    printf("key\t%g\tvalue\t%s\n", table->data[i].key, table->data[i].value);
}

void deleteTable(Table ** table)
{
  if (*table != NULL) {
    if ((*table)->size != 0) {
      for (int i = 0; i < (*table)->size; i++)
        free((*table)->data[i].value);
      free((*table)->data);
    }
    free(*table);
    *table = NULL;
  }
}

int binarySearch(Table * table, float item, int low, int high, float e)
{
  if (high <= low) {
    if (item > table->data[low].key)
      return low + 1;
    else
      return low;
  }
  int mid = (low + high) / 2;
  if (fabs(table->data[mid].key - item) < e)
    return mid + 1;
  if (item > table->data[mid].key)
    return binarySearch(table, item, mid + 1, high, e);
  return binarySearch(table, item, low, mid - 1, e);
}

void insertionSort(Table * table)
{
  float e = epsilon();
  char * arr;
  int i, location, j;
  float selected;
  for (i = 1; i < table->size; ++i) {
      j = i - 1;
      selected = table->data[i].key;
      arr = table->data[i].value;
      location = binarySearch(table, selected, 0, j, e);
      while (j >= location) {
          table->data[j+1] = table->data[j];
          j--;
      }
      table->data[j+1].key = selected;
      table->data[j+1].value = arr;
  }
  table->sorted = 1;
}

void deleteFromTable(Table * table, float key)
{
  int pos = binarySearchByKey(table, key);
  if (pos != -1) {
    free(table->data[pos].value);
    for (int i = pos; i < table->size - 1; i++)
      table->data[i] = table->data[i+1];
    Node * arr = table->data;
    arr = (Node *)realloc(arr, sizeof(Node) * (table->size - 1));
    table->data = arr;
    table->size--;
  }
}

void randomizer(Table * table)
{
  srand(time(NULL));
  int iteration = ((table->size / 10 + rand()) % table->size), l, r;
  float key;
  char * value;
  for (int i = 0; i < iteration; i++) {
    l = rand() % table->size;
    r = rand() % table->size;
    if (l != r) {
      key = table->data[l].key;
      value = table->data[l].value;
      table->data[l] = table->data[r];
      table->data[r].key = key;
      table->data[r].value = value;
    }
  }
}

// void complete(Table * table, int size)
// {
//   srand(time(NULL));
//   if (table->data != NULL)
//     free(table->data);
//   table->size = 0;
//   Node * array = table->data;
//   array = (Node *)malloc(sizeof(Node) * size);
//   table->data = array;
//   for (int i = 0; i < size; i++) {
//     table->data[i].key = (rand()) % size;
//     table->data[i].value = "data\0";
//   }
//   table->size += size;
// }

// void reverse(Table * table, int size)
// {
//   if (table->data != NULL)
//     free(table->data);
//   table->size = 0;
//   Node * array = table->data;
//   array = (Node *)malloc(sizeof(Node) * size);
//   table->data = array;
//   for (int i = 0; i < size; i++) {
//     table->data[i].key = size - i;
//   }
//   table->size += size;
// }
//
// void normal(Table * table, int size)
// {
//   if (table->data != NULL)
//     free(table->data);
//   table->size = 0;
//   Node * array = table->data;
//   array = (Node *)malloc(sizeof(Node) * size);
//   table->data = array;
//   for (int i = 0; i < size; i++) {
//     table->data[i].key = i;
//   }
//   table->size += size;
// }
