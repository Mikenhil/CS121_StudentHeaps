#include <iostream>
#include <string>
#include <sstream>

#include "date.h"
#include "address.h"

#include "student.h"

std::string firstName;
std::string lastName;

Address homeAddress;

Date birthDate;
Date gradDate;

std::string credits;

Student::Student() {
	firstName = "";
	lastName = "";
	credits = "-";
}

void Student::init(std::string data) {	
	std::stringstream ss;

	ss.clear();
	ss.str("");

	ss.str(data);

	getline(ss, firstName, ',');
	getline(ss, lastName, ',');

	std::string street, town, state, zipcode;
	getline(ss, street, ',');
	getline(ss, town, ',');
	getline(ss, state, ',');
	getline(ss, zipcode, ',');

	homeAddress.init(street, town, state, zipcode);

	std::string date0, date1;
	getline(ss, date0, ',');
	getline(ss, date1, ',');
	
	birthDate.init(date0);
	gradDate.init(date1);

	getline(ss, credits);

}

void Student::printStudent() {
	std::cout << firstName << " " << lastName << std::endl;
	homeAddress.printAddress();
	std::cout << "DOB: ";
	birthDate.printDate();

	std::cout << "Grad: ";
	gradDate.printDate();

	std::cout << "Credits: " << credits << std::endl;
}

std::string Student::getLastFirst() {
	return lastName + ", " + firstName;
}
