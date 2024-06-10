//Гамов Павел
//группа 207

#include <iostream>
#include "FazzyNumbers_class.hpp"

int main()
{
  std::cout << "Программа демонстрации работы с неявными числами" << std::endl;
  int a,b,c;
  std::cout << "Введите первое число ";
  std::cin >> a >> b >> c;
  FazzyNumbers <int> first(a, b, c);

  std::cout << "Введите второе число ";
  std::cin >> a >> b >> c;
  FazzyNumbers <int> second(a, b, c);

  std::cout << "Первое число ";
  first.printNumber();
  std::cout << "Второе число ";
  second.printNumber();

  char res;
  std::cout << "что вы хотите с ними сделать? ";

  while(1) {
    std::cin >> res;
    switch (res) {
      case '+':
        std::cout << "Результат суммы ";  (first + second).printNumber();
        break;
      case '-':
        std::cout << "Результат вычитания ";  (first - second).printNumber();
        break;
      case '*':
        std::cout << "Результат умножения ";  (first * second).printNumber();
        break;
      case '/':
        std::cout << "Результат деления ";  (first / second).printNumber();
        break;
      case '!':
        std::cout << "Обратное число ";  (!first).printNumber();
        break;
      case '<':
        std::cout << "Второе ";
        if (first < second) { std::cout << "больше "; }
        else {  std::cout << "меньше "; }
        std::cout << "первого";
        break;
      case '>':
        std::cout << "Первое ";
        if (first > second) { std::cout << "больше";  }
        else { std::cout << "меньше"; }
        std::cout << "второго";
        break;
      default:
        return 0;
    }
  }
  return 0;
}
