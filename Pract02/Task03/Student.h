#pragma once

struct Student {
    unsigned int facultyNumber;
    float averageGrade;
    unsigned short course;

};

void printStudent(const Student& student);
void initStudent(Student& student);
