#include <iostream>
#include <algorithm>

void selectionSort(int* arr, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
        {
            std::swap(arr[minIndex], arr[i]); 
        }

    }
}

int& countOfValidElements(int* numbers, size_t size, void (*sortFunc) (int* nums, size_t size), bool (*pred) (const int num))
{
    sortFunc(numbers, size);

    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (pred(numbers[mid]))
        {

            if (mid == 0 || !pred(numbers[mid - 1]))
                return numbers[mid];

            right = mid - 1;
        }

        else
        {
            if (numbers[mid] < numbers[size - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

        }

    }
    //how to return reference when an element is not present in the array of elements
    return 0;
}

int main() {
    int numbers[] = { 1,3,5,7,9,2,4,6,8,15 };

    int  firstEven = countOfValidElements(numbers, 10, selectionSort, [](int number) -> bool { return number % 2 == 0; });
    int  firstOdd = countOfValidElements(numbers, 10, selectionSort, [](int number) -> bool { return number % 2 == 1; });

    std::cout << "First even: " << firstEven << std::endl;
    std::cout << "First odd: " << firstOdd << std::endl;
}