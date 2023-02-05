#pragma once
#include "ComplexNumber.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
class FileReader {
private:
	std::vector<ComplexNumber> numberVector;

	std::vector<ComplexNumber> readFiles(std::fstream& file) {
		std::string line;
		std::vector<ComplexNumber> tempVector;
		while (true) {
			std::getline(file, line);
			if (file.fail()) {
				return tempVector;
			}
			if (strstr(line.c_str(), "i")) {
				tempVector.emplace_back(advancedRead(line));
			}
			else {
				tempVector.emplace_back(defaultRead(line));
			}
		}
	}
	ComplexNumber defaultRead(std::string line) {
		int re = 0;
		int im = 0;
		std::stringstream stream;
		stream << line;
		stream >> re >> im;
		stream.clear();
		return ComplexNumber(re, im);
	}
	ComplexNumber advancedRead(std::string line) {
		std::string noSpaces = removeSpaces(line);
		return defaultRead(removeSigns(noSpaces));
	}
	std::string removeSpaces(std::string line) {
		std::string result = "";
		for (char c : line) {
			if (!isspace(c))
				result += c;
		}
		return result;
	}
	std::string removeSigns(std::string line) {
		std::string temp;
		std::string re;
		std::string im;
		bool readingIm = false;
		for (char c : line) {
			switch (c)
			{
			case 'i': readingIm = true; break;
			case '+':
				setStrings(readingIm, temp, re, im);
				break;
			case '-':
				setStrings(readingIm, temp, re, im);
				temp += c;
				break;
			default:
				if (isdigit(c))
					temp += c;
				break;
			}
		}
		setStrings(readingIm, temp, re, im);
		if (re.empty())
			re = "0";
		if (im.empty())
			im = "0";
		return re + " " + im;
	}
	void setStrings(bool& isImaginary, std::string& temp, std::string& re, std::string& im) {
		if (isImaginary) {
			im = temp.empty() ? "1" : temp;
		}
		else {
			re = temp;
		}
		temp.clear();
		isImaginary = false;
	}

public:
	std::vector<ComplexNumber> read(std::string filename) {

		std::fstream file = std::fstream(filename);
		std::vector<ComplexNumber> currentVector;
		if (file.is_open()) {
			currentVector = this->readFiles(file);
			file.close();
		}
		else {
			std::cerr << "Unable to read input file!" << std::endl;
		}
		for (ComplexNumber n : currentVector) {
			numberVector.emplace_back(n);
		}
		return currentVector;
	}
	void clear() {
		numberVector.clear();
	}
	std::vector<ComplexNumber> getNumbers() {
		return numberVector;
	}

};