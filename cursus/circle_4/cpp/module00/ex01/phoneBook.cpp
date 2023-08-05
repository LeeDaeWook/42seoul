#include "PhoneBook.hpp"

void PhoneBook::add()
{
	int i;
	Contact newContact;

	input(newContact.first_name, "first name : ");
	input(newContact.last_name, "last name : ");
	input(newContact.nick_name, "nickname : ");
	input(newContact.phone_number, "phone number : ");
	input(newContact.darkest_secret, "darkest secret : ");

	i = 0;
	while (i < idx)
	{
		if ((contact[i]).phone_number == newContact.phone_number)
			return;
		i++;
	}
	contact[idx % 8] = newContact;
	idx++;
}

void PhoneBook::search()
{
	int i = 0;
	int limit = idx < 8 ? idx : 8;
	std::string index;

	i = 0;
	if (!idx)
	{
		std::cout << "There are no contacts in phone book" << std::endl;
		return;
	}
	// while (i < idx)
	// {
	// 	std::cout << i << " | ";
	// 	std::cout << contact[i].first_name << " | ";
	// 	std::cout << contact[i].last_name << " | ";
	// 	std::cout << contact[i].nick_name << std::endl;
	// 	i++;
	// }
	while (i < limit)
	{
		std::cout << i << " | ";
		printCol(contact[i].first_name);
		printCol(contact[i].last_name);
		printCol(contact[i].nick_name);
		std::cout << std::endl;
		i++;
	}
	input(index, "input index: ");
	i = atoi(index);
	if (i < limit)
	{
		std::cout << i << std::endl;
		std::cout << contact[i].first_name << std::endl;
		std::cout << contact[i].last_name << std::endl;
		std::cout << contact[i].nick_name << std::endl;
	}
	else
		std::cout << "There is no contact in that index" << std::endl;
}

void PhoneBook::printCol(std::string target)
{
	int len;

	len = target.length();
	if (len >= 10)
	{
		target.resize(9);
		std::cout << target << ".";
	}
	else
	{
		std::cout << target;
		while (len < 10) {
			std::cout << " ";
			len++;
		}
	}
	// if (flag == NEWLINE)
	// 	std::cout << std::endl;
	// else
	// 	std::cout << "|";

}

int PhoneBook::atoi(const std::string& str)
{
    int result = 0;
    int sign = 1;
    size_t i = 0;

    while (i < str.length() && str[i] == ' ')
        i++;
    if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    while (i < str.length() && std::isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}

void PhoneBook::input(std::string &container, std::string msg)
{
	if (msg.compare("None"))
		std::cout << msg;
	std::getline(std::cin, container);
	if (std::cin.eof()) {
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << std::endl;
		exit(EXIT_FAILURE);
	}
}
