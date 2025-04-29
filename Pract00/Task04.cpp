#include <iostream>

bool isIncreasing(int* numbers, unsigned size)
{
    if (size <= 1)
        return true;

    if (numbers[0] > numbers[1])
        return false;

    return isIncreasing(numbers + 1, size - 1);
}

int main() {
    int numbers[] = { 1, 3, 2, 7, 9 };
    std::cout << std::boolalpha << isIncreasing(numbers, 5);
}
