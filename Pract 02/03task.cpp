#include <iostream>

struct Student {
    int facultyNum;
    float averageGrade;
 
    Student(int number = 0, float grade = 0.0f)
        : facultyNum(number), averageGrade(grade) {}
  
    void display() const {
        std::cout << "Faculty Number: " << facultyNum        
            << ", Average Grade: " << averageGrade << std::endl;
    }
};

struct Group {
    int numStudents;
    Student* students;
    float averageGroupGrade;
    
    Group(int size) : numStudents(size), averageGroupGrade(0.0f) {
        students = new Student[size];
    }

    ~Group() {
        delete[] students;
    }
};


void createGroup(Group& group) {
    float totalGrade = 0.0f;
    for (int i = 0; i < group.numStudents; ++i) {
        std::cout << "Enter infromation for student: " << i + 1 << "\n";
        std::cout << "Enter faculty number: ";
        std::cin >> group.students[i].facultyNum;
        std::cout << "Enter average grade of the student: ";
        std::cin >> group.students[i].averageGrade;

        totalGrade += group.students[i].averageGrade;
    }
    group.averageGroupGrade = totalGrade / group.numStudents;
}

int countScholarshipStudents(const Group& group, float minGrade) {
    int count = 0;
    for (int i = 0; i < group.numStudents; ++i) {
        if (group.students[i].averageGrade >= minGrade) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;
    std::cout << "Enter the number of students in the group: \n";
    std::cin >> size;

    Group group(size); 
    createGroup(group);

    std::cout << "\nAverage grade of the group: " << group.averageGroupGrade << std::endl << "\n";
    float minScholarshipGrade;
    std::cout << "Enter minimum grade for a scholarship: ";
    std::cin >> minScholarshipGrade;
    int scolarshipStudents = countScholarshipStudents(group, minScholarshipGrade);
    std::cout << "Number of students with scholarship: " << scolarshipStudents << std::endl;


}
