#include "UniversityGroup.h"
#include <iostream>

void initGroup(UniversityGroup& group)
{
	float grade = 0;

	for (int i = 0; i < MAX_GROUP_STUDENTS; i++)
	{
		initStudent(group.students[i]);
		grade += group.students[i].averageGrade;
	}

	group.averageGrade = grade / MAX_GROUP_STUDENTS;
}

int getScholarshipStudentsCount(const UniversityGroup& group, float minGrade)
{
	unsigned int count = 0;

	for (int i = 0; i < MAX_GROUP_STUDENTS; i++)
	{
		if (group.students[i].averageGrade >= minGrade)
			count++;
	}

	return count;
}

static int getScholarshipStudentsCount(const Student* students, float minGrade)
{
	unsigned int count = 0;

	for (int i = 0; i < MAX_GROUP_STUDENTS; i++)
	{
		if (students[i].averageGrade >= minGrade)
			count++;
	}

	return count;
}

static Student* getScholarshipStudents(const Student* students, float minGrade, unsigned int& countOfStudents) {

	countOfStudents = getScholarshipStudentsCount(students, minGrade);

	Student* scholarshipStudents = new Student[countOfStudents];

	unsigned int count = 0;
	for (int i = 0; i < MAX_GROUP_STUDENTS; i++)
	{
		if (students[i].averageGrade >= minGrade)
		{
			scholarshipStudents[count] = students[i];
			count++;
		}
	}

	return scholarshipStudents;
}

static void sortStudents(Student* students, unsigned int countOfStudents)
{
	for (int i = 1; i < countOfStudents; i++) {
		Student currElement = students[i];
		int j = i - 1;

		while (j >= 0 && students[j].averageGrade < currElement.averageGrade) {
			students[j + 1] = students[j];
			j--;
		}

		students[j + 1] = currElement;
	}
}

static void printStudents(const Student* students, unsigned int countOfStudents)
{
	for (int i = 0; i < countOfStudents; i++)
	{
		printStudent(students[i]);
	}
}

void printScolarshipStudentsDescending(const UniversityGroup& group, float minGrade) {
	unsigned int countOfStudents = 0;

	Student* scholarshipStudents = getScholarshipStudents(group.students, minGrade, countOfStudents);
	sortStudents(scholarshipStudents, countOfStudents);
	printStudents(scholarshipStudents, countOfStudents);

	delete[] scholarshipStudents;
}
