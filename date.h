#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
	protected:
		std::string month;
		std::string day;
		std::string year;
	
	public:
		Date();
		void init(std::string dateStr);
		void printDate();
};

#endif
