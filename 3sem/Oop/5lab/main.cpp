/* Гамов Павел Антонович М8о-207Б-18
1.   	Коллекция должна быть реализована с помощью умных указателей (std::shared_ptr, std::weak_ptr). Опционально использование std::unique_ptr;
2.   	В качестве параметра шаблона коллекция должна принимать тип данных;
3.   	Реализовать forward_iterator по коллекции;
4.   	Коллекция должны возвращать итераторы begin() и  end();
5.   	Коллекция должна содержать метод вставки на позицию итератора insert(iterator);
6.   	Коллекция должна содержать метод удаления из позиции итератора erase(iterator);
7.   	При выполнении недопустимых операций (например выход аз границы коллекции или удаление не существующего элемента) необходимо генерировать исключения;
8.   	Итератор должен быть совместим со стандартными алгоритмами (например, std::count_if)
9.   	Коллекция должна содержать метод доступа: o Стек – pop, push, top; o Очередь – pop, push, top;Список, Динамический массив – доступ к элементу по оператору [];
10.	    Реализовать программу, которая: o Позволяет вводить с клавиатуры фигуры (с типом int в качестве параметра шаблона фигуры) и добавлять в коллекцию; Позволяет удалять элемент из коллекции по номеру элемента; o Выводит на экран введенные фигуры c помощью std::for_each; o Выводит на экран количество объектов, у которых площадь меньше заданной (с помощью
std::count_if);
Вариант 4:
Трапеция, Стак.
*/
#include <iostream>
#include <algorithm>
#include "trapeze.hpp"
#include "stack.hpp"

int main() {
    size_t N;
    float S;
    char option = '0';
    containers::stack<Trapeze<int>> st;
    Trapeze<int> *tra = nullptr;
    while (option != 'q') {
        std::cout << "choose option (m - man)" << std::endl;
        std::cin >> option;
        switch (option) {
            case 'q':
                break;
            case 'm':
                std::cout << "1) push new element into stack\n"
                          << "2) insert element into chosen position\n"
                          << "3) pop element from the stack\n"
                          << "4) delete element from the chosen position\n"
                          << "5) print stack\n"
                          << "6) count elements with area less then chosen value\n"
                          << "7) print top element\n"
                          << "q) - quit" << std::endl;
                break;
            case '1': {
                try{
                    tra =  new Trapeze<int>(std::cin);
                }catch(std::logic_error& err){
                    std::cout << err.what() << std::endl;
                    break;
                }
                st.push(*tra);
                break;
            }
            case '2': {
                std::cout << "enter position to insert" << std::endl;
                std::cin >> N;
                std::cout << "enter trapeze" << std::endl;
                try{
                    tra =  new Trapeze<int>(std::cin);
                }catch(std::logic_error& err){
                    std::cout << err.what() << std::endl;
                    break;
                }
                st.insert_by_number(N + 1, *tra);
                break;
            }
            case '3': {
                st.pop();
                break;
            }
            case '4': {
                std::cout << "enter position to delete" << std::endl;
                std::cin >> N;
                st.delete_by_number(N + 1);
                break;
            }
            case '5': {
                std::for_each(st.begin(), st.end(), [](Trapeze<int> &TRA) { TRA.Print(std::cout); });
                break;
            }
            case '6': {
                std::cout << "enter max area" <<std::endl;
                std::cin >> S;
                std::cout << std::count_if(st.begin(), st.end(), [=](Trapeze<int> &X) { return X.Area() < S; })
                          << std::endl;
                break;
            }
            case '7' : {
                st.top().Print(std::cout);
                break;
            }
            default:
                std::cout << "Wrong. Try m - manual" << std::endl;
                break;
        }
    }
    return 0;
}
