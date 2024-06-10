/*
Гамов Павел Антонович м80-207-б-18
Создать шаблон динамической коллекцию, согласно варианту задания:
1. Коллекция должна быть реализована с помощью умных указателей (std::shared_ptr, std::weak_ptr). Опционально использование std::unique_ptr;
2. В качестве параметра шаблона коллекция должна принимать тип данных;
3. Коллекция должна содержать метод доступа:
Стек – pop, push, top;
Очередь – pop, push, top;
Список, Динамический массив – доступ к элементу по оператору [];
4. Реализовать аллокатор, который выделяет фиксированный размер памяти (количество блоков памяти – является параметром шаблона аллокатора). Внутри аллокатор должен хранить указатель на используемый блок памяти и динамическую коллекцию указателей на свободные блоки. Динамическая коллекция должна соответствовать варианту задания (Динамический массив, Список, Стек, Очередь);
5. Коллекция должна использовать аллокатор для выделеления и освобождения памяти для своих элементов.
6. Аллокатор должен быть совместим с контейнерами std::map и std::list (опционально – vector).
7. Реализовать программу, которая:
Позволяет вводить с клавиатуры фигуры (с типом int в качестве параметра шаблона фигуры) и добавлять в коллекцию использующую аллокатор;
Позволяет удалять элемент из коллекции по номеру элемента;
Выводит на экран введенные фигуры c помощью std::for_each;

Задание: вариант 4 – реализовать стек трапеций с аллокатором в виде очереди.
*/
#include<iostream>
#include<algorithm>
#include<locale.h>
#include "Trapeze.hpp"
#include "Stack.hpp"
#include "Allocator.hpp"

void Menu1() {
	std::cout << "1. Добавить фигуру в стек\n";
	std::cout << "2. Удалить фигуру\n";
	std::cout << "3. Вывести фигуру\n";
	std::cout << "4. Вывести все фигуры\n";
	std::cout << "5. Добавить фигуру по индексу\n";
}

void DeleteMenu() {
	std::cout << "1. Удалить фигуру в вершине стека\n";
	std::cout << "2. Удалить фигуру по индексу\n";
}

void PrintMenu() {
	std::cout << "1. Вывести первую фигуру в стеке\n";
	std::cout << "2. Вывести последнюю фигуру в стеке\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	containers::Stack<Trapeze<int>, allocators::my_allocator<Trapeze<int>, 1000>> Mystack;

	Trapeze<int> TempTrapeze;

	while (true) {
		Menu1();
		int n, m, in;
		size_t ind;
		double s;
		std::cin >> n;
		switch (n) {
		case 1:
			TempTrapeze.Read(std::cin);
			TempTrapeze.Print(std::cout);
			Mystack.push(TempTrapeze);
			break;
		case 2:
			DeleteMenu();
			std::cin >> m;
			switch (m) {
				case 1:
					Mystack.pop();
					break;
				case 2:
					std::cin >> ind;
					Mystack.delete_by_index(ind);
					break;
				default:
					break;
			}
			break;
		case 3:
			PrintMenu();
			std::cin >> m;
			switch (m) {
				case 1:
					Mystack.bottom().Print(std::cout);
					std::cout << std::endl;
					break;
				case 2:
					Mystack.top().Print(std::cout);
					std::cout << std::endl;
					break;
				default:
					break;
			}
			break;
		case 4:
			std::for_each(Mystack.begin(), Mystack.end(), [](Trapeze<int>& X) { X.Print(std::cout); std::cout << std::endl; });
			break;
		case 5:
			std::cout << "Введите индекс\n";
			std::cin >> ind;
			std::cout << "Введите координаты трапеции\n";
			TempTrapeze.Read(std::cin);
			Mystack.insert_by_index(ind, TempTrapeze);
			break;
		default:
			return 0;
		}
	}
	system("pause");
	return 0;
}
