#include <stdio.h>
#include <stdlib.h>

#include "list.h"

char q;
int pass = 1;
int req, start, count;

int main() {
  List * list = createList();
  //
  printf("1 for push\n2 for pop\n3 for shift\n4 for unshift\n5 for incert\n6 for index\n7 for delete target\ns for slice\np for print\nu for unconventional\nc for clear\n");
  while(pass) {
    scanf("%c", &q);
    switch (q) {
      case ('1'):
        printf("enter: ");
        scanf("%d", &req);
        pushList(list, req);
        break;
      case ('2'):
        printf("res: %d\n", popList(list));
        break;
      case ('3'):
        printf("res: %d\n", shiftList(list));
        break;
      case ('4'):
        printf("enter: ");
        scanf("%d", &req);
        unshiftList(list, req);
        break;
      case ('5'):
        printf("position: ");
        scanf("%d", &start);
        printf("value: ");
        scanf("%d", &count);
        insertList(list, start, count);
        break;
      case ('6'):
        printf("target: ");
        scanf("%d", &count);
        printf("index: %d\n", indexList(list, count));
        break;
      case ('7'):
        printf("target: ");
        scanf("%d", &count);
        removeList(list, count);
        break;
      case ('r'):
        reverseList(list);
        break;
      case ('s'):
        printf("start: ");
        scanf("%d", &start);
        printf("count: ");
        scanf("%d", &count);
        sliceList(list, start, count);
        break;
      case ('p'):
        printf("list: ");
        printList(list);
        printf("size: %d\n", sizeList(list));
        break;
      case ('u'):
        printf("position: ");
        scanf("%d", &start);
        printf("value: ");
        scanf("%d", &req);
        printf("count: ");
        scanf("%d", &count);
        unconventionalList(list, start, req, count);
        break;
      case ('c'):
        clearList(list);
        break;
      case ('q'):
        deleteList(&list);
        pass = 0;
        break;
    }
  }
  return 0;
}
