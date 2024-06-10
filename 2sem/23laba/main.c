#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

char q;
int pass = 1;

int main() {
  Tree * tree = createTree();
  while (pass) {
    q = getchar();
    //
    switch (q) {
      case '+':
        if (addNode(&tree))
          printf("no path\n");
        break;
      case '-':
        if (delNode(&tree))
          printf("no path\n");
          break;
      case 'p':
        printTree(tree);
        break;
      case 'n':
        printf("res:  %d\n", neterTree(tree));
        break;
      case 'q':
        deleteTree(&tree);
        pass = 0;
        break;
    }
  }
  return 0;
}
