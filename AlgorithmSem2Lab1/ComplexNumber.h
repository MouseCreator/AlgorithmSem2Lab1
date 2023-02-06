#pragma once
#include <cmath>
#include <iostream>
class ComplexNumber {
private:
	int re;
	int im;
	const double minDifference = 0.0001;
public:
	ComplexNumber(int real, int imaginary) {
		this->re = real;
		this->im = imaginary;
	}
	ComplexNumber(int real) {
		this->re = real;
		this->im = 0;
	}
	double modulo() {
		return sqrt(re * re + im * im);
	}
	int moduloInt() {
		return (int) floor(this->modulo());
	}
	bool isGreaterThan(ComplexNumber other) {
		double modulo1 = this->modulo();
		double modulo2 = other.modulo();
		return abs(modulo1 - modulo2) < minDifference ? modulo1 > modulo2 : this->re > other.re;
	}
	bool equals(ComplexNumber other) {
		return this->re == other.re && this->im == other.im;
	}
	int real() {
		return re;
	}
	int imaginary() {
		return im;
	}
	bool isZero() {
		return im == 0 && re == 0;
	}
	void print() {
		if (isZero()) {
			std::cout << '0';
			return;
		}
		if (re != 0)
			std::cout << re;
		if (im != 0) {
			if (re!=0 && im > 0) {
				std::cout << "+";
			}
			std::cout << im << "*i";
		}
	}
	void printn() {
		print();
		std::cout << std::endl;
	}
	void printT() {
		std::cout << re << "\t" << im << std::endl;
	}
};