#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
enum Subject { NONE ,MATH, ENGLISH, GEOGRAPPHY, HISTORY};

class Teacher {
public:

	// Default constructor
	Teacher() {
		_name[0] = '\0';
		_age = 0;
		_subject = NONE;
		_salary = 0.0;
		_id = 0;
	}

	Teacher(char *n, unsigned int age, Subject subject, double salary, unsigned int id )
		:_age(age), _subject(subject), _salary(salary), _id(id)
	{
		strncpy_s(_name, n, SIZE-1);
		_name[SIZE - 1] = '\0';
	}

	//getters
	const unsigned int getId() const {
		return _id;
	}

	const double getSalary() const {
		return _salary;
	}


	//setters
	void setSubject(Subject subject) {
		_subject = subject;
	}
	void setSalary(double salary) {
		_salary = salary;
	}


public:
	static const int SIZE = 50;
	static const int MAX_TEACHERS = 100;

private:

	char _name[SIZE];
	unsigned short _age;
	Subject _subject;
	double _salary;
	unsigned int _id;

};

void createFile(const char* fileName ){
	std::ofstream writeFile(fileName, std::ios::binary);
	if (!writeFile) {
		std::cerr << "Error opening file";
	}
	writeFile.close();
}
double checkSalary() {
	double sal;
	do {
		std::cout << "Enter salary > 500 \n";
		std::cin >> sal;
	} while (sal <= 500);

	return sal;
}

bool teacherExists(const unsigned int id, std::fstream& file) {

	file.clear();
	file.seekg(0, std::ios::beg);

	Teacher temp;
	while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
		if (temp.getId() == id) {
			return true;
		}
	}
	return false; 

}

Teacher createTeacher() {
	char name[Teacher::SIZE];
	unsigned int age;
	unsigned int subject;
	double salary;
	unsigned int id;

	std::cout << "Enter a name: \n";
	std::cin.ignore();
	std::cin.getline(name, Teacher::SIZE);

	std::cout << "Enter age: \n";
	std::cin >> age;

	std::cout << "Enter subject(0 - MATH, 1 - ENGLISH, 2 - GEOGRAPHY, 3 - HISTORY) : \n";
	std::cin >> subject;

	salary = checkSalary();

	std::cout << "Enter id: \n";
	std::cin >> id;

	return Teacher (name, age, static_cast<Subject>(subject), salary, id);
}


void addTeacher(const char* fileName, int& count, Teacher* teachers) {

	std::fstream file(fileName, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
	if (!file) {
		std::cerr << "Error opening file!\n";
		return;
	}

	std::cout << "Amount of teachers you want to add: \n";
	unsigned int count;
	std::cin >> count;

	for (unsigned int i = 0; i < count; ++i) {
		//create a template for reading if a teacher exists
		Teacher t = createTeacher();

		//check if teacher exists (by id)
		if (teacherExists(t.getId(), file)) {
			std::cout << "Teacher with id: " << t.getId() << " already exists. Try different id.\n";
			i--;
		}
		else {
			file.seekp(0, std::ios::end);
			//add in file
			file.write(reinterpret_cast<char*>(&t), sizeof(Teacher));


			//we will add the teachers in the class
			if (count < Teacher::MAX_TEACHERS) {
				teachers[count] = t;
				count++;
				std::cout << "Teacher added successfully to the file and class.\n";
			}
			else {
				std::cout << "Can't add more teachers. Full\n";
			}
			

		std::cout << "Teacher added successfully to FILE.\n";
			
		}
	}
	file.close();
}
void deleteTeacher(const char* fileName) {
	std::cout << "Enter id you want to delete: \n";
	unsigned int deleteId;
	std::cin >> deleteId;

	//In order to reuse the function, we will use fstream
	std::fstream file(fileName, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
	if (!file) {
		std::cerr << "Error opening file \n";
	}
	if (!teacherExists(deleteId , file)) {
		std::cout << "Teacher with id " << deleteId << " does not exist.\n";
		file.close();
		return;
	}

	//search from beginning
	file.clear();
	file.seekg(0, std::ios::beg);

	Teacher temp;
	char tempName[100] = "C:\\Users\\vikik\\Desktop\\temp.bin";
	std::fstream tempFile(tempName, std::ios::binary | std::ios::out);

	if (!tempFile) {
		std::cerr << "Error opening temporary file!\n";
		file.close();
		return;
	}

	while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
		if (temp.getId() != deleteId) {
			tempFile.write(reinterpret_cast<char*>(&temp), sizeof(Teacher));
		}
	}

	file.close();
	tempFile.close();

	// Now replace the original file with the temporary file, by deleting the original and renaming the new one
	remove(fileName);
	rename(tempName, fileName);

	std::cout << "Teacher with id " << deleteId << " has been deleted.\n";
}


void changeTeacherSubject( std::fstream& file,const unsigned int teacherId, Subject newSubject) {
	//search from beginning
	file.clear();
	file.seekg(0, std::ios::beg);

	Teacher temp;
	bool found = false;

	// Iterate through the file to find the teacher with the matching id
	while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
		if (temp.getId() == teacherId) {
			temp.setSubject(newSubject);  // Update subject using setter
			file.seekp(file.tellg() - static_cast<std::streamoff>(sizeof(Teacher)));  // Move the file pointer back to the right position
			file.write(reinterpret_cast<char*>(&temp), sizeof(Teacher));  // Write the updated object back into the file
			found = true;
			break;
		}
	}

	if (found) {
		std::cout << "Teacher's subject updated successfully.\n";
	}
	else {
		std::cout << "Teacher with ID " << teacherId << " not found.\n";
	}

}


