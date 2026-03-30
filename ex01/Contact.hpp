#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

enum
{
	FirstName,
	LastName,
	NickName,
	PhoneNumber,
	DarkestSecret,
	CategoryCount
};

static std::string names[CategoryCount] =
{
	"first name",
	"last name",
	"nick name",
	"phone number",
	"darkest secret"
};

class	Contact
{
	public:
		Contact (void);
		~Contact (void);

		int			id;
		std::string	GetField(int category) const;
		void		SetField(int category, std::string content);

	private:
		std::string	_fields[CategoryCount];
};

#endif