
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
        //adding watch to monitor the inputs in the dynamic int array
        arr[i] = element;
    }
}
int countMatchingElements(const int *arr, int size, bool (*predicate)(int)) {
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
    inputNumbersInArray(arrayNumbers , n);


    //type (pointer to function) (arguments for f) = [capture list](parameter) -> type for return {body}
    // we have a pointer to a function and inside it a lambda function
    bool (*isEven)(int) = [](int num) -> bool { return num % 2 == 0; };

    int result = countMatchingElements(arrayNumbers, n, isEven);
    std::cout << "Count of even numbers: " << result << std::endl;
    delete[] arrayNumbers;
}
