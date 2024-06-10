#include <iostream>
#include <time.h>
#include <map>
#include <string>

char toolover(char a) {
    return a >= 'A' && a <= 'Z' ? a + ('a' - 'A') : a;
}

std::string regDown(std::string str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toolover(str[i]);
        i++;
    }
    return str;
}

using namespace std;

int main(int argc, char ** argv) {
    clock_t start, end;
    start = clock();
    long test_col;

    cin >> test_col;

    string input;
    unsigned long long number;
    map <string, unsigned long long> tree;

    while (cin >> input) {
        if (strcmp(input.c_str(), "+\0") == 0) {
            cin >> input >> number;
            input = regDown(input);
            if (tree.find(input) == tree.end()) {
                // printf("Exist\n");
            } else {
                tree[input] = number;
                // printf("OK\n");
            }
        } else if (strcmp(input.c_str(), "-\0") == 0) {
            cin >> input;
            input = regDown(input);
            if (tree.find(input) != tree.end()) {
                tree.erase(input);
                // printf("OK\n");
            } else {
                // printf("NoSuchWord\n");
            }
        } else {
            input = regDown(input);
            if (tree.find(input) == tree.end()) {
                // printf("NoSuchWord\n");
            } else {
                cout << tree[input];
                // printf("OK:\t%llu\n", pivet->value);
            }
        }
    }
    end = clock();
    double t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("size:  %ld\t\ttime:  %f\n", test_col, t);
    return 0;
}
