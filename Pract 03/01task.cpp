#include <iostream>
#include <fstream>
//for styling
#include <iomanip>
#include <string>
//of - write; if - read
int main() {
	int a, b;
	std::cout << "Pick 2 numbers: \n";
	std::cin >> a >> b;
	int sum = a + b;
	int subtraction = a - b;
	std::ofstream inputFile("result1.txt", std::ios::out);
	if (!inputFile.is_open()) {
		std::cerr << "Error opening file";
		return 1;
	}

	//input
	inputFile << "Sum of numbers:";
	inputFile << a + b << std::endl;
	inputFile << "Subtraction of numbers:";
	inputFile << a - b << std::endl;

	inputFile.close();

	std::ifstream outputFile("C:/Users/vikik/Desktop/example.txt");
	std::cout << "Here is the sum and subtraction from the numbers: ";
	char ch;
	bool skip = false;
	while (outputFile.get(ch)) {
		if (ch == 'S') {
			skip = true;
		}
		if (skip) {
			if (ch == ':') {
				skip = false; 
			}
			continue;
		}
		std::cout << ch;
	}
	int a_reconstructed = (sum + subtraction) / 2;
	int b_reconstructed = sum - a_reconstructed;
	std::cout << "The original numbers were: " << a_reconstructed << " and " << b_reconstructed;

	outputFile.close();

}
