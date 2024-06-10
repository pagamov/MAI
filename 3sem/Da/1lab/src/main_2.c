#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct NODE { //структура для хранения массива значений
    int key;
    char * value;
} NODE;

typedef struct SHINT {
    NODE * array;
    int size;
    int vars;
} SHINT;

SHINT * create_arr (int s) { //создание вектора
    SHINT * arr = (SHINT *)malloc(sizeof(SHINT));
    arr->array = (NODE *)malloc(sizeof(NODE) * s);
    arr->size = s;
    arr->vars = 0;
    return arr;
}

SHINT * resize_arr (SHINT * arr) { //как в стрингах расширение
    if (arr->size == 0)
        arr->size++; //если ноль то 1
    else
        arr->size *= 2;//иначе в 2 раза больше
    arr->array = (NODE *)realloc(arr->array, sizeof(NODE) * arr->size); //расширяем память
    return arr;
}

SHINT * push_arr (SHINT * arr, int key, char * value) {
    if (arr->size == 0 || arr->vars + 1 > arr->size)
        arr = resize_arr(arr);
    arr->array[arr->vars].value = (char *)malloc(sizeof(char) * 2049);
    arr->array[arr->vars].key = key;
    strcpy(arr->array[arr->vars].value, value);
    arr->vars++;
    return arr;
}

void delete_arr (SHINT ** arr) {
    for (int i = 0; i < (*arr)->vars; i++)
        free((*arr)->array[i].value);
    free(((*arr)->array));
    (*arr)->array = NULL;
    free(*arr);
    *arr = NULL;
}

void coppyStr(char * a, char * b) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
}

void swap(NODE * a, NODE * b)
{
    NODE * pivet = (NODE *)malloc(sizeof(NODE));
    pivet->value = (char *)malloc(sizeof(char) * 2049);
    pivet->key = a->key;    coppyStr(pivet->value, a->value);
    a->key = b->key;        coppyStr(a->value, b->value);
    b->key = pivet->key;    coppyStr(b->value, pivet->value);
    free(pivet->value);     free(pivet);
}

void quickSort(SHINT * obj, int left, int right) {
    int i = left, j = right;
    int pivot = obj->array[(left + right) / 2].key;
    while (i <= j) {
        while (obj->array[i].key < pivot)
            i++;
        while (obj->array[j].key > pivot)
            j--;
        if (i <= j) {
            swap(&(obj->array[i]), &(obj->array[j]));
            i++;
            j--;
        }
    }
    if (left < j)   quickSort(obj, left, j);
    if (i < right)  quickSort(obj, i, right);
}

clock_t start, end;
double t;
int main(void) {
    SHINT * arr = create_arr(100);
    int d;
    char * s = (char *)malloc(sizeof(char) * 2049);
    while (scanf("%d\t%s", &d, s) == 2)
        if (d >= 0 && d <= 65535)
            push_arr(arr, d, s);
    free(s);
    start=clock();
    quickSort(arr, 0, arr->vars - 1);
    end=clock();
    t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("add sort: size:  %d\ttime:  %f\n", arr->vars, t);
    delete_arr(&arr);
    return 0;
}
