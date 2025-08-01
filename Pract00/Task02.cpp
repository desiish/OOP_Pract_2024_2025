#include <iostream>

bool isDigitInNumber(unsigned long long number, unsigned digit)
{
    if (number == 0)
        return digit == 0;

    if (number % 10 == digit)
        return true;

    return isDigitInNumber(number / 10, digit);
}

int main() {
    unsigned long long number;
    unsigned digit;

    do
    {
        std::cin >> number;
        std::cin >> digit;
    } while ((digit < 0 || digit >9) && number < 0);

    bool result = isDigitInNumber(number, digit);
    std::cout << std::boolalpha << result;
}