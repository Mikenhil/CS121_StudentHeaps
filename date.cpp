#include <iostream>
#include <string>
#include <sstream>

#include "date.h"

std::string month;
std::string day;
std::string year;

Date::Date() {
	month = "";
	day = "";
	year = "";
}

void Date::init(std::string date) {
	std::string months[13] = {"null", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	std::stringstream ss;
	std::stringstream convert;

	ss.clear();
	ss.str("");

	convert.clear();
	convert.str("");

	ss.str(date);
	
	std::string tempMonth = "";
	int monthNum = 0;

	getline(ss, tempMonth, '/');
	getline(ss, day, '/');
	getline(ss, year);

	convert << tempMonth;
	convert >> monthNum;

	month = months[monthNum];
}

void Date::printDate() {
	std::cout << month << " " << day << ", " << year << std::endl;
}
