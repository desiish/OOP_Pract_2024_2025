#include "Student.h"
#include <iostream>

static void validateCourse(unsigned short& course)
{
	do {
		std::cout << "Enter course(number from 1 to 4): ";
		std::cin >> course;
	} while (course < 1 || course >4);
}

static void validateFacultyNumber(unsigned int& facultyNumber)
{
	do {
		std::cout << "Enter faculty number(5 digit number): ";
		std::cin >> facultyNumber;
	} while (facultyNumber < 10000 || facultyNumber >99999);
}

static void validateAverageGrade(float& avrgGrade)
{
	do {
		std::cout << "Enter average grade: ";
		std::cin >> avrgGrade;
	} while (avrgGrade < 2 || avrgGrade> 6);
}

void initStudent(Student& student)
{
	validateCourse(student.course);
	validateFacultyNumber(student.facultyNumber);
	validateAverageGrade(student.averageGrade);
}

void printStudent(const Student& student)
{
	std::cout << "Student course: " << student.course << "\n";
	std::cout << "Student faculty number: " << student.facultyNumber << '\n';
	std::cout << "Student average grade: " << student.averageGrade << "\n";
}