#pragma once
#ifndef __CONTACT_H__
# define __CONTACT_H__
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

#endif