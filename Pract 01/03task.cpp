
#include <iostream>
int* makeArray(int n) {
    int* arr = new int[n];
    return arr;
}
void inputNumbersInArray(int* arr, int n) {
    std::cout << "Let's assign values to the array!\n";
    for (int i = 0; i < n; i++) {
        int element;
        std::cout << "Enter an element: \n";
        std::cin >> element;
        arr[i] = element;
    }
}

void sortMatchingElements(int* arr, int size, bool (*predicate)(int)) {
    int insertPos = 0;
    for (int i = 0; i < size; i++) {
        if (predicate(arr[i])) {
            int temp = arr[i];
            for (int j = i; j > insertPos; j--) {
                arr[j] = arr[j - 1];
            }
            arr[insertPos] = temp;
            insertPos++;
        }
    }
}


int main()
{
    int n;
    std::cout << "How many numbers are we using for our array? \n";
    std::cin >> n;
    int* arrayNumbers = makeArray(n);
    inputNumbersInArray(arrayNumbers, n);
  
    bool (*isEven)(int) = [](int num) -> bool { return num % 2 == 0; };

    sortMatchingElements(arrayNumbers, n, isEven);

    for (int i = 0; i < n; i++) {
        std::cout << arrayNumbers[i] << " ";
    }

    delete[] arrayNumbers;
}
