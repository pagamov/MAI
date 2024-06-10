#ifndef FIGURES_H
#define FIGURES_H
#include <iostream>
#include <tuple>
#include <cmath>


template <class T>
struct Pentagon {
    using type = T;
    using vertex_t = std::pair<T,T>;
    vertex_t a; T R;
    Pentagon(T x1, T y1, T R) : a(x1, y1), R(R)
    {}
};

template <class T>
struct Trapeze {
    using type = T;
    using vertex_t = std::pair<T,T>;
    vertex_t a; T L_1; T L_2; T L_3;
    Trapeze(T x1, T y1, T L_1, T L_2, T L_3 ) : a(x1, y1), L_1(L_1), L_2(L_2), L_3(L_3)
    {}
};

template <class T>
struct Rhombus {
    using type = T;
    using vertex_t = std::pair<T,T>;
    vertex_t a; T L_1; T L_2;
    Rhombus(T x1, T y1, T L_1, T L_2) : a(x1, y1), L_1(L_1), L_2(L_2)
    {}
};

template <class T>
bool check(T R) {
    if(R > 0) {
        return true;
    } else {
        std::cout << "Error" << std::endl;
        return false;
    }
}
template <class T>
bool check(T L_1, T L_2) {
    if(L_1 > 0 && L_2 > 0) {
        return true;
    } else {
        std::cout << "Error" << std::endl;
        return false;
    }
}
template <class T>
bool check(T L_1, T L_2, T L_3) {
    if((L_1 > 0 && L_2 > 0 && L_3 > 0)&&(L_1 != L_2 && L_2 != L_3 && L_1 != L_3)) {
        return true;
    } else {
        std::cout << "Error" << std::endl;
        return false;
    }
}
template <template <class> class F, class T>
typename std::enable_if< std::is_same< F<T>, Trapeze<T> >::value, F<T> >::type information(F<T> t) {
    std::cout << "Trapeze :" << std::endl;
    std::cout << "One point of bigger base (" << t.a.first << "," << t.a.second << ")" << std::endl;
    T sq, x, y;
    x = t.a.first + (t.L_1 * 0.5);
    y = (t.a.second + (t.a.second + sqrt(pow(t.L_3, 2) - (pow(((t.L_1 - t.L_2)* 0.5), 2))))) * 0.5;
    std::cout << "Center point (" << x << "," << y << ")" << std::endl;
    sq = 0.25 * (t.L_1 + t.L_2) * sqrt( 4 * pow(t.L_3, 2) - pow(t.L_1 - t.L_2, 2));
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
        x = t.a.first;
        y = t.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
        x = t.a.first + ((t.L_1 - t.L_2) * 0.5);
        y = t.a.second + sqrt(pow(t.L_3, 2) - (pow((t.L_1 - t.L_2)* 0.5, 2)));
        std::cout << "(" << x << "," << y << ")" << std::endl;
        x = t.a.first + ((t.L_1 + t.L_2) * 0.5);
        y = t.a.second + sqrt(pow(t.L_3, 2) - (pow((t.L_1 - t.L_2) * 0.5, 2)));
        std::cout << "(" << x << "," << y << ")" << std::endl;
        x = t.a.first + t.L_1;
        y = t.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
    return t;
}

template <template <class> class F, class T>
typename std::enable_if< std::is_same< F<T>, Rhombus<T> >::value, F<T> >::type information2(F<T> r) {
    std::cout << "Rhombus :" << std::endl;
    std::cout << "Center point (" << r.a.first << "," << r.a.second << ")" << std::endl;
    T sq,x,y,angle;
    sq = 2 * r.L_1 * r.L_2;;
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
        x = r.a.first - r.L_1;
        y = r.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
        x = r.a.first;
        y = r.a.second - r.L_2;
        std::cout << "(" << x << "," << y << ")" << std::endl;
        x = r.a.first + r.L_2;
        y = r.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
        x = r.a.first;
        y = r.a.second + r.L_2;
        std::cout << "(" << x << "," << y << ")" << std::endl;
    return r;
}

