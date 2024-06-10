#include "list.h"
#include "tree.h"
#include "array.h"

#include <unistd.h>
#include <math.h>
#include <string.h>

#define SIZE 100

int charToInt(char * string) {
    int i = 0, res = 0;
    if (string[i] == '-') i++;
    while (string[i] != '\0') {
        res *= 10;
        res += string[i] - '0';
        i++;
    }
    return res;
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        perror("alt no discriptor");
        exit(1);
    }

    char * arr = NULL;
    char * pivet = NULL;
    int size = 0, error = 0, fd[2], s, iterator;
    char mess[SIZE], * m, q = '\n';
    fd[0] = charToInt(argv[1]);
    fd[1] = charToInt(argv[2]);

    m = (char *)malloc(sizeof(char) * SIZE);

    strcpy(m, "started\0");
    write(fd[1], m, strlen(m) + 1);

    List * OperatorArr = NULL;
    List * OutputArr = NULL;
    enum Status status = vait;

    while ((s = read(fd[0], mess, SIZE)) > 0) {
        printf("server : %s\n", mess);
        if (strcmp(mess, "exit\0") == 0) {
            strcpy(m, "server exit\0");
            write(fd[1], m, strlen(m) + 1);
            free(m);
            exit(0);
        } else {
            q = '\n';
            OperatorArr = createList();
            OutputArr = createList();
            status = vait;
            arr = createArray(arr);

            iterator = 0;
            while (q != '\0') {
                q = mess[iterator++];
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
                strcpy(m, "error\0");
                write(fd[1], m, strlen(m) + 1);
                deleteList(&OperatorArr);
                deleteList(&OutputArr);
            } else {
                deleteList(&OperatorArr);
                //printList(OutputArr);
                strcpy(m, "entered\0");     write(fd[1], m, strlen(m) + 1);     usleep(10);
                strcpy(m, "endl\0");        write(fd[1], m, strlen(m) + 1);     usleep(10);
                Tree * tree = createOperandTree(&OutputArr);
                printTree(tree, fd[1]);
                strcpy(m, "calculated\0");  write(fd[1], m, strlen(m) + 1);     usleep(10);
                strcpy(m, "endl\0");        write(fd[1], m, strlen(m) + 1);     usleep(10);
                calculateAsUCan(&tree);
                printTree(tree, fd[1]);
                strcpy(m, "end\0");         write(fd[1], m, strlen(m) + 1);
                deleteTree(&tree);
          }
        }
    }
  return 0;
}
