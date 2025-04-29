#include <iostream>

unsigned sumDigits(unsigned number)
{
    if (number == 0)
        return 0;

    return (number % 10) + sumDigits(number / 10);
}

int main() {
    unsigned number;

    do
    {
        std::cin >> number;
    } while (number < 0);

    unsigned sumOfDigits = sumDigits(number);
    std::cout << sumOfDigits;
}