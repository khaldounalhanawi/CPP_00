#include "test.hpp"
#include <iostream>
#include <string>

car::car(std::string input1, int input2):
make (input1),
year (input2)
{
	std::cout<< "Brand: "<< this->make<< ", "<<this->year<< "is submitted"<<std::endl;
	return;
}

car::~car(void)
{
	std::cout<< "Safe journey!"<< std::endl;
	return;
}

void	car::changeMake(std::string newMake)
{
	this->make = newMake;
	return;
}