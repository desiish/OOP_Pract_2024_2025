#include <iostream>
#include <fstream>

void writeToFile()
{
	std::ofstream ofs("result1.txt");

	double firstNum, secondNum;
	std::cin >> firstNum >> secondNum;
	if (!ofs.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
		return;
	}

	ofs << firstNum + secondNum << " " << firstNum - secondNum;

	ofs.close();
}

void readFromFile()
{
	std::ifstream ifs("result1.txt");
	if (!ifs.is_open()) {
		std::cerr << "Error opening file for reading." << std::endl;
		return;
	}

	double sum, diff;
	ifs >> sum;

	if (!ifs.good()) {
		std::cerr << "Error reading sum!" << std::endl;
		return;
	}

	ifs >> diff;
	if (!ifs.good()) {
		std::cerr << "Error reading difference!" << std::endl;
		return;
	}

	std::cout << (sum + diff) / 2 << " " << (sum - diff) / 2 << std::endl;

	ifs.close();
}


int main()
{
	readFromFile();

}


