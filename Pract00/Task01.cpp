#include <iostream>

unsigned sumNumbers(unsigned number)
{
    if (number == 0)
        return 0;

    return number + sumNumbers(number - 1);
}

int main() {
    unsigned input;

    do
    {
        std::cin >> input;
    } while (input < 0);

    unsigned sum = sumNumbers(input);
    std::cout << sum;
}