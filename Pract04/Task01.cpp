#include <iostream>
#include <fstream>

size_t getCountOfNumbers(std::ifstream& ifs)
{
    size_t currPosition = ifs.tellg();

    ifs.seekg(0, std::ios::end);
    size_t fileSize = ifs.tellg();

    ifs.clear();
    ifs.seekg(currPosition);

    return fileSize / sizeof(int);
}

void writeNumbersToFile(std::ofstream& ofs, int* numbers, size_t size)
{
    ofs.write((const char*)numbers, size * sizeof(numbers[0]));
}

void getNumbersFromFile(std::ifstream& ifs, int* numbers, size_t countOfNumbers)
{
    ifs.read((char*)numbers, countOfNumbers * sizeof(numbers[0]));
}

size_t getCountOfConditionNums(const int* numbers, size_t size, bool isEven)
{
    size_t count = 0;

    for (size_t i = 0; i < size; i++) {
        if ((isEven && numbers[i] % 2 == 0) || (!isEven && numbers[i] % 2 != 0)) {
            count++;
        }
    }

    return count;
}

int* getEvenOrOddNums(const int* numbers, size_t& size, bool isEven)
{
    size_t countNumbers = getCountOfConditionNums(numbers, size, isEven);

    int* output = new int[countNumbers];
    size_t index = 0;

    for (size_t i = 0; i < size; i++)
    {
        if ((isEven && numbers[i] % 2 == 0) || (!isEven && numbers[i] % 2 != 0))
        {
            output[index] = numbers[i];
            index++;
        }
    }

    size = countNumbers;

    return output;
}

int main()
{
    std::ifstream ifs("binary.txt", std::ios::binary);

    if (!ifs.is_open())
    {
        std::cerr << "Error while opening the file for reading" << std::endl;
        return -1;
    }

    size_t countOfNumbers = getCountOfNumbers(ifs);

    if (countOfNumbers == 0)
    {
        std::cerr << "File is empty or no integers found" << std::endl;
        return -1;
    }

    int* numbers = new int[countOfNumbers];

    getNumbersFromFile(ifs, numbers, countOfNumbers);

    std::ofstream evensFile("evens.txt", std::ios::binary);

    if (!evensFile.is_open())
    {
        std::cerr << "Error while opening the file for writing" << std::endl;
        delete[] numbers;
        return -1;
    }

    size_t countEvens = getCountOfConditionNums(numbers, countOfNumbers, true);
    int* evens = getEvenOrOddNums(numbers, countEvens, true);

    writeNumbersToFile(evensFile, evens, countEvens);

    std::ofstream oddsFile("odd.txt", std::ios::binary);

    if (!oddsFile.is_open())
    {
        std::cerr << "Error while opening the file for writing" << std::endl;
        delete[] numbers;
        delete[] evens;
        return -1;
    }

    size_t countOdds = getCountOfConditionNums(numbers, countOfNumbers, false);
    int* odds = getEvenOrOddNums(numbers, countOdds, false);

    writeNumbersToFile(oddsFile, odds, countOdds);

    ifs.close();
    evensFile.close();
    oddsFile.close();

    delete[] numbers;
    delete[] evens;
    delete[] odds;
}
