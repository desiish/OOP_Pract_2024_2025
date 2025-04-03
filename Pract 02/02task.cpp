#include <iostream>

struct Student {  
    int facultyNum = 0;
    int currentCourse = 0;
   float averageGrade = 0;
  
   Student(int number = 0, int course = 0, float grade = 0.0f)
       : facultyNum(number), currentCourse(course), averageGrade(grade) {
   }

    ~Student() {
        std::cout << "Destructor called for " << facultyNum << std::endl;
    }

    void display() const {
        std::cout << "Faculty Number: " << facultyNum
            << ", Course: " << currentCourse
            << ", Average Grade: " << averageGrade << std::endl;
    }
};

void inputStudentData(Student& student) {
    std::cout << "Enter Faculty Number: ";
    std::cin >> student.facultyNum;

    std::cout << "Enter Current Course (1-4): ";
    std::cin >> student.currentCourse;

    std::cout << "Enter Average Grade: ";
    std::cin >> student.averageGrade;
}

void findStudentByFacultyNumber(Student* students, int size, int facultyNum) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (students[i].facultyNum == facultyNum) {
            students[i].display(); 
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student with Faculty Number " << facultyNum << " not found.\n";
    }
}

int main() {
    int size;
    std::cout << "How many students do you want to add? \n";
    std::cin >> size;
    Student* students = new Student[size];

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter data for student " << i + 1 << ":\n";
        inputStudentData(students[i]);
    }

    int searchFacultyNum;
    std::cout << "\nEnter the faculty number to search for: ";
    std::cin >> searchFacultyNum;

    findStudentByFacultyNumber(students, size, searchFacultyNum);
    
    delete[] students;
}
