#include "Teacher.h"
#include <iostream>
#include <fstream>
void writeInFile(Teacher& t) 
{
	std::ofstream writeFile("C:\\Users\\vikik\\Desktop\\teachers.bin", std::ios::binary);
	if (!writeFile)
	{
		throw std::runtime_error("Error opening file for writing.\n");
	}
	t.writeToStream(writeFile);
	writeFile.close();
}

//use copy of t
void readFromFile(Teacher t)
{
	std::ifstream readFile("C:\\Users\\vikik\\Desktop\\teachers.bin", std::ios::binary);
	if (!readFile)
	{
		throw std::runtime_error("Error opening file for reading.\n");
	}
	t.readFromStream(readFile);
	readFile.close();
}
int main()
{
	try
	{
		Teacher t1("John", 35, Teacher::Subject::ENGLISH, 1500);
		Teacher t2("Ana", 35, Teacher::Subject::HISTORY, 1500);
		Teacher t3("Patric", 35, Teacher::Subject::MATH, 1500);

		//t3.print();
		writeInFile(t1);
		readFromFile(t2);
	
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what();
	}

}
