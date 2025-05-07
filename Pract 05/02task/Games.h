#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
#include <cstring>

namespace Constants {
	const int TITLE_SIZE = 65;
}
class Games {
private:
	char _title[Constants::TITLE_SIZE];
	double _price;
	bool _isAvailable;

public:
	Games(const char* title, double price, bool isAvailable); 
	Games(const Games& other);
	Games& operator=(const Games& other) = delete;
	~Games();

	//getters
	const char* getTitle() const;
	const double getPrice() const;
	bool getIsAvailable() const;

	//setters
	void setTitle(const char* title);
	void setPrice(const double price);
	void setIsAvailable(bool isAvailable);

	//write and read 
	void writeToStream(std::ofstream& write) const;
	void readFromStream(std::ifstream& read);

	//additional
	void isFree();
	void print();

};
