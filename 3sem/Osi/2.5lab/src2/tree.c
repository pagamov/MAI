#include "tree.h"
#include "array.h"
#include "list.h"
#include <string.h>
#include <unistd.h>

Tree * createNode(char * data)
{
  Tree * node = (Tree *)malloc(sizeof(Tree));
  int size = 0;
  while (data[size] != '\0')
    size++;
  node->data = (char *)malloc((size + 1) * sizeof(char));
  for (int i = 0; i < size; i++)
    node->data[i] = data[i];
  node->data[size] = '\0';
  node->left = NULL;
  node->right = NULL;
  return node;
}

void print_sup(Tree * node, int deep, int file)
{
    char * m = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < deep - 1; i++) {
        strcpy(m, "   \0");
        write(file, m, strlen(m) + 1);
        usleep(10);
    }
    if (deep != 0) {
        strcpy(m, "|  \0");
        write(file, m, strlen(m) + 1);
        usleep(10);
    }
    strcpy(m, node->data);
    write(file, m, strlen(m) + 1);
    usleep(10);

    strcpy(m, "endl\0");
    write(file, m, strlen(m) + 1);
    usleep(10);

    if (node->left != NULL)
	   print_sup(node->left, deep + 1, file);
    if (node->right != NULL)
	   print_sup(node->right, deep + 1, file);
    free(m);
}

void printTree(Tree * tree, int file)
{
    char * m = (char *)malloc(sizeof(char) * 100);
    if (tree == NULL) {
        strcpy(m, "no tree\0");
        write(file, m, strlen(m) + 1);
        sleep(1);
    } else {
        print_sup(tree, 0, file);
    }
    free(m);
}

void del_node_supp(Tree ** tree)
{
	if ((*tree)->right != NULL)
		del_node_supp(&((*tree)->right));
	if ((*tree)->left != NULL)
		del_node_supp(&((*tree)->left));
  free((*tree)->data);
	free(*tree);
	*tree = NULL;
}

void deleteTree(Tree ** tree)
{
  if (*tree != NULL)
    del_node_supp(tree);
}

int treeGoDeep(Tree * tree)
{
  if (tree->left != NULL || tree->right != NULL) {
    return 1;
  }
  return 0;
}

Tree * copyTree(Tree * tree)
{
  Tree * tmp = createNode(tree->data);
  if (tree->left != NULL)
    tmp->left = copyTree(tree->left);
  if (tree->right != NULL)
    tmp->right = copyTree(tree->right);
  return tmp;
}

int needDergee(Tree * tree)
{
  if (is_operatorNorm(tree->data[0]) && (tree->data[0] == '+' || tree->data[0] == '-') && (!(is_operandLetter(tree->data[1]))) && (!(is_opereandNumber(tree->data[1]))))
    if (tree->left->data[0] == '^' && is_operatorNorm(tree->left->data[0]) && tree->right->data[0] == '^' && is_operatorNorm(tree->right->data[0]))
      if ((is_needToDeAdded(tree->left->left->data) || treeGoDeep(tree->left->left)) && (is_needToDeAdded(tree->right->left->data) || treeGoDeep(tree->right->left))) {
        // calculateAsUCan(&(tree->left->right));
        // calculateAsUCan(&(tree->right->right));
        if (tree->left->right->data[0] == '3' && tree->left->right->data[1] == '\0' && tree->right->right->data[0] == '3' && tree->right->right->data[1] == '\0') {
          if (tree->data[0] == '+')
            return 1;
          else if (tree->data[0] == '-')
            return 2;
        }
      }
  return 0;
}

void reBuildTree(Tree ** tree)
{
  int res = needDergee(*tree);
  if (res) {
    char * arr = NULL;
    arr = createArray(arr);
    List * list = createList();
    pushListTree(list, copyTree((*tree)->left->left)); // add a
    pushListTree(list, copyTree((*tree)->right->left)); // add b
    if (res == 1)
      pushList(list, (*tree)->data); // add +
    else if (res == 2)
      pushList(list, (*tree)->data); // add -
    pushListTree(list, copyTree((*tree)->left->left)); // add a
    arr = addToDataArray(arr, '2');
    pushList(list, arr); // add 2
    arr = refresh(arr);
    pushList(list, (*tree)->left->data); // add ^
    pushListTree(list, copyTree((*tree)->left->left)); // add a
    pushListTree(list, copyTree((*tree)->right->left)); // add b
    arr = addToDataArray(arr, '*');
    pushList(list, arr); // add *
    arr = refresh(arr);
    if (res == 1)
      arr = addToDataArray(arr, '-'); // add -
    else if (res == 2)
      arr = addToDataArray(arr, '+'); // add +
    pushList(list, arr);
    arr = refresh(arr);
    pushListTree(list, copyTree((*tree)->right->left)); // add b
    arr = addToDataArray(arr, '2');
    pushList(list, arr); // add 2
    arr = refresh(arr);
    pushList(list, (*tree)->left->data); // add ^
    arr = addToDataArray(arr, '+');
    pushList(list, arr); // add -
    arr = refresh(arr);
    arr = addToDataArray(arr, '*');
    pushList(list, arr); // add *
    arr = refresh(arr);
    //
    deleteTree(tree);
    *tree = createOperandTree(&list);
    free(arr);
  }
  if ((*tree)->left != NULL)
    reBuildTree(&((*tree)->left));
  if ((*tree)->right != NULL)
    reBuildTree(&((*tree)->right));
}

void calculateAsUCan(Tree ** tree)
{
  int left, right, res;
  if (is_operatorNorm((*tree)->data[0]) && (*tree)->data[1] == '\0') {
    if (((*tree)->left) != NULL)
      calculateAsUCan(&((*tree)->left));
    if (((*tree)->right) != NULL)
      calculateAsUCan(&((*tree)->right));
    if (is_integer((*tree)->left->data) && is_integer((*tree)->right->data)) {
      left = replaceCharToInt((*tree)->left->data);
      right = replaceCharToInt((*tree)->right->data);
      switch ((*tree)->data[0]) {
        case '+': res = left + right; break;
        case '-': res = left - right; break;
        case '^': res = int_power(left, right); break;
        case '/': res = left / right; break;
        case '*': res = left * right; break;
      }
      deleteTree(&((*tree)->left));
      deleteTree(&((*tree)->right));
      free((*tree)->data);
      (*tree)->data = replaceIntToChar(res);
    }
  }
}
