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
			return ;
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
	while (i < limit)
		printCol(i++);
	input(index, "Input index: ");
	i = atoi(index);
	if (i < limit)
	{
		std::cout << "Index: " << i << std::endl;
		std::cout << "First name: " << contact[i].first_name << std::endl;
		std::cout << "Last name: " << contact[i].last_name << std::endl;
		std::cout << "Nick name: " << contact[i].nick_name << std::endl;
	}
	else
		std::cout << "There is no contact in that index" << std::endl;
}

void PhoneBook::printCol(int i)
{
	std::cout << std::setw(10);
	std::cout << i << "|";
	std::cout << std::setw(10);
	std::cout << checkLen(contact[i].first_name) << "|";
	std::cout << std::setw(10);
	std::cout << checkLen(contact[i].last_name) << "|";
	std::cout << std::setw(10);
	std::cout << checkLen(contact[i].nick_name) << "|";
	std::cout << std::endl;
}

std::string PhoneBook::checkLen(std::string str)
{
	if (str.size() >= 10) {
		str.resize(9);
		str.append(".");
	}
	return str;
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
	if (result == 0 && str != "0")
		return 2147483647;
    return sign * result;
}

void PhoneBook::input(std::string &input, std::string msg)
{
	std::cout << msg;
	std::getline(std::cin, input);
	checkInput();
	if (input.empty())
	{
		while (input.empty())
		{
			std::cout << "You entered nothing, try again: ";
			std::getline(std::cin, input);
			checkInput();
		}
	}
}

void PhoneBook::checkInput()
{
	if (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Program finished by reaching EOF" << std::endl;
		exit(EXIT_FAILURE);
	}
}