void changeTeacherSubjectMenu(const char* fileName) {

	std::cout << "Enter the id of the teacher whose subject you want to change: \n";
	unsigned int teacherId;
	std::cin >> teacherId;
	std::fstream file(fileName, std::ios::binary | std::ios::in);

	if (!file) {
		std::cerr << "Error opening file!\n";
		return;
	}

	if (teacherExists(teacherId, file)){
		unsigned int subjectChoice;
		std::cout << "Enter the new subject (0 - MATH, 1 - ENGLISH, 2 - GEOGRAPHY, 3 - HISTORY): \n";
		std::cin >> subjectChoice;
		changeTeacherSubject(file, teacherId, static_cast<Subject>(subjectChoice));
	}
	else {
		std::cout << "Teacher with id " << teacherId << " not found.\n";
	}
	file.close();
}
void givePromotion(const unsigned int teacherId, std::fstream& file, const double promotion) {
	//search from beginning
	file.clear();
	file.seekg(0, std::ios::beg);

	Teacher temp;
	bool found = false;
	
	// Iterate through the file to find the teacher with the matching id
	while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
		if (temp.getId() == teacherId) {
			double newSalary = temp.getSalary() + promotion;
			temp.setSalary(newSalary);  // Update subject using setter
			file.seekp(file.tellg() - static_cast<std::streamoff>(sizeof(Teacher)));  // Move the file pointer back to the right position
			file.write(reinterpret_cast<char*>(&temp), sizeof(Teacher));  // Write the updated object back into the file
			found = true;
			break;
		}
	}
}

void givePromotionMenu(const char* fileName) {
	std::cout << "Enter which teacher (id) gets a promotion and the amount to add: \n";
	unsigned int teacherId;
	double promotion;
	std::cin >> teacherId >> promotion;
	std::fstream file(fileName, std::ios::binary | std::ios::in | std::ios::out);
	//check if id exists
	if(!teacherExists(teacherId, file)){
		std::cout << "Teacher with id " << teacherId << "doesnt exist\n";
		return;
	}
	givePromotion(teacherId, file, promotion);

	file.close();
}
int main() {
	Teacher* teachers = new Teacher[Teacher::MAX_TEACHERS];
	int count = 0;
	char fileName[100] = "C:\\Users\\vikik\\Desktop\\teachers.bin";


	//create file
	createFile(fileName);
	//addTeachers by amount
	addTeacher(fileName, count, teachers);
	//delete teacher by id
	deleteTeacher(fileName);
	//change subject
	changeTeacherSubjectMenu(fileName);
	//give promotion
	givePromotionMenu(fileName);
	//delete all teachers
	delete[] teachers;
}
