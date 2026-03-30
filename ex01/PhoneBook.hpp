#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"

static const int	BookCapacity = 8;

class	PhoneBook
{
	public:
		PhoneBook (void);
		~PhoneBook (void);

		void	AddBook (int IndexPosition);
		void	search (void) const;
		void	ExitBook (void);
	
	private:
		Contact	_ContactList[BookCapacity];
};


#endif


// capacity = 8

// ADD
	// If the user enters this command, they are prompted to input the information
	// of the new contact one field at a time. Once all the fields have been completed,
	// add the contact to the phonebook.

// SEARCH

// EXIT