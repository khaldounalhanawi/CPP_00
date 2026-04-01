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
		Contact	GetContact (int id) const;

	private:
		Contact	_ContactList[BookCapacity];
};

#endif
