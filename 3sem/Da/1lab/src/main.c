#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct STRING { //структура для хранения массива значений
    char ** array;
    int size;
    int vars;
} STRING;

STRING * create_str (int s) { //функция создания вектора значений
    STRING * string = (STRING *)malloc(sizeof(STRING));
    string->array = (char **)malloc(sizeof(char *) * s); //выделяем нужный размер
    for (int i = 0; i < s; i++)
        string->array[i] = (char*)malloc(sizeof(char) * 2049); //каждая строка по 2049 чаров
    string->size = s; //размер вектора
    string->vars = 0; //сколько реально занято
    return string;
}

STRING * resize_str (STRING * string) { //в случае переполнеия при добавлении вызывается она
    if (string->size == 0) {  string->size++; } //если размер 0 то размер 1
    else  {  string->size *= 2;  } //иначе размер в 2 раза больше
    string->array = (char **)realloc(string->array, sizeof(char *) * string->size); //расширение вектора
    return string;
}

STRING * push_str (STRING * string, char * value) { //пушим значение
    if (string->size == 0 || string->vars + 1 > string->size)
        string = resize_str(string); //если размер не помещается то изменяем размер
    string->array[string->vars] = (char *)malloc(sizeof(char) * 2049); //новый стринг
    strcpy(string->array[string->vars], value); //помещаем значение
    string->vars++; //увеличиваем размер
    return string;
}

void delete_str (STRING ** string) { //удаление памяти под вектор
    for (int i = 0; i < (*string)->vars; i++)
        free((*string)->array[i]); //удаляем каждый стринг
    free(((*string)->array)); //чистим чистим чистим
    free((*string)); //ну и снова чистим чтоб валгринг не ругался
    (*string) = NULL;
}

typedef struct SHINT { //стракт под ключи
    int * array;
    int size; //размер вектора
    int vars; //реально занято
} SHINT;

SHINT * create_arr (int s) { //создание вектора
    SHINT * arr = (SHINT *)malloc(sizeof(SHINT));
    arr->array = (int *)malloc(sizeof(int) * s);
    arr->size = s;
    arr->vars = 0;
    return arr;
}

SHINT * resize_arr (SHINT * arr) { //как в стрингах расширение
    if (arr->size == 0) {  arr->size++; } //если ноль то 1
    else  {  arr->size *= 2;  } //иначе в 2 раза больше
    arr->array = (int *)realloc(arr->array, sizeof(int) * arr->size); //расширяем память
    return arr;
}

SHINT * push_arr (SHINT * arr, int value) { //пушим значение
    if (arr->size == 0 || arr->vars + 1 > arr->size)
        arr = resize_arr(arr); //если переполнение и нет места
    arr->array[arr->vars] = value; //присвоение нового значения
    arr->vars++; //инкремент
    return arr;
}

void delete_arr (SHINT ** arr) { //удаление ветора ключей
    free(((*arr)->array)); //удаление внутреннего массива интов
    (*arr)->array = NULL; //обнуление указателя
    free(*arr); // удаление вектора
    *arr = NULL; //обнуление указателя на вектор
}

void stableString(SHINT * v, STRING * s) {
    int max = 65536; //верхняя граница при подсчете
    SHINT * c = create_arr(0); //доп вектор под кол-во элементов
    SHINT * b = create_arr(0); //доп вектор под ключи
    STRING * bb = create_str(0); //доп вектор под значения
    for (int i = 0; i < max; i++)
        push_arr(c, 0); //заполняем нулями
    for (int i = 0; i < v->vars; i++) {
        c->array[v->array[i]] += 1; //инкремет соответствующих элементов
        push_arr(b, 0); //пушим нули в доп векторы
        push_str(bb, ""); //пушим пустые строки в вектор доп строк
    }
    for (int i = 1; i < max; i++)
        c->array[i] = c->array[i] + c->array[i - 1]; /*алгоритм для стабильной подсчетом подразумевает такую операцию
                                                       к елементу i прибавляем значение i - 1*/
    for (int i = v->vars - 1; i > -1; i--) { //слева направо идем и присваиваем значения доп векторов копируя из основных в доп веторы
        c->array[v->array[i]] = c->array[v->array[i]] - 1; //декримент массива подсчета
        b->array[c->array[v->array[i]]] = v->array[i]; //доп вектор ключей получает значение от основного вектора
        strcpy(bb->array[c->array[v->array[i]]], s->array[i]); //доп вектор значений получает значение от основного вектора
    }
    for (int i = 0; i < v->vars; i++) { //в цикле копируем из дополнительных вектором в основные
        v->array[i] = b->array[i];
        strcpy(s->array[i], bb->array[i]);
    }
    delete_arr(&c); //удаляем доп векторы
    delete_arr(&b);
    delete_str(&bb);
}

clock_t start, end;
double t;

int main(void) {
    SHINT * arr = create_arr(0); //вектор ключей
    STRING * string = create_str(0); //вектор значений
    int d; //какая та переменная что ты тут забыла
    char * s = (char *)malloc(sizeof(char) * 2049); //строка для считывания вход данных
    while (scanf("%d\t%s", &d, s) == 2) { //если ввод хороший то далее
        if (d >= 0 && d <= 65535) { //ранжирование по беззнаковому шорт инту
            push_arr(arr, d); //пушим пушим
            push_str(string, s); //пушим пушим
        }
    }
    free(s);
    start=clock();
    stableString(arr, string);
    end=clock();
    t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("main sort: size:  %d\ttime:  %f\t\t", arr->vars, t);
    delete_arr(&arr); //удаление вектора ключей
    delete_str(&string); //удаление вектора значений
    return 0;
}
