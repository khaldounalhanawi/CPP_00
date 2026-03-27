#include "test.hpp"
#include <iostream>

int	main(void)
{
	car first ("Mercedez", 1996);

	first.changeMake ("BMW");
	std::cout<< "Modified: "<< first.make<<std::endl;

	return (0);
}