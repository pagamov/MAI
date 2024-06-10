//
//
// Гамов Павел
// Группа 207
//
// main.cpp

#include <iostream>
#include "class.hpp"

using namespace std;

int main() {
    string in{"___"};
    int index;
    float fullS, S;
    vector <Figure *> figures;
    while (in != "exit") {
        cin >> in;
        if (in == "add") {
            cout << "enter numbers : ";
            cin >> in;
            Figure * fig = new Figure(recive(in));
            figures.push_back(fig);
        } else if (in == "print") {
            cin >> in;
            fullS = 0;
            if (in == "all") {
                cout << endl;
                for (int i = 0; i < figures.size(); i++) {
                    cout << "index : " << i << endl;
                    S = figures[i]->gaussS();
                    cout << "S : " << S << endl;
                    figures[i]->geomCenter();
                    figures[i]->print();
                    fullS += S;
                }
                cout << "full S : " << fullS << endl;
            } else {
                cout << endl;
                for (int i = 0; i < figures.size(); i++) {
                    if (figures[i]->status == in) {
                        S = figures[i]->gaussS();
                        cout << "S : " << S << endl;
                        figures[i]->geomCenter();
                        figures[i]->print();
                        fullS += S;
                    }
                }
                cout << "full S : " << fullS << endl;
            }
        } else if (in == "exit") {
            return 0;
        } else if (in == "delete") {
            cin >> index;
            if (index < figures.size() && index >= 0) {
                delete figures[index];
                figures.erase(figures.begin() + index);
            } else {
                cout << "wring index" << endl;
            }
        }
    }
    return 0;
}
