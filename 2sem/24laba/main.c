#include "list.h"
#include "tree.h"
#include "array.h"
//global vars section
char * arr = NULL;
char * pivet = NULL;
int size = 0, error = 0;

int main()
{
  char q = '\0';
  List * OperatorArr = createList();
  List * OutputArr = createList();
  enum Status status = vait;
  arr = createArray(arr);
  while (q != '\n') {
    q = getchar();
    if (is_operatorScob(q) == 1) {
      switch (status) {
        case operand:
          if (arr[0] == '-' && arr[1] == '\0') {
            arr = refresh(arr);
            arr = addToDataArray(arr, '0');
            pushList(OutputArr, arr);
            arr = refresh(arr);
            arr = addToDataArray(arr, '-');
            pushList(OperatorArr, arr);
            arr = refresh(arr);
          }
          break;
        case operator:
        case vait:
        case left:
          arr = addToDataArray(arr, q);
          pushList(OperatorArr, arr);
          arr = refresh(arr);
          status = left;
          break;
        default:
          error = 1;
      }
    } else if (is_operatorScob(q) == 2) {
      switch (status) {
        case operand:
          pushList(OutputArr, arr);
          arr = refresh(arr);
          pivet = popList(OperatorArr);
          while (pivet[0] != '(') {
            pushList(OutputArr, pivet);
            free(pivet);
            pivet = popList(OperatorArr);
          }
          free(pivet);
          status = right;
          break;
        case right:
          pivet = popList(OperatorArr);
          while (pivet[0] != '(') {
            pushList(OutputArr, pivet);
            free(pivet);
            pivet = popList(OperatorArr);
          }
          free(pivet);
          status = right;
          break;
        default:
          error = 1;
      }
    } else if (is_operatorNorm(q)) {
      switch (status) {
        case operand:
          pushList(OutputArr, arr);
          arr = refresh(arr);
          arr = addToDataArray(arr, q);
          if (notEmpty(OperatorArr)) {
            pivet = popList(OperatorArr);
            if (ratingOperator(q, pivet[0])) {
              pushList(OperatorArr, pivet);
              pushList(OperatorArr, arr);
            } else {
              pushList(OperatorArr, arr);
              pushList(OutputArr, pivet);
            }
            free(pivet);
          } else {
            pushList(OperatorArr, arr);
          }
          arr = refresh(arr);
          status = operator;
          break;
        case operator:
          break;
        case vait:
        case left:
          if (q == '-') {
            arr = addToDataArray(arr, q);
            status = operand;
          } else if (q == '+')
            break;
          else
            error = 1;
          break;
        case right:
          arr = addToDataArray(arr, q);
          if (notEmpty(OperatorArr)) {
            pivet = popList(OperatorArr);
            if (ratingOperator(q, pivet[0])) {
              pushList(OperatorArr, pivet);
              pushList(OperatorArr, arr);
            } else {
              pushList(OperatorArr, arr);
              pushList(OutputArr, pivet);
            }
            free(pivet);
          } else {
            pushList(OperatorArr, arr);
          }
          arr = refresh(arr);
          status = operator;
          break;
        default:
          error = 1;
      }
    } else if (is_operandLetter(q) || is_opereandNumber(q)) {
      switch (status) {
        case operand:
          arr = addToDataArray(arr, q);
          break;
        case operator:
        case vait:
        case left:
          arr = addToDataArray(arr, q);
          status = operand;
          break;
        default:
          error = 1;
      }
    }
  }
  switch (status) {
    case operand:
      pushList(OutputArr, arr);
    case right:
      while (notEmpty(OperatorArr)) {
        pivet = popList(OperatorArr);
        pushList(OutputArr, pivet);
        free(pivet);
      }
      break;
    default:
      error = 1;
  }
  free(arr);
  if (error) {
    printf("error\n");
    deleteList(&OperatorArr);
    deleteList(&OutputArr);
    return 0;
  }
  deleteList(&OperatorArr);
  //
  printList(OutputArr);
  //
  puts("entered");
  Tree * tree = createOperandTree(&OutputArr);
  printTree(tree);
  //
  puts("reBuilded");
  reBuildTree(&tree);
  printTree(tree);
  // printTree(tree);
  //
  puts("calculated");
  calculateAsUCan(&tree);
  printTree(tree);
  //
  deleteTree(&tree);
  return 0;
}
