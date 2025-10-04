#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<sstream>

#include "date.h"
#include "address.h"

class Student {

	protected:
		std::string firstName;
		std::string lastName;

		Address homeAddress;

		Date birthDate;
		Date gradDate;

		std::string credits;	

	public:
		Student();
		void init(std::string data);
		void printStudent();
		std::string getLastFirst();		
};

#endif
