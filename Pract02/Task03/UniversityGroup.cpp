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
