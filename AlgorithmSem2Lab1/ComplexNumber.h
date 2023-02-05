#pragma once
#include <cmath>
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
		return floor(this->modulo());
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
};