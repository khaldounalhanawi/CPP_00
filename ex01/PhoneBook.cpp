#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::AddBook(int IndexPosition)
{
	Contact		NewContact;
	std::string	buffer;
	int			i;

	NewContact.id = IndexPosition;
	i = 0;
	while (i < CategoryCount)
	{
		std::cout<< RED<<"Please enter your "<< names[i]<< " :"<< RESET<<std::endl;
		std::getline (std::cin, buffer); // make sure it is not empty // edge case
		NewContact.SetField (i, buffer);
		i ++;
	}
	this->_ContactList[IndexPosition] = NewContact;
	std::cout<< GREEN<<"New contact has been saved!"<< RESET<<std::endl;
	return;
}

void	PrintSeperator(int ColumnCount, int ColumnWidth, bool edge)
{
	if (edge)
	{
		std::cout<< RESET<<" "<< std::string((ColumnWidth * ColumnCount) + ColumnCount - 1, '-')<< " "<< std::endl;
		return;
	}
	while (ColumnCount)
	{
		std::cout<< RESET<< "|"<< std::string(ColumnWidth, '-');
		ColumnCount --;
	}
	std::cout<< RESET<< "|"<< std::endl;
}

void	PrintHeader(int ColumnCount, int ColumnWidth, std::string *HeadersContent)
{
	int	i;

	i = 0;
	while (i < ColumnCount)
	{
		std::cout<< RESET<< "|"<< std::setw (ColumnWidth)<< std::right <<HeadersContent[i];
		i ++;
	}
	std::cout<< RESET<< "|"<< std::endl;
	return;
}

void	PhoneBook::search(void) const
{
	int	i;
	int	j;
	static const int ColumnCount = 4;
	static const int ColumnWidth = 10;
	std::string headers[ColumnCount] = {"Index", "First name", "Last name", "Nickname"};
	std::string content[4];

	if (this->_ContactList[0].id == -1)
	{
		std::cout<< RESET<< "PhoneBook is empty! please use the 'add' function to fill it."<< std::endl;
		return;
	}

	PrintSeperator (ColumnCount, ColumnWidth, true);
	PrintHeader (ColumnCount, ColumnWidth, headers);
	i = 0;
	while (i < BookCapacity)
	{
		if (this->_ContactList[i].id != -1)
		{
			PrintSeperator (ColumnCount, ColumnWidth, false);
			content[0] = this->_ContactList[i].id + '0';
			content[1] = this->_ContactList[i].GetField (0);
			content[2] = this->_ContactList[i].GetField (1);
			content[3] = this->_ContactList[i].GetField (2);
			PrintHeader (ColumnCount, ColumnWidth, content);
		}
		i ++;
	}
	PrintSeperator (ColumnCount, ColumnWidth, true);
	return;
}

void	PhoneBook::ExitBook(void)
{
	return;
}
