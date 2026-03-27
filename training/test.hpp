#ifndef TEST_HPP
# define TEST_HPP
# include <string>
# include <iostream>

class	car
{
	public:
		std::string	make;
		int			year;
		void	changeMake(std::string newMake);
		
		car(std::string input1, int input2);
		~car();
};

#endif