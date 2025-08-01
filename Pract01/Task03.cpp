#include <iostream>
#include <algorithm>

void sortByPredicateResult(int* numbers, size_t size, bool (*pred)(const int num))
{
    size_t left = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (pred(numbers[i]))
        {
            std::swap(numbers[left], numbers[i]);
            left++;
        }
    }
}

int main() {
    constexpr short ARRAY_SIZE = 10;
    int numbers[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 15 };

    sortByPredicateResult(numbers, ARRAY_SIZE, [](int number) { return number % 2 == 0; });

    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        std::cout << numbers[i] << " ";
    }
}
