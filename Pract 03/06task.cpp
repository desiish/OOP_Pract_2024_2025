#include <iostream>
#include <fstream>
#include <cstring>
//encapsulation'- see
struct City {
	static const int SIZE = 63;
	char name[SIZE];
	int citizens;
};

struct District {
	static const int CITY_SIZE = 20;
	int currSize;
	City cities[CITY_SIZE];

	District() : currSize(0) {
		for (int i = 0; i < CITY_SIZE; ++i) {
			strcpy_s(cities[i].name, "Blank");
			cities[i].citizens = 0;
		}

	}

	void addCity(char name[], int citizens) {
		if (currSize < CITY_SIZE) {
			strcpy_s(cities[currSize].name, name);
			cities[currSize].citizens = citizens;
			currSize++;
		}
		else {
			std::cout << "District is full. \n";
		}
	}


	bool isNameTaken(const char* name) const {
		for (int i = 0; i < currSize; ++i) {
			if (strcmp(cities[i].name, name) == 0) {
				return true; // Name is already taken
			}
		}
		return false;
	}

	void writeChosenDistrict(std::ofstream& file, int n, int index) const{
		file << "District " << index << "\n";
		for (int i = 0; i < n; i++) {
			file << "City: " << i + 1 << " : " << cities[i].name << " with " << cities[i].citizens << " people.\n";

		}
	
	}
	// bubble sort
	void sortCities() {
		for (int i = 0; i < currSize - 1; i++) {
			for (int j = 0; j < currSize - i - 1; j++) {
				if (cities[j].citizens > cities[j + 1].citizens) {					
					City temp = cities[j];
					cities[j] = cities[j + 1];
					cities[j + 1] = temp;
				}
			}
		}
	}

	void writeSortedDistrict(std::ofstream& file, int index) {
		file << "District " << index << "\n";
		for (int i = 0; i < currSize; i++) {
			file << "City: " << i + 1 << " : " << cities[i].name
				<< " with " << cities[i].citizens << " people.\n";
		}
	}	
};
void inputValues(int numberOfCities, int districtIndex, District& district, int i) {
	char name[City::SIZE];
	int citizens;

	std::cout << "Enter name for city " << i + 1 << ": ";
	std::cin.ignore();
	std::cin.getline(name, City::SIZE);

	while (district.isNameTaken(name)) {
		std::cout << "This name is already taken. Try another one.\n";
		std::cout << std::endl;
		std::cin.getline(name, City::SIZE);
	}

	std::cout << "Enter number of citizens: ";
	std::cin >> citizens;
	district.addCity(name, citizens);
	
}
void inputCities(int numberOfCities, int districtIndex, District& district) {	
	for (int i = 0; i < numberOfCities; i++) {

		inputValues(numberOfCities, districtIndex, district, i);
		
	}

}
int extractNumber(const char* str) {
	int num = 0;
	while (*str) {
		if (*str >= '0' && *str <= '9') {
			num = num * 10 + (*str - '0');
		}
		str++;
	}
	return num;
}

void readFromFile(std::ifstream& file, int districtNumber) {
	if (!file.is_open()) {
		std::cout << "Error opening file.\n";
		return;
	}

	std::cout << "Choose a district to order: ";
	int n;
	std::cin >> n;

	if (n > districtNumber) {
		std::cout << "Invalid district. \n";
		return;
	}

	char buffer[City::SIZE];
	District district;
	bool found = false;
	int currentDistrict = 0;

	while (file.getline(buffer, sizeof(buffer))) {
		
		if (strstr(buffer, "District") != nullptr) {
			currentDistrict++;

			if (currentDistrict == districtNumber) {
				found = true;
				continue;
			}
			else if (found) {
				break; // Stop reading after the chosen district
			}
		}

		// Extract cities if the chosen district is found
		if (found && strstr(buffer, "City:") != nullptr) {
			char cityName[City::SIZE];
			int citizens = extractNumber(buffer); // Extract number

			// Extract the city name
			sscanf_s(buffer, "City: %*d : %s", cityName, (unsigned)_countof(cityName));
			district.addCity(cityName, citizens);
		}


	}

	if (!found) {
		std::cout << "District not found.\n";
		return;
	}


	district.sortCities();

	// Write sorted data to a new file
	std::ofstream sortedFile("example1.txt");
	if (!sortedFile.is_open()) {
		std::cout << "Error creating sorted file.\n";
		return;
	}

	district.writeSortedDistrict(sortedFile, districtNumber);
	sortedFile.close();

	std::cout << "Sorted district saved to 'example1.txt'.\n";

}
	int main() {		
		City c;
		District* districts = new District[5];
		std::ofstream writeFile("example.txt");

		std::cout << "Choose how many districts you want to put the cities in: \n";
		int districtIndex;
		std::cin >> districtIndex;

		//districtIndex -= 1;
		

		for (int i = 0; i < districtIndex; i++) {
		
			std::cout << "Enter how many cities you want to make: \n";
			int numberOfCities;
			std::cin >> numberOfCities;

			inputCities(numberOfCities, districtIndex, districts[i]);			

			if (!writeFile.is_open()) {
				std::cout << "error opening file. \n";
			}

			districts[i].writeChosenDistrict(writeFile, numberOfCities, i+1);
		}
				
		writeFile.close();

		//time to read
		std::ifstream readFile("example.txt");
		readFromFile(readFile, districtIndex);

		readFile.close();
		delete[] districts;
}
