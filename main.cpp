#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "address.h"
#include "date.h"
#include "student.h"

void loadStudents(std::vector<Student*>& vector);
void printStudents(std::vector<Student*>& vector);
void showStudents(std::vector<Student*>& vector);
void findStudent(std::vector<Student*>& vector);
void delStudents(std::vector<Student*>& vector);

void menu();

void testAddress();
void testDate();
void testStudent();

int main() {
	bool test = false;

	if(test) {
		testDate();
		testAddress();
		testStudent();
	} 
	else {
		menu();
	}
	return 0;

}

void loadStudents(std::vector<Student*>& vector) {
	std::stringstream ss;

	std::ifstream file ("students.csv");
	std::string line;

	if(file.is_open()) {
		while(getline(file, line)) {
			Student* student = new Student();
			student->init(line);
			
			vector.push_back(student);
		}
	}
	else {
		std::cout << "Unable to open file." << std::endl;
	}
}

void printStudents(std::vector<Student*>& vector) {
	// Using modern iteration for c++ 11+
	for(auto& student: vector) {
		student->printStudent();
		std::cout << "----------------------------" << std::endl;
	}
}

void showStudentNames(std::vector<Student*>& vector) {
	for(auto& student: vector) {
		std::cout << student->getLastFirst() << std::endl;
	}
}

void findStudent(std::vector<Student*>& vector) {
	std::string response;

	std::cout << "last name of student: ";
	std::cin >> response;

	for(auto& student: vector) {
		if((student->getLastFirst()).find(response) != std::string::npos)
			student->printStudent();
	}
}

void delStudents(std::vector<Student*>& vector) {
	for(auto& student: vector) {
		delete student;
	}

	vector.clear();
}

void menu() {
	std::vector<Student*> students;
	loadStudents(students);

	bool keepGoing = true;
	while(keepGoing) {
		std::cout << "0) quit" << std::endl;
		std::cout << "1) print all student data" << std::endl;
		std::cout << "2) print all student names" << std::endl;
		std::cout << "3) find a student" << std::endl;
		std::cout << "" << std::endl;

		std::string menu_selection;

		std::cout << "please choose 0-3: ";
		std::cin >> menu_selection;
		std::cout << "" << std::endl;

		// Quit
		if(menu_selection == "0") { 
			delStudents(students);
			keepGoing = false;
		}
		// Print all student names
		else if(menu_selection == "1") {
			printStudents(students);
		}
		// Print all student data
		else if(menu_selection == "2") {
			showStudentNames(students);
		}
		// Find a student
		else if(menu_selection == "3") {
			findStudent(students);
		}
		else {
			std::cout << "Invalid Input. Try again..." << std::endl;
		}

		std::cout << "" << std::endl;
	}
}

void testAddress() {
	Address a;
	a.init("123 W Main St", "Muncie", "IN", "47303");
	a.printAddress();
}

void testDate() {
	Date d;
	d.init("01/27/1997");
	d.printDate();
}

void testStudent() {
	std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jameside,IN,59379,02/17/2004,05/15/2027,65";
	Student* student = new Student();
	student->init(studentString);
	student->printStudent();
	std::cout << std::endl;
	std::cout << student->getLastFirst() << std::endl;
	delete student;
}
