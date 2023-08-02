#pragma once
#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__
# include <iostream>

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

		Contact();
		Contact(Contact &new_contact);
};

class PhoneBook
{
	private:
		Contact	contact[8];
	public:
		int		idx;
	
	void	add(Contact &new_contact);

	void	search(void);
};

#endif