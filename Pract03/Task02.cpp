#include <iostream>
#include <fstream>

constexpr size_t MAX_SIZE = 64;

bool upgradeOccurences(int index, int* numbers, int* occurrences, int currentNum)
{
	for (int j = 0; j < index; j++)
	{
		if (numbers[j] == currentNum)
		{
			occurrences[j]++;
			return true;
		}
	}

	return false;
}

void fillOccurences(int& indexNums, int* numbers, int* occurrences, int currentNum)
{
	if (!upgradeOccurences(indexNums, numbers, occurrences, currentNum))
	{
		if (indexNums >= MAX_SIZE) {
			std::cerr << "Error: Too many unique numbers, ignoring " << currentNum << std::endl;
			return;
		}
		numbers[indexNums] = currentNum;
		occurrences[indexNums] = 1;
		indexNums++;
	}

}

int getIndexMaxNum(int indexNums, int* occurrences)
{
	int indexMaxNum = 0;
	int countMaxNum = 0;

	for (int i = 0; i < indexNums; i++)
	{
		if (occurrences[i] > countMaxNum)
		{
			countMaxNum = occurrences[i];
			indexMaxNum = i;
		}
	}

	return indexMaxNum;
}

int main()
{
	std::ifstream ifs("numbers.dat");

	if (!ifs.is_open()) {
		std::cerr << "Error opening the file for reading!";
		return;
	}

	if (ifs.eof()) {
		std::cerr << "Error: File is empty!" << std::endl;
		return;
	}

	int countOfNumbers;
	ifs >> countOfNumbers;

	if (!ifs.good())
	{
		std::cerr << "Eror reading count of numbers!";
		return;
	}

	if (countOfNumbers <= 0 || countOfNumbers > MAX_SIZE) {
		std::cerr << "Error: Invalid number count!" << std::endl;
		return;
	}

	int numbers[MAX_SIZE]{ 0 };
	int occurrences[MAX_SIZE]{ 0 };

	int indexNums = 0;

	for (int i = 0; i < countOfNumbers; i++)
	{
		int currentNum;
		ifs >> currentNum;

		if (!ifs.good())
		{
			std::cerr << "Eror reading number!";
			return;
		}

		fillOccurences(indexNums, numbers, occurrences, currentNum);

	}

	int indexMaxNum = getIndexMaxNum(indexNums, occurrences);

	std::cout << numbers[indexMaxNum];

	ifs.close();
}
