#pragma once
#include <iostream>

class Hasher {
private:
	int a = 1;
	int b = 0;
	int p = 101;
	int m = 9;
public:
	int hashFromKey(int key) {
		return ((a * key + b) % p) % m;
	}
};