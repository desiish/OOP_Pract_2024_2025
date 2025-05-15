#include <iostream>
#include <fstream>
#include <cstring>
namespace Constants
{
	const int SIZE = 25;
}
struct Pair {
	int x;
	int y;
};

struct Relation {
	//array of pairs
	Pair pairs[Constants::SIZE];
	int currSize;

	//constructor for adding
	Relation() : currSize(0) {

		for (int i = 0; i < Constants::SIZE; ++i) {
			pairs[i].x = 0;
			pairs[i].y = 0;
		}
	}

	//adds a pair to the relation
	void addPair(int x, int y) {
		if (currSize < Constants::SIZE) {
			pairs[currSize].x = x;
			pairs[currSize].y = y;
			currSize++;
		}
		else {
			std::cout << "Relation is full, cannot add more pairs." << std::endl;
		}
	}
	void putInFile(std::ofstream& file, const int number) const {
		if (number < Constants::SIZE) {

			file << "Chosen pair " << number << ": (" << pairs[number].x << ", " << pairs[number].y << ")\n";

		}
		else {
			std::cout << "No such relation. \n";
			return;
		}
	}
	//put everything in file
	void writeEverything(std::ofstream& file) {
		for (int i = 0; i < Constants::SIZE; i++) {
			file << "Pair " << i << ": (" << pairs[i].x << ", " << pairs[i].y << ")\n";
		}

	}
	void readFromFile(std::ifstream& file, const int number) const {
		char ch;
		if (number < Constants::SIZE) {
			while (file.get(ch)) {
				if (ch == '\n') {
					return;
				}
				std::cout << ch;
			}
		}
		else {
			std::cout << "No such relation. \n";
		}
	}
};

int main() {
	std::ofstream writeFile("C:\\Users\\vikik\\Desktop\\example.txt", std::ios::app);
	int n;
	std::cout << "Pick a number of relation: ";
	std::cin >> n;
	Relation r;
	r.addPair(1, 4);
	r.addPair(4, 4);
	r.addPair(2, 7);


	r.putInFile(writeFile, n);
	r.writeEverything(writeFile);
	writeFile.close();

	std::ifstream readFile("example.txt");
	r.readFromFile(readFile, n);
	readFile.close();


}
