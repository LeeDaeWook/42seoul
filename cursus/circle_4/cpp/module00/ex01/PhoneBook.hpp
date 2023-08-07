#pragma once
#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];

		void		printCol(int i);
		int			atoi(const std::string& str);
		std::string checkLen(std::string str);
		void		checkInput();
	
	public:
		int		idx;
		
		void	add();
		void	search();
		void 	input(std::string &input, std::string msg);
};

#endif
