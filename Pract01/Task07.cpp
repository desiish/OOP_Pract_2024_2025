#include <iostream>

struct ComplexNumber
{
	double real;
	double imaginary;
};

void printComplexNumber(const ComplexNumber& complexNumber)
{
	std::cout << complexNumber.real;
	if (complexNumber.imaginary < 0)
	{
		std::cout << " " << complexNumber.imaginary << "i";
	}
	else
	{
		std::cout << " + " << complexNumber.imaginary << "i";
	}
}

ComplexNumber getSumOfTwo(const ComplexNumber& c1, const ComplexNumber& c2)
{
	ComplexNumber sum = { c1.real + c2.real,c1.imaginary + c2.imaginary };
	return sum;
}

ComplexNumber getMultiplicationOfTwo(const ComplexNumber& c1, const ComplexNumber& c2)
{
	ComplexNumber multiplication = {
		 (c1.real * c2.real) - (c1.imaginary * c2.imaginary), 
		(c1.real * c2.imaginary) + (c1.imaginary * c2.real) };
	return multiplication;
}

int main()
{
	ComplexNumber complexNum1 = { 2,-3 };
	ComplexNumber complexNum2 = { 4,5 };

	std::cout << "Sum: ";
	printComplexNumber(getSumOfTwo(complexNum1, complexNum2));
	std::cout << std::endl;

	std::cout << "Multiplication: ";
	printComplexNumber(getMultiplicationOfTwo(complexNum1, complexNum2));
}