#include "Person.h"
#pragma warning (disable:4996)
#include <iostream>
#include <stdexcept>
#include <cstring>

//COPY DYNAMIC
void Person::copyDynamic(const Person& other)
{
	_name = new char[std::strlen(other._name) + 1];
	std::strcpy(_name, other._name);

	_position = new char[std::strlen(other._position) + 1];
	std::strcpy(_position, other._position);

}
//FREE DYNAMIC
void Person::freeDynamic()
{
	delete[] _name;
	delete[] _position;

	_name = nullptr;
	_position = nullptr;
}

//OPERATOR=
Person& Person::operator=(const Person& other)
{

	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);
		_salary = other._salary;
	}

	return *this;
}

//COPY CTOR
Person::Person(const Person& other)
	:_salary(other._salary)
{
	copyDynamic(other);
}
//DEF CTOR - for team
Person::Person()
	:_salary(0)
{
	_name = new char[1];
	_name[0] = '\0';

	_position = new char[1];
	_position[0] = '\0';
}

//CTOR
Person::Person(const char* name, const char* position, int salary)
	:_name(nullptr), _position(nullptr), _salary(0)
{
	setSalary(salary);
	setName(name);
	setPosition(position);
	
}

//DTOR
Person::~Person()
{
	freeDynamic();
}


//SETTERS
void Person::setSalary(int salary)
{
	if (salary < 0)
	{
		throw std::invalid_argument("The salary is not right.\n");
	}
	_salary = salary;
}

void Person::setName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument("Name is not valid!\n");
	}
	
	delete[] _name;
	size_t size = std::strlen(name);
	_name = new char[size + 1];
	std::strcpy(_name, name);
	
}

void Person::setPosition(const char* position)
{
	if(!position)
	{
		throw std::invalid_argument("Position is not valid!\n");
	}

	delete[] _position;
	size_t size = std::strlen(position);
	_position = new char[size + 1];
	std::strcpy(_position, position);
}

//GETTERS
int Person::getSalary() const 
{
	return _salary;
}

const char* Person::getName() const
{
	return _name;
}
const char* Person::getPosition() const
{
	return _position;
}
