#include <iostream>
void buildArray(int* arrayOfNumbers, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a number: \n";
        int nextN;
        std::cin >> nextN;
        *arrayOfNumbers = nextN;
        arrayOfNumbers++;
    }
}
int isSequence(int* arrayOfNumbers, int n) {
    if (n == 1) {
        return 1;
    }
    if (arrayOfNumbers[n - 1] < arrayOfNumbers[n - 2]) {
        return 0;
    }
    return isSequence(arrayOfNumbers, n - 1);
}
int main()
{
    int n;
    std::cout << "Enter amount of sequence's indexes: \n";
    std::cin >> n;

    int* arrayOfNumbers = new int[n];
    buildArray(arrayOfNumbers, n);

    std::cout << isSequence(arrayOfNumbers, n);

    delete[] arrayOfNumbers;
}

