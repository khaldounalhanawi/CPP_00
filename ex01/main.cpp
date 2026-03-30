#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int	main()
{
	PhoneBook	myPhoneBook;
	std::string	prompt;
	std::string	message;
	int			counter;

	counter = 0;
	message = 
		RESET "Please enter one of these commands:\n"
		BLUE "ADD:\t"
		GREEN "to add a new contact\n"
		BLUE "SEARCH:\t"
		GREEN "to display all your contacts\n"
		BLUE "EXIT:\t"
		GREEN "to exit";
	while (1)
	{
		std::cout<< message<< BLUE<< std::endl;
		std::getline (std::cin, prompt);
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
		if (prompt == "")
		{
			std::cout << "\033[2J\033[H";
			continue;
		}
	}
	std::cout<< RESET<<"Thank you for using my PhoneBook app!"<< RESET<< std::endl;
	return (0);
}

/*
int	main()
{
	int	i;
	Contact NewContact;

	NewContact.id = 33;
	NewContact.SetField (FirstName, "Obama");
	NewContact.SetField (PhoneNumber, "+4922713321");
	NewContact.SetField (NickName, "Who's in?");

	i = 0;
	while (i < CategoryCount)
	{
		std::cout<< NewContact.GetField (i)<< std::endl;
		i ++;
	}

	return (0);
}
	*/