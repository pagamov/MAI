/*
Студент Гамов Павел. Лабораторная №8.
Создать приложение, которое будет считывать из стандартного ввода данные фигур, согласно варианту
задания, выводить их характеристики на экран и записывать в файл. Фигуры могут задаваться как своими
вершинами, так и другими характеристиками (например, координата центра, количество точек и радиус).
Программа должна:
1. Осуществлять ввод из стандартного ввода данных фигур, согласно варианту задания;
2. Программа должна создавать классы, соответствующие введенным данных фигур;
3. Программа должна содержать внутренний буфер, в который помещаются фигуры. Для создания
буфера допускается использовать стандартные контейнеры STL. Размер буфера задается параметром
командной строки. Например, для буфера размером 10 фигур: oop_exercise_08 10
4. При накоплении буфера они должны запускаться на асинхронную обработку, после чего буфер
должен очищаться;
5. Обработка должна производиться в отдельном потоке;
6. Реализовать два обработчика, которые должны обрабатывать данные буфера:
    a. Вывод информации о фигурах в буфере на экран;
    b. Вывод информации о фигурах в буфере в файл. Для каждого буфера должен создаваться файл с уникальным именем.
7. Оба обработчика должны обрабатывать каждый введенный буфер. Т.е. после каждого заполнения
буфера его содержимое должно выводиться как на экран, так и в файл.
8. В программе должно быть ровно два потока (thread). Один основной (main) и второй для
обработчиков;
9. В программе должен явно прослеживаться шаблон Publish-Subscribe. Каждый обработчик должен
быть реализован как отдельный подписчик.
10. Реализовать в основном потоке (main) ожидание обработки буфера в потоке-обработчике. Т.е. после
отправки буфера на обработку основной поток должен ждать, пока поток обработчик выведет данные
на экран и запишет в файл.
Вариант 4 - трапеция, ромб, пятиугольник.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <thread>
#include <fstream>
#include <future>
#include <chrono>
using namespace std;
const double PI = 3.1415926535;

void wrong() {
    cout << "Wrong format!!\nPlease try again:\n";
}

void CheckWrongs(ofstream &f1) {
    if (f1.fail()) {
        puts("ERROR");
        puts("The read type does not match the specidied");
        exit(-2);
    }
    if (f1.bad()) {
        puts("ERROR");
        puts("Bad file formatting");
    }
}

template <class T>
class Figure {
protected:
    vector <T> c_x;
    vector <T> c_y;
    int n_size;
    bool exist;
public:
    Figure() {
        n_size = 0;
        exist = 0;
    }
    void d_exist() {
        cout << "'Figure dosent exist'\n";
    }
    void add_point(T x1, T y1) {
        c_x.push_back(x1);
        c_y.push_back(y1);
        n_size++;
    }
    virtual T get_square() = 0;
    void get_info() {
        if (!exist) {
            d_exist();
            return;
        }
        vector <T> out = center();
        cout << "{ ";
        for (int i = 0; i < n_size; i++) {
            cout << "(" << c_x[i] << ", " << c_y[i] << ") ";
        }
        cout << "}; ";
        cout << "S = " << get_square();
        cout << "; Geom Center: (" << out[0] << ", " << out[1] << ")\n";
    }
    vector <T> center() {
        vector <T> out(2);
        T S1, S2;
        S1 = 0;
        S2 = 0;
        for (int i = 0; i < n_size; i++) {
            S1 += c_x[i];
            S2 += c_y[i];
        }
        out[0] = S1 / n_size;
        out[1] = S2 / n_size;
        return out;
    }
    virtual void write_file(ofstream &file) = 0;
    virtual ~Figure() = default;
};

template <class T>
class Trap : public Figure <T> {
protected:
    T b;
    T a;
    T l;
    T h;
public:
    Trap(T c, T x1, T y1, T x2, T y2)
    {
        if (c == 0 || (x1 == x2 && y1 == y2)) {
            return;
        }
        if (x2 - x1 <= -c) {
            return;
        }
        a = c;
        b = c + 2 * (x2 - x1);
        h = abs(y2 - y1);
        l = (T)sqrt(pow(x2 - x1, 2) + pow(h, 2));
        if (h == 0 || l == 0 || a == 0 || b == 0) {
            return;
        }
        this->exist = 1;
        this->add_point(x1, y1);
        this->add_point(x2, y2);
        this->add_point(x1 + b, y1);
        this->add_point(x2 + a, y2);
    }
    T get_square() {
        return (a + b) / 2 * h;
    }
    void write_file(ofstream &file) {
        if (!this->exist) {
            file << "N" << "\t";
            CheckWrongs(file);
            return;
        }
        file << "t" << "\t" << a << "\t" << this->c_x[0] << "\t" << this->c_y[0] << "\t" << this->c_x[1] << "\t" << this->c_y[1] << "\t";
        CheckWrongs(file);
    }
    ~Trap() = default;
};

template <class T>
class Romb : public Figure <T> {
protected:
    T a;
    T h;
public:
    Romb(T x1, T y1, T x2, T y2) {
        if (x1 == x2 && y1 == y2) {
            return;
        }
        a = (T)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        h = abs(y2 - y1);
        if (a == 0 || h == 0) {
            return;
        }
        this->exist = 1;
        this->add_point(x1, y1);
        this->add_point(x2, y2);
        this->add_point(x2 + a, y2);
        this->add_point(x1 + a, y1);
    }
    T get_square() {
        return a * h;
    }
    void write_file(ofstream &file) {
        if (!this->exist) {
            file << "N" << "\t";
            CheckWrongs(file);
            return;
        }
        file << "r" << "\t" << this->c_x[0] << "\t" << this->c_y[0] << "\t" << this->c_x[1] << "\t" << this->c_y[1] << "\t";
        CheckWrongs(file);
    }
    ~Romb() = default;
};

template <class T>
class Pentagon : public Trap <T> {
protected:
    T a;
public:
    Pentagon(T c, T x1, T y1) : Trap <T>(c, x1 - c * (T)cos(2 * PI / 5), y1 + c * (T)sin(2 * PI / 5), x1, y1)
    {
        if (!this->exist) {
            return;
        }
        a = c;
        this->add_point(this->c_x[0] + c * (T)cos(PI / 5), this->c_y[2] + c * (T)sin(PI / 5));
    }
    T get_square() {
        return (T)(5 / 4 * pow(a, 2) / tan(PI / 5));
    }
    void write_file(ofstream &file) {
        if (!this->exist) {
            file << "N" << "\t";
            CheckWrongs(file);
            return;
        }
        file << "p" << "\t" << a << "\t" << this->c_x[1] << "\t" << this->c_y[1] << "\t";
        CheckWrongs(file);
    }
    ~Pentagon() = default;
};

template <class T>
void add_figure(vector <Figure <T>*> &a, T c, T x1, T y1, T x2, T y2) {
    Trap <T>* b = new Trap <T>(c, x1, y1, x2, y2);
    a.push_back(b);
}

template <class T>
void add_figure(vector <Figure <T>*> &a, T x1, T y1, T x2, T y2) {
    Romb <T>* b = new Romb <T>(x1, y1, x2, y2);
    a.push_back(b);
}

template <class T>
void add_figure(vector <Figure <T>*> &a, T c, T x1, T y1) {
    Pentagon <T>* b = new Pentagon <T>(c, x1, y1);
    a.push_back(b);
}

template <class T>
void show_info(vector <Figure <T>*> &a) {
    for (unsigned int i = 0; i < a.size(); i++) { a[i]->get_info(); }
}

template <class T>
T median_square(vector <Figure <T>*> &a) {
    T S = 0;
    for (unsigned int i = 0; i < a.size(); i++) { S += a[i]->get_square(); }
    return S;
}

template <class T>
void delete_fig(vector <Figure <T>*> &a, unsigned int j) {
    delete a[j];
    for (unsigned int i = j; i < a.size() - 1; i++) { a[i] = a[i + 1]; }
    a[a.size() - 1] = nullptr;
    a.pop_back();
}

template <class T>
void all_delete(vector <Figure <T>*> &a) {
    while (a.size() > 0) { delete_fig(a, 0); }
}

template <class T>
bool treat(vector <Figure <T>*> &a, string filename) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50*a.size()));
    show_info(a);
    ofstream out(filename, ios::trunc);
    if (!out.is_open()) {
        puts("error_open");
        exit(-1);
    }
    for (unsigned int i = 0; i < a.size(); i++) { a[i]->write_file(out); }
    out << "S";
    CheckWrongs(out);
    all_delete(a);
    return true;
}

typedef double use_type;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Студент Гамов Павел.\nЛабораторная работа №8\n";
    cout << "\nПрограмма:\n\t'name' + 'size' - создать буфер с именем name и размером size.\n\t't' + arguments (длина основания и вектор боковой стороны соотвественно) - создать фигуру 'трапеция' и добавить ее в буфер;\n	'r' + arguments (вектор одной стороны) - создать фигуру 'ромб' и добавить ее в буфер;\n	'p' + arguments (длина основания и его единственная точка) - создать фигуру 'пятиугольник' и добавить ее в буфер;\n	'!stop' - завершить программу;\n";
    vector <Figure <use_type>*> vec;
    use_type x1, x2, y1, y2, c;
    size_t size;
    string name;
    char ch;
    while (true) {
        cin >> name;
        if (name == "!stop") { return 0; }
        cin >> size;
        while (true) {
            if (size == vec.size()) { break; }
            cin >> ch;
            if (ch == 't') {
                cin >> c >> x1 >> y1 >> x2 >> y2;
                add_figure(vec, c, x1, y1, x2, y2);
            } else if (ch == 'r') {
                cin >> x1 >> y1 >> x2 >> y2;
                add_figure(vec, x1, y1, x2, y2);
            } else if (ch == 'p') {
                cin >> c >> x1 >> y1;
                add_figure(vec, c, x1, y1);
            } else { wrong(); }
        }
        future <bool> fut = async([&] { return treat(vec, name); });
        cout << "loading...\n";
        fut.wait();
    }
    return 0;
}
