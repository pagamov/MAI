#include "table.h"

char q = ' ';
int pass = 1, res;
float req;

clock_t begin, end;
double time_spent;



int main()
{
  //int size1 = 20000, size2 = size1*2, size3 = size2*2;


  // reverse(table, 100);
  // printTable(table);
  // return 0;
  //
  // puts("-------");
  // complete(table, size1);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting random : %g sec\n", size1, time_spent);
  //
  // reverse(table, size1);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting reversed : %g sec\n", size1, time_spent);
  //
  // normal(table, size1);
  // randomizer(table);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting almost sorted : %g sec\n", size1, time_spent);
  //
  // puts("-------");
  //
  // complete(table, size2);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting random : %g sec\n", size2, time_spent);
  //
  // reverse(table, size2);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting reversed : %g sec\n", size2, time_spent);
  //
  // normal(table, size2);
  // randomizer(table);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting almost sorted : %g sec\n", size2, time_spent);
  //
  // puts("-------");
  //
  // complete(table, size3);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting random : %g sec\n", size3, time_spent);
  // reverse(table, size3);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting reversed : %g sec\n", size3, time_spent);
  // normal(table, size3);
  // randomizer(table);
  // begin = clock();
  // insertionSort(table);
  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // printf("spent on %d size sorting almost sorted : %g sec\n", size3, time_spent);
  // puts("-------");
  // deleteTable(&table);
  Table * table = createTable();
  while (pass) {
    q = getchar();
    switch (q) {
      case '+':
        addToTable(table);
        break;
      case '-':
        scanf(" %g", &req);
        deleteFromTable(table, req);
        break;
      case 'f':
        scanf(" %g", &req);
        res = binarySearchByKey(table, req);
        if (res != -1)
          printf("in table number : %d value : %s\n", res, table->data[res].value);
        else
          puts("not in table");
        break;
      case 'p':
        printTable(table);
        break;
      case 's':
        insertionSort(table);
        break;
      case 'r':
        randomizer(table);
        break;
      case 'q':
        deleteTable(&table);
        pass = 0;
        break;
    }
  }
  return 0;
}
