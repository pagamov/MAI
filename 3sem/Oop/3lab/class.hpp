//
//
// Гамов Павел
// Группа 207
//
// class.hpp

#ifndef Figures_hpp
#define Figures_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Figure {
public:
    vector <float> X;
    vector <float> Y;
    int size;
    string status;

    Figure(vector <float> in) {
        int size_ = in.size() % 2 == 0 ? in.size() / 2 : (in.size() - 1) / 2;
        size = size_;
        for (int i = 0; i < size * 2; i++) {
            if (i % 2 == 0)
                X.push_back(in[i]);
            else if (i % 2 == 1)
                Y.push_back(in[i]);
        }
        if (this->isRomb())         status = "romb";
        else if (this->isTrap())    status = "trap";
        else if (size == 5)         status = "five";
        else                        status = "figure";

    }

    void geomCenter() {
        if (size == 0) {
            cout << "no dots" << endl;
            return;
        }
        float X_sum = 0, Y_sum = 0;
        int count = 0;
        for (int i = 0; i < size; i++) {
            X_sum += X[i];
            Y_sum += Y[i];
            count++;
        }
        cout << "geom center : x : " << X_sum / count << " y : " << Y_sum / count << endl;
    }

    float gaussS() {
        if (size == 0) {
            cout << "no dots" << endl;
            return 0;
        }
        float l_sum = 0, r_sum = 0, res;
        for (int i = 0; i < size - 1; i++) {
            l_sum += X[i] * Y[i + 1];
            r_sum += Y[i] * X[i + 1];
        }
        l_sum += X[size - 1] * Y[0];
        r_sum += Y[size - 1] * X[0];
        res = (l_sum - r_sum) > 0 ? (l_sum - r_sum) : -1 * (l_sum - r_sum);
        return res / 2;
    }

    void print() {
        cout << "size : " << size << " status : " << status << endl;
        cout << "x : ";
        for (int i = 0; i < X.size(); i++)
            cout << X[i] << " ";
        cout << endl << "y : ";
        for (int i = 0; i < Y.size(); i++)
            cout << Y[i] << " ";
        cout << endl << endl;
    }

    int isTrap() {
        if (size != 4) return 0;
        vector <float> vx;
        vector <float> vy;
        for (int i = 0; i < size - 1; i++) {
            vx.push_back(X[i + 1] - X[i]);
            vy.push_back(Y[i + 1] - Y[i]);
        }
        vx.push_back(X[size - 1] - X[0]);
        vy.push_back(Y[size - 1] - Y[0]);
        int count = 0;
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (vx[i] * vy[j] == vx[j] * vy[i] && j - i != 1)
                    count++;
        if (count == 1)
            return 1;
        return 0;
    }

    int isRomb() {
        if (size != 4) return 0;
        vector <float> vx;
        vector <float> vy;
        for (int i = 0; i < size - 1; i++) {
            vx.push_back(X[i + 1] - X[i]);
            vy.push_back(Y[i + 1] - Y[i]);
        }
        vx.push_back(X[size - 1] - X[0]);
        vy.push_back(Y[size - 1] - Y[0]);
        int count = 0;
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (vx[i] * vy[j] == vx[j] * vy[i] && j - i != 1)
                    count++;
        if (count == 2)
            return 1;
        return 0;
    }

    ~Figure() {

    }
};

class Trap : public Figure {
public:
    Trap(vector <float> in) : Figure (in) {
        if (size >= 4 && this->isTrap()) {
            size = 4;
            status = "trap";
        } else {
            size = 0;
        }
    }

    ~Trap() {

    }
};

class Romb : public Figure {
public:
    Romb(vector <float> in) : Figure (in) {
        if (size >= 4 && this->isRomb()) {
            size = 4;
            status = "romb";
        } else {
            size = 0;
        }
    }

    ~Romb() {

    }
};

class Five : public Figure {
public:
    Five(vector <float> in) : Figure (in) {
        if (size == 5) {
            status = "five";
        } else {
            size = 0;
        }
    }

    ~Five() {

    }
};

int pars(char a) {
    return (int)(a - '0');
}

vector <float> recive(string value) {
    int piv = 0, flag = 0, count = 0, i = 0;
    vector <float> v;
    while (value[i] != '\0') {
        if (value[i] == ' ' || value[i] == ',' || value[i] == ';') {
            if (flag) {
                flag = 0;
                piv *= -1;
            }
            v.push_back(piv);
            count++;
            piv = 0;
        } else if (value[i] >= '0' && value[i] <= '9') {
            piv *= 10;
            piv += pars(value[i]);
        } else if (value[i] == '-') {
            flag = 1;
        }
        i++;
    }
    if (flag) {
        flag = 0;
        piv *= -1;
    }
    v.push_back(piv);
    return v;
}

#endif
