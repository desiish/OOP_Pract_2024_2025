#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
	int a, b;
	std::cout << "Pick 2 numbers: \n";
	std::cin >> a >> b;
	int sum = a + b;
	int subtraction = a - b;
	std::ofstream writeFile("C:/Users/vikik/Desktop/example.txt");
	if (!writeFile.is_open()) 
	{
		std::cerr << "Error opening file to write";
	}

	//input
	writeFile << sum << std::endl;
	writeFile << subtraction << std::endl;

	writeFile.close();

	std::ifstream readFile("C:/Users/vikik/Desktop/example.txt");
	std::cout << "Here is the sum and subtraction from the numbers: \n";

	int num1, num2;
	readFile >> num1 >> num2;
	std::cout << num1 << "\n" << num2;

	int a_reconstructed = (sum + subtraction) / 2;
	int b_reconstructed = sum - a_reconstructed;
	std::cout << "\nThe original numbers were: " << a_reconstructed << " and " << b_reconstructed;

	readFile.close();

}
