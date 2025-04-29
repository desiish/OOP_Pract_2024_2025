#include <iostream>

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

unsigned countOfValidElements(const int* numbers, size_t size, bool (*pred) (const int num))
{
    unsigned count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (pred(numbers[i]))
            count++;
    }

    return count;
}

int main() {
    int numbers[] = { 1,3,5,7,9,2,4,6,8,15 };

    unsigned countOfPrimeNumbers = countOfValidElements(numbers, 10, isPrime);
    unsigned countOfEvenNumbers = countOfValidElements(numbers, 10, [](int number) -> bool { return number % 2 == 0; });
    unsigned countOfOddNumbers = countOfValidElements(numbers, 10, [](int number) -> bool { return number % 2 != 0; });

    std::cout << "Count of prime numbers: " << countOfPrimeNumbers << std::endl;
    std::cout << "Count of even numbers: " << countOfEvenNumbers << std::endl;
    std::cout << "Count of odd numbers: " << countOfOddNumbers << std::endl;
}