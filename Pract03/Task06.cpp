#include <iostream>
#include <fstream>

constexpr unsigned short MAX_SYMBOLS_CITY_NAME = 63 + 1;
constexpr unsigned short MAX_COUNT_CITIES = 20;

struct City
{
	char name[MAX_SYMBOLS_CITY_NAME] = {};
	int countOfCitizens = 0;
};

struct District
{
	size_t currentSize = 0;
	City cities[MAX_COUNT_CITIES] = {};
};

void writeCityToFile(std::ofstream& ofs, const City& city)
{
	ofs << "Name: " << city.name << ", count of citizens: " << city.countOfCitizens << "\n";
}

void writeDistrictToFile(std::ofstream& ofs, const District& district)
{
	if (!ofs.good())
	{
		std::cerr << "The stream is not good before writing!";
		return;
	}

	for (size_t i = 0; i < district.currentSize; i++)
	{
		writeCityToFile(ofs, district.cities[i]);
	}
}

void readCityFromFile(std::ifstream& ifs, City& city)
{
	ifs.getline(city.name, MAX_SYMBOLS_CITY_NAME);

	if (!ifs.good())
	{
		std::cerr << "The stream is not good while reading!";
		return;
	}

	ifs >> city.countOfCitizens;

	if (!ifs.good())
	{
		std::cerr << "The stream is not good while reading!";
		return;
	}

}

void readDistrictFromFile(std::ifstream& ifs, District& district)
{
	if (!ifs.good())
	{
		std::cerr << "The stream is not good before reading!";
		return;
	}

	for (size_t i = 0; i < district.currentSize; i++)
	{
		readCityFromFile(ifs, district.cities[i]);
	}

}

void sortCitiesInDistrict(District& district) {

	for (int i = 1; i < district.currentSize; i++)
	{
		City keyCity = district.cities[i];
		int j = i - 1;

		while (j >= 0 && district.cities[j].countOfCitizens > keyCity.countOfCitizens)
		{
			district.cities[j + 1] = district.cities[j];
			j = j - 1;
		}

		district.cities[j + 1] = keyCity;
	}

}


void writeSortedCitiesToFile(std::ofstream& ofs, const District& district)
{
	if (!ofs.good())
	{
		std::cerr << "The stream is not good before writing!";
		return;
	}

	for (size_t i = 0; i < district.currentSize; i++)
	{
		writeCityToFile(ofs, district.cities[i]);
	}

}
