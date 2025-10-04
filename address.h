#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

class Address {
	protected:
		std::string street;
		std::string town;
		std::string state;
		std::string zipcode;

	public:
		Address();
		void init(std::string street, std::string town, std::string state, std::string zipcode);
		void printAddress();
};

#endif
