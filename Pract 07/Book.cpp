#include "Book.h"
#pragma warning (disable : 4996)
#include <iostream>
#include <stdexcept>
#include <cstring>

size_t Book::_idCounter = 0;

void Book::copyDynamic(const Book& other)
{
	_name = new char[std::strlen(other._name) + 1];
	std::strcpy(_name, other._name);

	_author = new char[std::strlen(other._author) + 1];
	std::strcpy(_author, other._author);

}
void Book::freeDynamic()
{
	delete[] _name;
	delete[] _author;

	_name = nullptr;
	_author = nullptr;

}
Book::Book(const char* name, const char* author, bool isAvailable)
//use the default ctor in User to set the user to defUser
	: _isAvailable(isAvailable), _user(User()), _id(_idCounter++)
{
	if (!name || !author) 
	{
		char* temp = new char[8];
		std::strcpy(temp, "invalid");
		delete[] _name;
		delete[] _author;
		_name = temp;
		_author = temp;
		delete[] temp;
	}
	else
	{
		setName(name);
		setAuthor(author);
	}

};

Book::Book(const Book& other)
	:_name(nullptr), _author(nullptr),_isAvailable(other._isAvailable), _user(other._user)
{
	copyDynamic(other);
}

Book& Book::operator=(const Book& other)
{

	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);
		_isAvailable = other._isAvailable;
		_user = other._user;
	}

	return *this;
}

Book::~Book() 
{
	freeDynamic();
}

//setters 
void Book::setName(const char* name)
{
	//my idea is to put a certain name to the inv books and then reject them at addBook
	if(!name)
	{
		std::cout << "Invalid name for the book! You wont be able to add it to the library.\n";
		return;
	}

	//using temporary buffer	
	char* temp = new char[std::strlen(name) + 1];
	std::strcpy(temp, name);
	
	delete[] _name;
	_name = temp;
}
void Book::setAuthor(const char* author)
{
	if (!author)
	{
		std::cout << "Invalid author!\n";
		return;
	}
	
	
	char* temp = new char[std::strlen(author) + 1];
	std::strcpy(temp, author);

	delete[] _author;
	_author = temp;
}
void Book::setStatus(bool isAvailable)
{
	_isAvailable = isAvailable;
}


void Book::setUser(const User& user)
{
	_user = user;
}
void Book::resetUser()
{
	_user = User();
}
//getters
const char* Book::getName() const
{
	return _name;
}

const char* Book::getAuthor() const
{
	return _author;
}
bool Book::getStatus() const
{
	return _isAvailable;
}
User Book::getUser() const
{
	return _user;
}
size_t Book::getId() const {
	return _id;
}
void Book::printName()
{
	size_t size = std::strlen(_name);
	for (size_t i = 0; i < size + 1; ++i)
	{
		std::cout << _name[i];
	}
}