template <template <class> class F, class T>
typename std::enable_if< std::is_same< F<T>, Pentagon<T> >::value, F<T> >::type information3(F<T> pe) {
    std::cout << "Pentagon :" << std::endl;
    std::cout << "Center point (" << pe.a.first << "," << pe.a.second << ")" << std::endl;
    T sq, x, y, angle;
    sq = 5 * sin(2*M_PI / 5) * pe.R * pe.R;
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 5; i++) {
        angle =  2*M_PI * i / 5;
        x = pe.R * cos(angle) + pe.a.first;
        y = pe.R * sin(angle) + pe.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    return pe;
}

template <class T>
void information(std::tuple <std::pair<T,T> > Trapeze, T L_1, T L_2, T L_3) {
    std::cout << "Trapeze :" << std::endl;
    T sq, tx, ty;
    tx = std::get<0>(Trapeze).first + (L_1 * 0.5);
    ty = (std::get<0>(Trapeze).second + (std::get<0>(Trapeze).second + sqrt(pow(L_3, 2) - (pow((L_1 - L_2) * 0.5, 2)))) * 0.5);
    std::cout << "Center point (" << tx << "," << ty << ")" << std::endl;
    sq = 0.5 * (L_1 + L_2) * sqrt(L_3 * L_3 - ((L_1 - L_2) * (L_1 - L_2) * 0.25));
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
    tx = std::get<0>(Trapeze).first;
    ty = std::get<0>(Trapeze).second;
    std::cout << "(" << tx << "," << ty << ")" << std::endl;
    tx = std::get<0>(Trapeze).first + ((L_1 - L_2) * 0.5);
    ty = std::get<0>(Trapeze).second + sqrt(pow(L_3, 2) - (pow((L_1 - L_2)* 0.5, 2)));
    std::cout << "(" << tx << "," << ty << ")" << std::endl;
    tx = std::get<0>(Trapeze).first + ((L_1 + L_2) * 0.5);
    ty = std::get<0>(Trapeze).second + sqrt(pow(L_3, 2) - (pow((L_1 - L_2) * 0.5, 2)));
    std::cout << "(" << tx << "," << ty << ")" << std::endl;
    tx = std::get<0>(Trapeze).first + L_1;
    ty = std::get<0>(Trapeze).second;
    std::cout << "(" << tx << "," << ty << ")" << std::endl;
}

template <class T>
void information2(std::tuple<std::pair<T,T>> Rhombus,T L_1, T L_2) {
    std::cout << "Rhombus :" << std::endl;
    T sq, rx, ry;
    std::cout << "Center point (" << std::get<0>(Rhombus).first << "," << std::get<0>(Rhombus).second << ")" << std::endl;
    sq = 2 * L_1 * L_2;
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
    rx = std::get<0>(Rhombus).first - L_1;
    ry = std::get<0>(Rhombus).second;
    std::cout << "(" << rx << "," << ry << ")" << std::endl;
    rx = std::get<0>(Rhombus).first;
    ry = std::get<0>(Rhombus).second - L_2;
    std::cout << "(" << rx << "," << ry << ")" << std::endl;
    rx = std::get<0>(Rhombus).first + L_2;
    ry = std::get<0>(Rhombus).second;
    std::cout << "(" << rx << "," << ry << ")" << std::endl;
    rx = std::get<0>(Rhombus).first ;
    ry = std::get<0>(Rhombus).second + L_2;
    std::cout << "(" << rx << "," << ry << ")" << std::endl;
}

template <class T>
void information3(std::tuple<std::pair<T,T>> Pentagon,T R) {
    std::cout << "Pentagon :" << std::endl;
    T sq, pex, pey;
    std::cout << "Center point (" << std::get<0>(Pentagon).first << "," << std::get<0>(Pentagon).second << ")" << std::endl;
    sq = 5 * sin(2*M_PI / 5) * R * R;
    std::cout << "Area : " << sq << std::endl;
    T angle;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 5; i++) {
        angle = 2*M_PI * i / 5;
        pex = R * cos(angle) + std::get<0>(Pentagon).first;
        pey = R * sin(angle) + std::get<0>(Pentagon).second;
        std::cout << "(" << pex << "," << pey << ")" << std::endl;
    }
}

#endif
