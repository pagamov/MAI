/*
Cтудент Гамов Павел. Лабораторная работа №7.
Задание:
Спроектировать простейший графический векторный редактор.
Требование к функционалу редактора:
    • создание нового документа
    • импорт документа из файла
    • экспорт документа в файл
    • создание графического примитива (согласно варианту задания)
    • удаление графического примитива
    • отображение документа на экране (печать перечня графических объектов и их характеристик)
    • реализовать операцию undo, отменяющую последнее сделанное действие. Должно действовать для операций добавления/удаления фигур.
Требования к реализации:
    • Создание графических примитивов необходимо вынести в отдельный класс – Factory.
    • Сделать упор на использовании полиморфизма при работе с фигурами;
    • Взаимодействие с пользователем (ввод команд) реализовать в функции main;
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
const double PI = 3.1415926535;

void wrong() {
    cout << "Wrong format!!\n";
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
        file << "p" << "\t" <<  this->c_x[1] << "\t" << this->c_y[1] << "\t";
        CheckWrongs(file);
    }
    ~Pentagon() = default;
};

template <class T>
void show_info(vector <Figure <T>*> &a) {
    for (unsigned int i = 0; i < a.size(); i++) {
        a[i]->get_info();
    }
}

template <class T>
struct Node_del {
    Figure <T> * ptr;
    int index;
};

template <class T>
void delete_fig(vector <Figure <T>*> &a, unsigned int j) {
    delete a[j];
    for (unsigned int i = j; i < a.size() - 1; i++) {
        a[i] = a[i + 1];
    }
    a[a.size() - 1] = nullptr;
    a.pop_back();
}

void create_doc(string filename) {
    ofstream out(filename, ios::trunc);
    if (!out.is_open()) {
        puts("error_open");
        exit(-1);
    }
}

template <class T>
void export_doc(string filename, vector <Figure <T>*> &a) {
    ofstream out(filename, ios::trunc);
    if (!out.is_open()) {
        puts("error_open");
        exit(-1);
    }
    for (unsigned int i = 0; i < a.size(); i++) {
        a[i]->write_file(out);
    }
    out << "S";
    CheckWrongs(out);
}

template <class T>
class Factory {
public:
    stack <char> commands;
    stack <Node_del<T>> deletes;
    Figure <T>* add_figure(T c, T x1, T y1, T x2, T y2) {
        commands.push('a');
        Trap <T>* b = new Trap <T>(c, x1, y1, x2, y2);
        return b;
    }
    Figure <T>* add_figure(T x1, T y1, T x2, T y2) {
        commands.push('a');
        Romb <T>* b = new Romb <T>(x1, y1, x2, y2);
        return b;
    }
    Figure <T>* add_figure(T c, T x1, T y1) {
        commands.push('a');
        Pentagon <T>* b = new Pentagon <T>(c, x1, y1);
        return b;
    }
    void undo(vector <Figure <T>*> &a) {
        if (commands.empty()) {
            return;
        }
        if (commands.top() == 'a')
            delete_fig(a, a.size() - 1);
        if (commands.top() == 'd') {
            Node_del <T> node_del = deletes.top();
            a.insert(a.begin() + node_del.index, node_del.ptr);
            deletes.pop();
        }
        commands.pop();
    }
    ~Factory() {
        while (!deletes.empty()) {
            delete (deletes.top().ptr);
            deletes.pop();
        }
    }
};

template <class T>
void import_doc(string filename, vector <Figure <T>*> &a, Factory <T> &fac) {
    while(!fac.commands.empty())
        fac.commands.pop();
    while (!fac.deletes.empty()) {
        delete (fac.deletes.top().ptr);
        fac.deletes.pop();
    }
    while (a.size() > 0) {
        delete_fig(a, 0);
    }
    T c; T x1; T y1; T x2; T y2;
    char type;
    ifstream out(filename);
    if (!out.is_open()) {
        puts("error_open");
        exit(-1);
    }
    while (true) {
        out >> type;
        CheckWrongs(out);
        if (type == 't') {
            out >> c >> x1 >> y1 >> x2 >> y2;
            CheckWrongs(out);
            a.push_back(new Trap <T>(c, x1, y1, x2, y2));
        }
        if (type == 'r') {
            out >> x1 >> y1 >> x2 >> y2;
            CheckWrongs(out);
            a.push_back(new Romb <T>(x1, y1, x2, y2));
        }
        if (type == 'p') {
            out >> c >> x1 >> y1;
            CheckWrongs(out);
            a.push_back(new Pentagon <T>(c, x1, y1));
        }
        if (type == 'N') {
            a.push_back(new Pentagon <T>(0, 0, 0));
        }
        if (type == 'S') {
            break;
        }
    }
}

template <class T>
void delete_fig_plus(vector <Figure <T>*> &a, unsigned int j, Factory <T> &fac) {
    fac.commands.push('d');
    Node_del <T> node;
    node.ptr = a[j];
    node.index = j;
    fac.deletes.push(node);
    for (unsigned int i = j; i < a.size() - 1; i++) {
        a[i] = a[i + 1];
    }
    a[a.size() - 1] = nullptr;
    a.pop_back();
}

typedef int use_type;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Студент Гамов Павел.\nЛабораторная работа №7\n";
    cout << "\nПрограмма:\n	't' + arguments (длина основания и вектор боковой стороны соотвественно) - создать фигуру 'трапеция';\n	'r' + arguments (вектор одной стороны) - создать фигуру 'ромб';\n	'p' + arguments (длина основания и его единственная точка) - создать фигуру 'пятиугольник';\n	'i' - вывести все добавление фигуры;\n	'd' + arguments (номер элемента) - удалить ранее созданную фигуру;\n	'u' - отменить предыдущее действие\n	'e' + 'filename' - экспортировать в файл именем filename текущую работу\n\t'g' + 'filename' - импортировать из файла именем filename сохраненную работу\t\n\t's' - завершить программу;\n";
    vector <Figure <use_type>*> vec;
    Factory <use_type> fac;
    use_type x1, x2, y1, y2, c;
    string filename;
    unsigned int j;
    char ch;
    while (true) {
        cin >> ch;
        if (ch == 't') {
            cin >> c >> x1 >> y1 >> x2 >> y2;
            vec.push_back(fac.add_figure(c, x1, y1, x2, y2));
        }
        else if (ch == 'r') {
            cin >> x1 >> y1 >> x2 >> y2;
            vec.push_back(fac.add_figure(x1, y1, x2, y2));
        }
        else if (ch == 'p') {
            cin >> c >> x1 >> y1;
            vec.push_back(fac.add_figure(c, x1, y1));
        }
        else if (ch == 'd') {
            cin >> j;
            j--;
            if (j >= 0 && j < vec.size()) {
                delete_fig_plus(vec, j, fac);
            }
            else {
                wrong();
            }
        }
        else if (ch == 'i') {
            show_info(vec);
        }
        else if (ch == 'u') {
            fac.undo(vec);
        }
        else if (ch == 'c') {
            cin >> filename;
            create_doc(filename);
        }
        else if (ch == 'e') {
            cin >> filename;
            export_doc(filename, vec);
        }
        else if (ch == 'g') {
            cin >> filename;
            import_doc(filename, vec, fac);
        }
        else if (ch == 's') {
            while (vec.size() > 0) {
                delete_fig(vec, 0);
            }
            break;
        }
        else {
            wrong();
        }
    }
    return 0;
}
