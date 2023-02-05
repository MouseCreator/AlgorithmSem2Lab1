#include "DataFileReader.h"

int main() {
	FileReader reader;
	reader.read("sample.txt");
	std::vector<ComplexNumber> number = reader.getNumbers();
	for (std::size_t i = 0; i < number.size(); i++) {
		number[i].prints();
	}
}