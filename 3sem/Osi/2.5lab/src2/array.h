#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

//structure
enum Status {
  operand,
  operator,
  vait,
  left,
  right
};

//functions
char * addToDataArray(char * data, char new);
char * createArray(char * arr);
char * refresh(char * arr);
int is_operatorNorm(char q);
int is_operandLetter(char q);
int is_opereandNumber(char q);
int is_operatorScob(char q);
int ratingOperator(char in, char sver);
int is_needToDeAdded(char * arr);
int is_needToDeAddedMinus(char * arr);
int is_integer(char * arr);
int replaceCharToInt(char * arr);
char * replaceIntToChar(int number);
int int_power(int low, int pow);

#endif
