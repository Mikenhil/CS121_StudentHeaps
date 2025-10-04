#include <iostream>
#include <string>
#include "address.h"

std::string street;
std::string town;
std::string state;
std::string zipcode;

Address::Address() {
	street = "";
	town = "";
	state = "";
	zipcode = "";
}

void Address::init(std::string street, std::string town, std::string state, std::string zipcode) {
	this->street = street;
	this->town = town;
	this->state = state;
	this->zipcode = zipcode;
}

void Address::printAddress() {
	std::cout << street << std::endl;
	std::cout << town << " " << state << ", " << zipcode << std::endl;
}

