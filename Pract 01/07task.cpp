#include <iostream>
struct Complex {
	int real;
	int imaginary;
	
};
Complex* sumOfComplexNumbers(Complex number1, Complex number2) {
	Complex* sum = new Complex{ number1.real + number2.real, number1.imaginary + number2.imaginary};
	return sum;
}
Complex* multiplicationOfComplexNumbers(Complex number1, Complex number2) {
	Complex* multiplication = new Complex{ number1.real * number2.real - number1.imaginary * number2.imaginary,
	number1.real * number2.imaginary + number1.imaginary * number2.real };
	return multiplication;

}
int main() {
	Complex number1 = { 2,2 };
	Complex number2 = { 4,3 };
	 
	Complex* sum = sumOfComplexNumbers(number1, number2);
	Complex* multiplication = multiplicationOfComplexNumbers(number1, number2);
	std::cout << "Sum of to comlex numbers: " << sum->real << " + " << sum->imaginary << "i\n";
	std::cout << "Multiplication of to comlex numbers: " << multiplication->real << " + " << multiplication->imaginary << "i\n";
	delete sum;
	delete multiplication;
}
