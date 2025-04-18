#include <iostream>
#include <fstream>
#include <cstring>
constexpr size_t MAX_SIZE = 1024;

void printDiffLineIndex(std::ifstream& ifs1, std::ifstream& ifs2) {
	char buff1[MAX_SIZE] = {};
	char buff2[MAX_SIZE] = {};

	bool areLinesEqual = true;
	while (true) {
		
	
		if (ifs1.getline(buff1, MAX_SIZE) && ifs2.getline(buff2, MAX_SIZE)) {
			// Compare the contents of the lines
			if (strcmp(buff1, buff2) != 0) {
				std::cout << "Line from file1: " << buff1 << std::endl;
				std::cout << "Line from file2: " << buff2 << std::endl;
				areLinesEqual = false;
				return;
			}
		}		

		if (ifs1.eof() && ifs2.eof() && areLinesEqual)
		{
			std::cout << "Files are identical."<< std::endl;
			return;
		}

		if (ifs1.eof() || ifs2.eof() || strcmp(buff1, buff2) != 0)
		{
			if (strcmp(buff1, buff2) < 0) {
				std::cout << buff1<< std::endl;
			}
			else {
				std::cout << buff2 << std::endl;
			}
			return;
		}
	}
}
	int main() {

		std::ifstream file1("example.txt");
		std::ifstream file2("example1.txt");
	
		if (!file1.is_open() || !file2.is_open()) {
			std::cerr << "Error opening one or both files!" << std::endl;
			return 1;
		}

		printDiffLineIndex(file1, file2);

		file1.close();
		file2.close();
}
