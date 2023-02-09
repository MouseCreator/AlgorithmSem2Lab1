#pragma once
#include <iostream>

class HashTalbe {
private:
	int* arr = nullptr;
	std::size_t maxSize = 0;
public:
	HashTalbe(int size) {
		arr = new int[size];
		maxSize = size;
	}
	~HashTalbe() {
		delete arr;
		arr = nullptr;
	}
	std::size_t maxSize() {
		return maxSize;
	}
};