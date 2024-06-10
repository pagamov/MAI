#pragma once
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Vertex.hpp"

template<class T>
class Trapeze {
public:
	vertex<T> vertices[4];

	Trapeze() = default;
	Trapeze(std::istream& in);
	void Read(std::istream& in);
	void Print(std::ostream& os) const;
	friend std::ostream& operator<< (std::ostream& out, const Trapeze<T>& point);
};

	template<class T>
	Trapeze<T>::Trapeze(std::istream& is) {
		for (int i = 0; i < 4; i++) {
			is >> this->vertices[i];
		}
	}

	template<class T>
	void Trapeze<T>::Print(std::ostream& os) const {
		for (int i = 0; i < 4; i++) {
			os << this->vertices[i];
			if (i != 4) {
				os << ',';
			}
		}
		os << std::endl;
	}

	template<class T>
	void Trapeze<T>::Read(std::istream& in) {
		for (int i = 0;i < 4;i++)
			in >> vertices[i];
	}

	template<class T>
	std::ostream& operator<<(std::ostream& os, const Trapeze<T>& point) {
		for (int i = 0; i < 4; i++) {
			os << point.vertices[i];
			if (i != 4) {
				os << ',';
			}
		}
	}
