#include "array.h"

char * addToDataArray(char * data, char new)
{
  int size = 0;
  while (data[size] != '\0')
    size++;
  data = (char *)realloc(data, (size + 2) * sizeof(char));
  data[size] = new;
  data[size + 1] = '\0';
  return data;
}

char * createArray(char * arr)
{
  arr = (char *)malloc(sizeof(char));
  arr[0] = '\0';
  return arr;
}

char * refresh(char * arr)
{
  arr = (char *)realloc(arr, sizeof(char));
  arr[0] = '\0';
  return arr;
}

int is_operatorNorm(char q)
{
  if (q == '+' || q == '/' || q == '-' || q == '*' || q == '^')
    return 1;
  return 0;
}

int is_operandLetter(char q)
{
  if (q >= 'a' && q <= 'z')
    return 1;
  return 0;
}

int is_opereandNumber(char q)
{
  if (q >= '0' && q <= '9')
    return 1;
  return 0;
}

int is_operatorScob(char q)
{
  if (q == '(')
    return 1;
  else if (q == ')')
    return 2;
  return 0;
}

int ratingOperator(char in, char sver)
{
  switch (in) {
    case '^':
      return 1;
      break;
    case '/':
      if (sver == '-' || sver == '+' || sver == '(')
        return 1;
      break;
    case '*':
      if (sver == '-' || sver == '+' || sver == '(')
        return 1;
      break;
    case '+':
      if (sver == '(')
        return 1;
      break;
    case '-':
      if (sver == '(')
        return 1;
      break;
  }
  return 0;
}

int is_needToDeAdded(char * arr)
{
  if (is_operandLetter(arr[0]) || is_opereandNumber(arr[0]) || is_operandLetter(arr[1]) || is_opereandNumber(arr[1]))
    return 1;
  return 0;
}

int is_needToDeAddedMinus(char * arr)
{
  if (arr[0] == '-' && (is_operandLetter(arr[1]) || is_opereandNumber(arr[1])))
    return 0;
  if (is_operatorNorm(arr[0]))
    return 1;
  return 0;
}

int is_integer(char * arr)
{
  int i = 0;
  if ((is_operatorNorm(arr[0]) && arr[1] == '\0') || is_operandLetter(arr[0]))
    return 0;
  i++;
  while (arr[i] != '\0') {
    if (!(is_opereandNumber(arr[i])))
      return 0;
    i++;
  }
  return 1;
}

int replaceCharToInt(char * arr)
{
  int res = 0, i = 0, minus = 0;
  if (arr[i] == '-') {
    minus = 1;
    i += 1;
  }
  while (arr[i] != '\0') {
    switch (arr[i]) {
      case '0': break;
      case '1': res += 1; break;
      case '2': res += 2; break;
      case '3': res += 3; break;
      case '4': res += 4; break;
      case '5': res += 5; break;
      case '6': res += 6; break;
      case '7': res += 7; break;
      case '8': res += 8; break;
      case '9': res += 9; break;
    }
    res *= 10;
    i++;
  }
  res /= 10;
  if (minus)
    res *= -1;
  return res;
}

int int_power(int low, int pow)
{
  int a = low;
  if (pow == 0)
    return 1;
  while (pow - 1 != 0) {
    a *= low;
    pow--;
  }
  return a;
}

char * replaceIntToChar(int number)
{
  char * arr = NULL;
  arr = createArray(arr);
  int pivet = number, size = 0;
  if (number == 0) {
    addToDataArray(arr, '0');
    return arr;
  }
  if (number < 0) {
    number *= -1;
    addToDataArray(arr, '-');
  }
  while (pivet != 0) {
    pivet /= 10;
    size++;
  }
  for (int i = 0; i < size; i++) {
    pivet = number;
    if (i == 0)
      pivet = pivet / int_power(10, size - 1);
    else
      pivet = pivet / int_power(10, size - i - 1) % 10;
    switch (pivet) {
      case 0: arr = addToDataArray(arr, '0'); break;
      case 1: arr = addToDataArray(arr, '1'); break;
      case 2: arr = addToDataArray(arr, '2'); break;
      case 3: arr = addToDataArray(arr, '3'); break;
      case 4: arr = addToDataArray(arr, '4'); break;
      case 5: arr = addToDataArray(arr, '5'); break;
      case 6: arr = addToDataArray(arr, '6'); break;
      case 7: arr = addToDataArray(arr, '7'); break;
      case 8: arr = addToDataArray(arr, '8'); break;
      case 9: arr = addToDataArray(arr, '9'); break;
    }
  }
  return arr;
}
