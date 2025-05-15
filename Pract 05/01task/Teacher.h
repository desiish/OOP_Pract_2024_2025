#pragma once
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)
namespace Constants 
{
	const int SALARY = 500;
}

class Teacher 
{
public:
	enum class Subject
	{
		MATH,
		ENGLISH,
		HISTORY
	};

private:
	char* _name = nullptr;
	int _age = 18;
	Subject _subject = Subject::MATH;
	double _salary = 501;


private:
	void freeDynamic();
	void copyDynamic(const Teacher& other);

public:
	Teacher(const char* name, int age, Subject subject, double salary);
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);
	~Teacher();

	const char* getName() const;
	int getAge() const;
	Subject getSubject() const;
	double getSalary() const;

	void setName(const char* name);
	void setAge(int age);
	void setSubject(Subject subject);
	void setSalary(double salary);

	void writeToStream(std::ofstream& writeFile) const;
	void readFromStream(std::ifstream& readFile);

	//for stream if it was text file
	static const char* subjectToString(Subject s);
	//static Teacher::Subject stringToSubject(const std::string& str);

	void print() const;
};
