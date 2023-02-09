#pragma once
#include <iostream>

class HashTalbe {
	int* arr = nullptr;
	std::size_t maxSize = 0;

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