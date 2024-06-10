#ifndef FazzyNumbers_hpp
#define FazzyNumbers_hpp

#include "math.h"

template <class T> class FazzyNumbers {
private:
  T x;
  T el;
  T er;

  T getEps() {
    T eps = 1;
    while (eps + 1 != 1)
      eps /= 2;
    return eps;
  }

  int isZero(T target) {
    if (fabs(target - 0) < getEps()) {
      return 0;
    }
    return 1;
  }

public:
  FazzyNumbers(T x, T e1, T er) {
    this->x = x;
    this->el = x - e1;
    this->er = x + er;
  }

  FazzyNumbers(T x, T e) {
    this->x = x;
    this->el = x - e;
    this->er = x + e;
  }

  void printNumber() {
    std::cout << this->el << " " << this->x << " " << this->er << std::endl;
  }

  FazzyNumbers operator+ (FazzyNumbers b) {
    FazzyNumbers res(0,0);
    res.x = this->x + b.x;
    res.el = this->el + b.el;
    res.er = this->er + b.er;
    return res;
  }

  FazzyNumbers operator- (FazzyNumbers b) {
    FazzyNumbers res(0,0);
    res.x = this->x - b.x;
    res.el = this->el - b.el;
    res.er = this->er - b.er;
    return res;
  }

  FazzyNumbers operator* (FazzyNumbers b) {
    FazzyNumbers res(0,0);
    res.x = this->x * b.x;
    res.el = this->el * b.el;
    res.er = this->er * b.er;
    return res;
  }

  FazzyNumbers operator/ (FazzyNumbers b) {
    FazzyNumbers res(0,0);
    if (isZero(b.x) && isZero(b.el) && isZero(b.er) && (b.x > 0)) {
      res.x = this->x / b.x;
      res.el = this->el / b.el;
      res.er = this->er / b.er;
    } else {
      res.x = this->x;
      res.el = this->el;
      res.er = this->er;
    }
    return res;
  }

  FazzyNumbers operator! () {
    FazzyNumbers res(0,0);
    if (isZero(this->x) && isZero(this->el) && isZero(this->er) && (this->x > 0)) {
      res.x = 1 / this->x;
      res.el = 1 / this->el;
      res.er = 1 / this->er;
    } else {
      res.x = this->x;
      res.el = this->el;
      res.er = this->er;
    }
    return res;
  }

  int operator< (FazzyNumbers b) {
    if (this->x < b.x) {
      return 1;
    } else {
      return 0;
    }
  }

  int operator> (FazzyNumbers b) {
    if (this->x > b.x) {
      return 1;
    } else {
      return 0;
    }
  }

  int operator<= (FazzyNumbers b) {
    if (this->x < b.x || (fabs(this->x - b.x) < getEps())) {
      return 1;
    } else {
      return 0;
    }
  }

  int operator>= (FazzyNumbers b) {
    if (this->x > b.x || (fabs(this->x - b.x) < getEps())) {
      return 1;
    } else {
      return 0;
    }
  }
};

#endif
