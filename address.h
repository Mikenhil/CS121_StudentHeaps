#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

class Address {

	string street;
	string town;
	string state;
	int zipcode;

	public:
		Address();
		void init(string street, string town, string state, int zipcode);
		void printAddress();
};

#endif
