#pragma once
#include "Student.h"

constexpr unsigned short MAX_GROUP_STUDENTS = 20;

struct UniversityGroup {

    Student students[MAX_GROUP_STUDENTS];
    float averageGrade;
};

void initGroup(UniversityGroup& group);
int getScholarshipStudentsCount(const UniversityGroup& group, float minGrade);
