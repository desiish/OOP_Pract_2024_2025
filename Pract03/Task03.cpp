#include <iostream>
#include <fstream>

constexpr unsigned int MAX_COUNT_SYMBOLS = 2048;

void selfPrint()
{
	std::ifstream ifs("selfPrint.cpp");

	if (!ifs.is_open())
	{
		std::cerr << "Error while opening the file for reading!";
		return;
	}

	while (!ifs.eof())
	{
		char buff[MAX_COUNT_SYMBOLS];
		ifs.getline(buff, MAX_COUNT_SYMBOLS);
		std::cout << buff << "\n";
	}

	ifs.close();
}

int main()
{
	selfPrint();
}