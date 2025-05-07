#include <iostream>
#include <algorithm>

int* makeArray(int n) {
    int* arr = new int[n];
    return arr;
}
void inputNumbersInArray(int* arr, int n) {
    std::cout << "Let's assign values to the array!\n";
    for (int i = 0; i < n; i++) {
        int element;
        std::cout << "Enter an element: \n";
        std::cin >> arr[i];
    }
}
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int& binarySearchFirstMatch(int arr[], int size, bool (*predicate)(int)) {
    int left = 0;
    int right = size - 1;
    int* result = nullptr;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (predicate(arr[mid])) {
            result = &arr[mid];
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (result == nullptr) {
        std::cout << "No matching element found";
    }

    return *result;
}


int countMatchingElements(const int* arr, int size, bool (*predicate)(int)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (predicate(arr[i])) {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    std::cout << "How many numbers are we using for our array? \n";
    std::cin >> n;
    int* arrayNumbers = makeArray(n);
    inputNumbersInArray(arrayNumbers, n);
    //sort the array
    selectionSort(arrayNumbers, n);

    bool (*isEven)(int) = [](int x) { return x % 2 == 0; };

    int& result = binarySearchFirstMatch(arrayNumbers, n, isEven);
    std::cout << "First matching element: " << result << std::endl;

    delete[] arrayNumbers;
}
