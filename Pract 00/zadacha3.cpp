#include <iostream>
int countOfDigits(int n, int count) {
    if (n == 0) {
        return count;
    }
    count += n % 10;
    return countOfDigits(n / 10, count);

}
int main()
{
    int n;
    int count = 0;
    std::cout << "Enter a number: \n";
    std::cin >> n;
    std::cout << countOfDigits(n, count);
}

