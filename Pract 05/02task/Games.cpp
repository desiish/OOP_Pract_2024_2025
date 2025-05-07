#include "Games.h"
#include <stdexcept>


//copy ctor
Games::Games(const Games& other)
	:_price(other._price), _isAvailable(other._isAvailable)
{
	std::strcpy(_title, other._title);
	_title[Constants::TITLE_SIZE - 1] = '\0';

}
//ctor
Games::Games(const char* title, double price, bool isAvailable)
{
	setTitle(title);
	setPrice(price);
	setIsAvailable(isAvailable);
}

Games::~Games()
{

}
//setters
void Games::setTitle(const char* title)
{
	if (!title || std::strlen(title) > Constants::TITLE_SIZE)
	{
		throw std::invalid_argument("Title is too big or invalid!\n");
	}
	std::strcpy(_title, title);
}

void Games::setPrice(const double price)
{
	if (price < 0)
	{
		throw std::invalid_argument("Invalid price!\n");
	}
	_price = price;
}

void Games::setIsAvailable(bool isAvailable)
{
	_isAvailable = isAvailable;
}

//getters
const char* Games::getTitle() const
{
	return _title;
}
const double Games::getPrice() const
{
	return _price;
}
bool Games::getIsAvailable() const
{
	return _isAvailable;
}

void Games::isFree()
{
	if (getIsAvailable()) 
	{
		std::cout << "The game: " << getTitle() << " is available\n";
	}
	else
	{
		std::cout << "The game: " << getTitle() << " is not available\n";
	}
}

void Games::print()
{
	std::cout << "Name: " << getTitle() << std::endl;
	std::cout << "Price: " << getPrice() << std::endl;
	std::cout << "Availability: " << (getIsAvailable() ? "Yes" : "No") << std::endl;
}


//OFSTREAM
void Games::writeToStream(std::ofstream& write) const
{
	write << _title << std::endl << _price << std::endl << _isAvailable << std::endl;

}

void Games::readFromStream(std::ifstream& read)
{
	char templateTitle[Constants::TITLE_SIZE];
	read.getline(templateTitle, Constants::TITLE_SIZE);

	if (!read)
	{
		throw std::runtime_error("Failed to read text!\n");
	}
	strcpy(_title, templateTitle);
	_title[Constants::TITLE_SIZE - 1] = '\0';

	read >> _price;
	read >> _isAvailable;
	read.ignore();
}
