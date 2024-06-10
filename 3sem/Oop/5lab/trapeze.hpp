#ifndef TRAPEZE_H
#define TRAPEZE_H

#include <iostream>
#include "point.hpp"
#include <cmath>

template <class T>
class Trapeze {
public:
    point <T> A , B, C, D;

    explicit Trapeze<T>(std::istream& is) {
        is >> A >> B >> C >> D;
        double AB, CB, DC, AD;
        AB = sqrt(pow((B.x-A.x),2) + pow((B.y-A.y),2));
        CB = sqrt(pow((C.x-B.x),2) + pow((C.y-B.y),2));
        DC = sqrt(pow((D.x-C.x),2) + pow((D.y-C.y),2));
        AD = sqrt(pow((A.x-D.x),2) + pow((A.y-D.y),2));
        if ((( AB!= DC) && (((D.x - A.x)/AD) != ((C.x - B.x)/CB))) && ((CB != AD)&&(((C.x - D.x)/DC) != ((B.x - A.x)/AB))) && ((AB != DC) && (CB != AD))) {
                throw std::logic_error("It`s not a trapeze");
        }
    }

    Trapeze <T>() = default;

    double Area() {
        double AB, AD, BD, DC, CB, p1, S1, p2, S2;
        AB = sqrt(pow((B.x-A.x),2) + pow((B.y-A.y),2));
        AD = sqrt(pow((D.x-A.x),2) + pow((D.y-A.y),2));
        BD = sqrt(pow((D.x-B.x),2) + pow((D.y-B.y),2));
        CB = sqrt(pow((C.x-B.x),2) + pow((C.y-B.y),2));
        DC = sqrt(pow((D.x-C.x),2) + pow((D.y-C.y),2));
        p1 = 0.5 * (AB+AD+BD);
        p2 = 0.5 * (CB+DC+BD);
        S1 = sqrt(p1*(p1-AB)*(p1-AD)*(p1-BD));
        S2 = sqrt(p2*(p2-CB)*(p2-DC)*(p2-BD));
        return S1+S2;
    }

    void Print(std::ostream& os) { os << A << " " << B << " " << C << " " << D << std::endl; }

    void operator<< (std::ostream& os) { os << A << " " << B << " " << C << " " << D; }
};

#endif
