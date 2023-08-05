#pragma once
#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__
# include <iostream>
# include "Contact.hpp"

# define NEWLINE 1

class PhoneBook
{
	private:
		Contact	contact[8];
	public:
		int		idx;

	void	add();
	void	search();
	void	printCol(std::string target);
	void 	input(std::string &container, std::string msg);
	int		atoi(const std::string& str);
};

#endif