// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// main.c

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12
#define SUCCESS 0
#define ERROR 1

using namespace std;

void printArr(vector <char> v) {
    for (long unsigned int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
    return;
}

vector <char> strTovec(string number) {
    vector <char> v;
    int flag = 0;
    for (long unsigned int i = 0; i < number.length(); i++) {
        if (number[i] != '0' && flag == 0)
            flag = 1;
        if (number[i] == '0' && flag == 1)
            v.push_back(number[i]);
        else if (number[i] != '0')
            v.push_back(number[i]);
    }
    if (v.size() == 0) {
        v.push_back('0');
    }
    return v;
}

long long hex(char ch) {
    if (ch <= '9' && ch >= '0')
        return (long long)(ch - '0');
    if (ch <= 'f' && ch >= 'a')
        return 10 + (long long)(ch - 'a');
    return 0;
}

char uhex(long long num) {
    if (num >= 0 && num <= 9)
        return (char)('0' + num);
    if (num >= 10 && num <= 15)
        return (char)('a' + (num - 10));
    return '0';
}

vector <char> addHex(vector <char> number1, vector <char> number2) {
    vector <char> v;
    int n1_val, n2_val, balance = 0;
    int n1_pos = number1.size() - 1;
    int n2_pos = number2.size() - 1;
    while (n1_pos >= 0 || n2_pos >= 0) {
        n1_val = n1_pos >= 0 ? hex(number1[n1_pos]) : 0;
        n2_val = n2_pos >= 0 ? hex(number2[n2_pos]) : 0;
        if (n1_val + n2_val + balance > 15) {
            v.insert(v.begin(), (uhex(n1_val + n2_val + balance - 16)));
            balance = 1;
        } else {
            v.insert(v.begin(), (uhex(n1_val + n2_val + balance)));
            balance = 0;
        }
        n1_pos--;
        n2_pos--;
    }
    if (balance)
        v.insert(v.begin(), '1');
    return v;
}

vector <char> del(vector <char> number, long long d) {
    vector <char> v;
    long unsigned int iterator = 0;
    long long piv = 0;
    if (number.size() == 1) {
        v.push_back(uhex(hex(number[iterator]) / d));
        return v;
    }
    while (iterator < number.size() - 1) {
        piv += hex(number[iterator]);
        if (piv / d == 0) {
            piv *= 16;
            iterator++;
        } else {
            v.push_back(uhex(piv / d));
            number[iterator] = uhex(piv % d);
            piv = 0;
        }
    }
    piv += hex(number[iterator]);
    v.push_back(uhex(piv / d));
    return v;
}

typedef struct someArgs_tag {
    vector <char> input1;
    vector <char> input2;
    long long delitel;
    vector <char> output;
} someArgs_t;

void * calculateHex(void *args) {
    someArgs_t *arg = (someArgs_t*) args;
    vector <char> v = addHex(arg->input1, arg->input2);
    arg->output.clear();
    arg->output = v;
    return SUCCESS;
}

void * delCount(void *args) {
    someArgs_t *arg = (someArgs_t*) args;
    vector <char> v = del(arg->input1, arg->delitel);
    arg->output.clear();
    arg->output = v;
    printArr(arg->output);
    printf("good\n");
    return SUCCESS;
}

int main(int argc, char ** argv) {
    int tred;
    clock_t start, stop;
    if (argc != 3) {
        perror("args : size in bytes + file");
        exit(ERROR);
    }
    int NUM_THREADS = atoi(argv[1]);
    ifstream file;
    file.open(argv[2]);
    if (!file.is_open()) {
        perror("cant open file");
        exit(ERROR);
    }

    string str;
    vector <char> v;
    vector <char> res;
    vector <vector <char> > que;
    while (!file.eof()) {
        file >> str;
        if (str != "") {
            v = strTovec(str);
            que.push_back(v);
        }
    }
    file.close();
    que.pop_back();

    std::cout << "size : " << que.size() << '\n';

    if (que.size() == 0) {
        cout << "no numbers" << endl;
        return 0;
    }
    vector <pthread_t> threads(NUM_THREADS);
    vector <someArgs_t> args(NUM_THREADS);
    int i, real = 0, status, status_addr;
    long unsigned int J;
    vector <char> piv;
    long long sizeOfQueue = (long long)que.size();
    start = clock();
    J = 0;
    printf("here\n");
    cout << args.size() << endl;
    while (J != que.size()) {
        for (i = 0; i < NUM_THREADS; i++) {
            if (que.size() > 0) {
                args[i].input1.clear();
                args[i].input1 = que[0];
                que.erase(que.begin());
                args[i].delitel = sizeOfQueue;
                real++;
                J++;
            }
        }
        printf("input\n");
        tred = real;
        for (i = 0; i < tred; i++) {
            status = pthread_create(&threads[i], NULL, delCount, (void*) &args[i]);
            if (status != 0) {
                printf("main error: can't create thread, status = %d\n", status);
                exit(ERROR_CREATE_THREAD);
            }
        }
        printf("create\n");
        cout << args[0].delitel << endl;
        for (i = 0; i < tred; i++) {
            status = pthread_join(threads[i], (void**) &status_addr);
            if (status != SUCCESS) {
                printf("main error: can't join thread, status = %d\n", status);
                exit(ERROR_JOIN_THREAD);
            }
        }
        printf("res\n");
        cout << args[0].delitel << endl;
        sleep(1);
        printf("join\n");
        cout << "tred : " <<  tred << endl;
        for (i = 0; i < tred; i++) {
            printf("aaaaaa\n");
            piv = args[i].output;
            printf("eaquele\n");
            printArr(piv); // wonna know why
            que.push_back(piv);
        }
        printf("end\n");
        real = 0;

    }
    std::cout << "now summ" << '\n';
    while (que.size() > 1) {
        for (i = 0; i < NUM_THREADS; i++) {
            if (que.size() >= 2) {
                args[i].input1.clear();     args[i].input2.clear();
                args[i].input1 = que[0];    que.erase(que.begin());
                args[i].input2 = que[0];    que.erase(que.begin());
                real++;
            }
        }
        tred = real;
        for (i = 0; i < tred; i++) {
            status = pthread_create(&threads[i], NULL, calculateHex, (void*) &args[i]);
            if (status != 0) {
                printf("main error: can't create thread, status = %d\n", status);
                exit(ERROR_CREATE_THREAD);
            }
        }
        for (i = 0; i < tred; i++) {
            status = pthread_join(threads[i], (void**) &status_addr);
            if (status != SUCCESS) {
                printf("main error: can't join thread, status = %d\n", status);
                exit(ERROR_JOIN_THREAD);
            }
        }
        for (i = 0; i < tred; i++) {
            piv = args[i].output;

            que.push_back(piv);
        }
        real = 0;
    }
    stop = clock();
    cout << "done in : " << ((float)(stop - start)) / CLOCKS_PER_SEC << " sec" << endl;
    cout << "res number : ";
    printArr(que[0]);
    return 0;
}
