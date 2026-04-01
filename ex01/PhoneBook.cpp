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

Contact	PhoneBook::GetContact (int id) const
{
	return (this->_ContactList[id]);
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
		std::cout<< RED
				 <<"Please enter your "
				 << names[i]
				 << " :"
				 << RESET
				 <<std::endl;
		buffer.clear ();
		while (buffer.empty ())
			if (!std::getline (std::cin, buffer))
				break;
		NewContact.SetField (i, buffer);
		i ++;
	}
	this->_ContactList[IndexPosition] = NewContact;
	std::cout<< GREEN
			 <<"New contact has been saved!"
			 << RESET
			 <<std::endl;
	return;
}

void	PrintSeperator(int ColumnCount, int ColumnWidth, bool edge)
{
	if (edge)
	{
		std::cout<< RESET
				 <<" "
				 << std::string((ColumnWidth * ColumnCount) + ColumnCount - 1, '-')
				 << " "
				 << std::endl;
		return;
	}
	while (ColumnCount)
	{
		std::cout<< RESET
				 << "|"
				 << std::string(ColumnWidth, '-');
		ColumnCount --;
	}
	std::cout<< RESET
			 << "|"
			 << std::endl;
}

void	PrintContent(int ColumnCount, int ColumnWidth, std::string *Content)
{
	int			i;
	std::string	SubString;

	i = 0;
	while (i < ColumnCount)
	{
		if ((int) Content[i].size () >= ColumnWidth)
			SubString = Content[i].substr (0, ColumnWidth - 1) + ".";
		else
			SubString = Content[i];
		std::cout<< RESET
				 << "|"
				 << std::setw (ColumnWidth)
				 << std::right
				 << SubString;
		i ++;
	}
	std::cout<< RESET
			 << "|"
			 << std::endl;
	return;
}

void	PrintTable(int ColumnCount, int ColumnWidth, const PhoneBook *book, std::string headers[])
{
	int	i;
	std::string content[ColumnCount];

	PrintSeperator (ColumnCount, ColumnWidth, true);
	PrintContent (ColumnCount, ColumnWidth, headers);
	i = 0;
	while (i < BookCapacity)
	{
		if (book->GetContact(i).id != -1)
		{
			PrintSeperator (ColumnCount, ColumnWidth, false);
			content[0] = book->GetContact(i).id + '0';
			content[1] = book->GetContact(i).GetField (0);
			content[2] = book->GetContact(i).GetField (1);
			content[3] = book->GetContact(i).GetField (2);
			PrintContent (ColumnCount, ColumnWidth, content);
		}
		i ++;
	}
	PrintSeperator (ColumnCount, ColumnWidth, true);
}

		// if (book->_ContactList[i].id != -1)


void	PhoneBook::search(void) const
{
	std::string headers[4] = {"Index", "First name", "Last name", "Nickname"};

	if (this->_ContactList[0].id == -1)
	{
		std::cout<< RESET
				 << "PhoneBook is empty! "
					"please use the 'add' function to fill it."
				 << std::endl;
		return;
	}
	PrintTable(4, 10, this, headers);
	return;
}
