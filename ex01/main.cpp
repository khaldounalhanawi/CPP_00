#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	myPhoneBook;
	std::string	prompt;
	std::string	message;
	int			counter;

	counter = 0;
	message = "Please enter one of these options:\n\tadd:\tto add a new contact\n\tsearch:\tto display all your contacts\n\texit:\tto exit";
	while (1)
	{
		std::cout<< message<< std::endl;
		std::getline (std::cin, prompt);
		if (prompt == "add")
		{
			myPhoneBook.AddBook (counter % BookCapacity);
			counter ++;
		}
		else if (prompt == "search")
			myPhoneBook.search ();
		else if (prompt == "exit")
			break;
	}
	std::cout<< "Thank you for using my PhoneBook app!"<< std::endl;
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