#include <iostream>

struct Student {
    int facultyNum;
    double averageGrade;

    Student(int number = 0, double grade = 0.0)
        : facultyNum(number), averageGrade(grade) {}

    void display() const {
        std::cout << "Faculty Number: " << facultyNum
            << ", Average Grade: " << averageGrade << std::endl;
    }
};

struct Group {
    int numStudents;
    Student* students;
    double averageGroupGrade;

    Group(int size) : numStudents(size), averageGroupGrade(0.0) {
        students = new Student[size];
    }

    ~Group() {
        delete[] students;
    }
};

void createGroup(Group& group) {
    double totalGrade = 0.0;
    for (int i = 0; i < group.numStudents; ++i) {
        std::cout << "Enter information for student " << i + 1 << ":\n";
        std::cout << "Enter faculty number: ";
        std::cin >> group.students[i].facultyNum;
        std::cout << "Enter average grade of the student: ";
        std::cin >> group.students[i].averageGrade;

        totalGrade += group.students[i].averageGrade;
    }
    group.averageGroupGrade = totalGrade / group.numStudents;
}

int countScholarshipStudents(const Group& group, double minGrade) {
    int count = 0;
    for (int i = 0; i < group.numStudents; ++i) {
        if (group.students[i].averageGrade >= minGrade) {
            count++;
        }
    }
    return count;
}

void createScholars(Group& scholars, const Group& group, double minGrade) {
    int count = 0;
    for (int i = 0; i < group.numStudents; ++i) {
        if (group.students[i].averageGrade >= minGrade) {
            scholars.students[count] = group.students[i];
            count++;
        }
    }
}

void displayScholars(const Group& scholars) {
    std::cout << "\nList of students who receive scholarships:\n";
    for (int i = 0; i < scholars.numStudents; ++i) {
        scholars.students[i].display();
    }
}

int main() {
    int size;
    std::cout << "Enter the number of students in the group: ";
    std::cin >> size;

    Group group(size);
    createGroup(group);

    std::cout << "\nAverage grade of the group: " << group.averageGroupGrade << "\n";

    double minScholarshipGrade;
    std::cout << "Enter minimum grade for a scholarship: ";
    std::cin >> minScholarshipGrade;

    int scholarshipCount = countScholarshipStudents(group, minScholarshipGrade);
    std::cout << "Number of students with scholarship: " << scholarshipCount << std::endl;

    if (scholarshipCount > 0) {
        Group scholars(scholarshipCount);
        createScholars(scholars, group, minScholarshipGrade);
        displayScholars(scholars);
    }
    else {
        std::cout << "No students qualify for a scholarship.\n";
    }
}
