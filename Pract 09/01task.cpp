#include <iostream>
#include <cmath>
#include <fstream> 
#include <stdexcept>
//x++ - lvalue -> A operator++(int);
//++x - rvalue -> A& operator++(); 
class NVector
{
private:
	double x = 0;
	double y = 0;

public:

	NVector() = default;
	NVector(double x, double y) : x(x), y(y) {}

	//v+v
	NVector operator+(const NVector& v)
	{
		return NVector(x + v.x, y + v.y);
	}
	//v-v
	NVector operator-(const NVector& v)
	{
		return NVector(x - v.x, y + v.y);
	}
	//v*num

	NVector operator*(int num)
	{
		return NVector(x * num, y * num);
	}

	//return length
	double operator() () const
	{
		return std::sqrt(x * x + y * y);
	}

	//return random value
	double operator[](int ind) const
	{
		if (ind == 0) return x;
		else if (ind == 1) return y;
		else throw std::out_of_range("Index is out of range!");
	}

	//files
	friend std::ofstream& operator<<(std::ofstream& writeFile, const NVector& v);
	friend std::ifstream& operator>>(std::ifstream& readFile, NVector& v);
	

	void display()
	{
		std::cout << x << " " << y;
	}

};
std::ofstream& operator<<(std::ofstream& writeFile, const NVector& v)
{
	writeFile << v.x;
	return writeFile;
}
std::ifstream& operator>>(std::ifstream& readFile, NVector& v)
{
	readFile >> v.x;
	return readFile;
}

int main() {

	NVector v1(4, 3);
	NVector v2(1.5, 3.4);
	NVector v3 = v1 + v2;
	NVector v4 = v1 - v2;
	NVector v5 = v1 * 3;
	v5.display();

	double length = v1();
	std::cout << length;

	try
	{
		int getX = v1[1];
		std::cout << getX;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Error: " << e.what();
	}

	//file - write
	std::ofstream file("output.txt");
	if (file.is_open()) {
		file << v1;
		file.close();
	}
	else {
		std::cerr << "Unable to open file\n";
	}
	file.close();

	//file read 
	std::ifstream file1("input.txt");
	if (file1.is_open()) {
		file1 >> v1;
		file1.close();
	}
	else {
		std::cerr << "Unable to open file\n";
	}

}
