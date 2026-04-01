#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

static const std::string DisplayMessage =
	RESET "Please enter one of these commands:\n"
	BLUE "ADD:\t"
	GREEN "to add a new contact\n"
	BLUE "SEARCH:\t"
	GREEN "to display all your contacts\n"
	BLUE "EXIT:\t"
	GREEN "to exit";

int	main()
{
	PhoneBook	myPhoneBook;
	std::string	prompt;
	int			counter;

	counter = 0;
	while (1)
	{
		std::cout<< DisplayMessage<< BLUE<< std::endl;
		prompt.clear ();
		if (!std::getline (std::cin, prompt))
			break;
		if (prompt == "ADD")
		{
			myPhoneBook.AddBook (counter % BookCapacity);
			counter ++;
		}
		else if (prompt == "SEARCH")
			myPhoneBook.search ();
		else if (prompt == "EXIT")
			break;
		else
		{
			std::cout << "\033[2J\033[H";
			continue;
		}
		std::cout<< RESET<< "Press Enter to continue.."<< std::endl;
		std::getline (std::cin, prompt);
		std::cout << "\033[2J\033[H";
	}
	std::cout<< RESET
			 <<"Thank you for using my PhoneBook app!"
			 << RESET
			 << std::endl;
	return (0);
}
