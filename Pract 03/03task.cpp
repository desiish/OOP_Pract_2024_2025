#include <iostream>
#include <fstream>

using namespace std;
constexpr int MAX_SIZE = 1024;

void printFileCode() {
	ifstream ifs("zadacha_oop.cpp");
	if (!ifs.is_open()){
		cout << "Failed to open the file!" << endl;
		return;
	}
		
	char buff[MAX_SIZE] = {};
	while (true)
	{
		ifs.getline(buff, MAX_SIZE); //Reads up to MAX_SIZE characters or until newline
		if (ifs.eof())
			break;

		cout << buff << '\n';
	}
}
int main() {
	printFileCode(); 
	
}
