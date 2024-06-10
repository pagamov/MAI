/* Гамов Павел Антонович М8о-207Б-18
Разработать шаблоны классов согласно варианту задания.
Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат.
Классы должны иметь публичные поля. Фигуры являются фигурами вращения.
Для хранения координат фигур необходимо использовать шаблон  std::pair.
Создать набор шаблонов, создающих функции, реализующие:
1.       Вычисление геометрического центра фигуры;
2.       Вывод в стандартный поток вывода std::cout координат вершин фигуры;
3.       Вычисление площади фигуры;
Вариант 4:
Трапеция, Ромб, Пятиугольник
*/

#include "Figures.hpp"


void help() {
    std::cout << "Press pe to show information about pentagon" << std::endl;
    std::cout << "Press t to show information about trapeze" << std::endl;
    std::cout << "Press r to show information about rhombus" << std::endl;
    std::cout << "Then enter tuple to use std::tuple<> or class to use class" << std::endl;
    std::cout << "Press q to exit" << std::endl;
}


int main() {
    help();
    using point = std::pair<double, double>;
	using std::make_pair;
    std::cout << std::fixed;
    std::cout.precision(3);
    std::string data, s;
    while(std::cin >> data) {
        if (data == "r") {
            double x1, y1, L_1, L_2;
            std::cout << "Coordinates of center point :" << std::endl;
            std::cin >> x1 >> y1;
            std::cout << "Half of 1 diagonal :" << std::endl;
            std::cin >> L_1;
            std::cout << "Half of 2 diagonal :" << std::endl;
            std::cin >> L_2;
            if (check(L_1, L_2) == true) {
                std::cout << "tuple or class" << std::endl;
                std::cin >> s;
                if (s == "tuple") {
                    std::tuple<point>  rhombus(make_pair(x1, y1));
                    information2(rhombus, L_1, L_2);
                } else if (s == "class") {
                    Rhombus <double> rhombus(x1, y1, L_1, L_2);
                    information2(rhombus);
                }
            }
        } else if(data == "t") {
            double x1, y1, L_1, L_2, L_3;
            std::cout << "One point of bigger base :" << std::endl;
            std::cin >> x1 >> y1;
            std::cout << "Length of bigger base :" << std::endl;
            std::cin >> L_1;
            std::cout << "Length of smaller base :" << std::endl;
            std::cin >> L_2;
            std::cout << "Length of side :" << std::endl;
            std::cin >> L_3;
            if (check (L_1, L_2, L_3) == true) {
                std::cout << "tuple or class" << std::endl;
                std::cin >> s;
                if (s == "tuple") {
                    std::tuple<point>  trapeze(make_pair(x1, y1));
                    information(trapeze, L_1, L_2, L_3);
                } else if (s == "class") {
                    Trapeze <double> trapeze(x1, y1, L_1, L_2, L_3);
                    information(trapeze);
                }
            }
        } else if (data == "pe") {
            double x1, y1, R;
            std::cout << "Coordinates of center point :" << std::endl;
            std::cin >> x1 >> y1;
            std::cout << "Radius :" << std::endl;
            std::cin >> R;
            if (check(R) == true) {
                std::cout << "tuple or class" << std::endl;
                std::cin >> s;
                if (s == "tuple") {
                    std::tuple<point>  pentagon(make_pair(x1, y1));
                    information3(pentagon, R);
                } else if (s == "class") {
                    Pentagon <double> pentagon(x1, y1, R);
                    information3(pentagon);
                }
            }
        } else if(data == "exit") {
            return 0;
        }
    }
    return 0;
}
