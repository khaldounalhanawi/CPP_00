#include "test.hpp"
#include <iostream>
#include <utility>

int	main(void)
{
	// std::pair <std::string, int> car ("porsche",42);
	std::pair <std::string, int> car;
	car = {"BMW", 1997};
	
	



	std::cout<< car.first<< std::endl;


	return (0);
}