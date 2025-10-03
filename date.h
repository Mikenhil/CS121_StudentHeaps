#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
	int month;
	int day;
	int year;

	public:
		Date();
		void init(string dateStr);
		void printDate();
};

#endif
