#pragma once
namespace Constants
{
	const int MIN_TEAM_SIZE = 1;
}

class Person
{
private:
	char* _name;
	char* _position;
	int _salary;

	void freeDynamic();
	void copyDynamic(const Person& other);

public:
	Person();
	Person(const char* name, const char* position, int salary);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	//getters
	const char* getName() const;
	const char* getPosition() const;
	int getSalary() const;

	//setters
	void setName(const char* name);
	void setPosition(const char* position);
	void setSalary(int salary);
};
