#include <iostream>
int sumOfNumbers(int n) {
    if (n == 0) {
        return n;
    }
    return n + sumOfNumbers(n - 1);
}
int main()
{
    int n;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> n;
    std::cout << sumOfNumbers(n);
}

