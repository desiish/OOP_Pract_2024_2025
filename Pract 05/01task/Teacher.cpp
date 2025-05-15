#include "Teacher.h"
#include <cstring>


void Teacher::freeDynamic()
{
	delete[] _name;
	_name = nullptr;
}

void Teacher::copyDynamic(const Teacher& other)
{
	_name = new char[std::strlen(other._name) + 1];
	std::strcpy(_name, other._name);
}

Teacher::Teacher(const Teacher& other)
	:_name(nullptr), _age(other._age), _subject(other._subject), _salary(other._salary)
{
	//std::strcpy(_name, other._name);
	copyDynamic(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);

		_age = other._age;
		//std::strcpy(_name, other._name);
		_subject = other._subject;
		_salary = other._salary;

	}
	return *this;
}

Teacher::Teacher(const char* name, int age, Teacher::Subject subject, double salary)
	:_name(nullptr), _age(18), _subject(subject), _salary(501)
{
	setName(name);
	setAge(age);
	setSubject(subject);
	setSalary(salary);
}

Teacher::~Teacher()
{
	freeDynamic();
}


void Teacher::setName(const char* name) 
{
	if (!name)
	{	
		throw std::invalid_argument("Name is not valid!\n");
	}
	if (_name)
	{
		delete[] _name;	
	}
	size_t size = std::strlen(name);
	_name = new char[size + 1];
	std::strcpy(_name, name);
}

void Teacher::setAge(int age) 
{
	if (age < 18 || age > 70)
	{
		throw std::invalid_argument("Invalid age.\n");
	}
	_age = age;
}

void Teacher::setSalary(double salary)
{
	if (salary <= 500)
	{
		throw std::invalid_argument("Salary must be more than 500.\n");
	}
	_salary = salary;
}

void  Teacher::setSubject(Teacher::Subject subject)
{
	_subject = subject;
}

const char* Teacher::getName() const
{
	return _name;
}

int Teacher::getAge() const
{
	return _age;
}
Teacher::Subject Teacher::getSubject() const
{
	return _subject;
}
double Teacher::getSalary() const
{
	return _salary;
}
//for the stream if it was text file
const char* Teacher::subjectToString(Teacher::Subject s)
{
	switch (s)
	{
	case Subject::MATH: return "MATH";
	case Subject::ENGLISH: return "ENGLISH";
	case Subject::HISTORY: return "HISTORY";
	default: return "UNKNOWN";
	}
}
//
//Teacher::Subject Teacher::stringToSubject(const std::string& str)
//{
//	if (str == "MATH") return Subject::MATH;
//	if (str == "ENGLISH") return Subject::ENGLISH;
//	if (str == "HISTORY") return Subject::HISTORY;
//
//	throw std::invalid_argument("Invalid subject string: " + str);
//}
void Teacher::print() const
{
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Subject: " << subjectToString(getSubject()) << std::endl;
	std::cout << "Salary: " << getSalary() << std::endl;
}

void Teacher::writeToStream(std::ofstream& writeFile) const
{
	//name
	size_t nameSize = std::strlen(_name);
	writeFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
	writeFile.write(_name, nameSize);

	//age
	writeFile.write(reinterpret_cast<const char*>(&_age), sizeof(_age));

	//subject
	auto subjectValue = static_cast<std::underlying_type<Subject>::type>(_subject);
	writeFile.write(reinterpret_cast<const char*>(&subjectValue), sizeof(subjectValue));

	//salary
	writeFile.write(reinterpret_cast<const char*>(&_salary), sizeof(_salary));
}

void Teacher::readFromStream(std::ifstream& readFile)
{
	//name 
	size_t nameSize;
	readFile.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));

	char* buffer = new char[nameSize + 1];
	readFile.read(buffer, nameSize);
	buffer[nameSize] = '\0';
	setName(buffer);
	delete[] buffer;

	//age
	readFile.read(reinterpret_cast<char*>(&_age), sizeof(_age));

	//subject
	std::underlying_type<Subject>::type subjectValue;
	readFile.read(reinterpret_cast<char*>(&subjectValue), sizeof(subjectValue));
	_subject = static_cast<Subject>(subjectValue);

	//salary
	readFile.read(reinterpret_cast<char*>(&_salary), sizeof(_salary));
}
