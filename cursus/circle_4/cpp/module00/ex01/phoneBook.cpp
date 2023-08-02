#include "PhoneBook.hpp"

Contact::Contact()
{
	
}

Contact::Contact(Contact &new_contact)
{
	first_name = new_contact.first_name;
	last_name = new_contact.last_name;
	nick_name = new_contact.nick_name;
	phone_number = new_contact.phone_number;
	darkest_secret = new_contact.darkest_secret;
}

void PhoneBook::add(Contact &new_contact)
{
	int i;

	i = 0;
	while (i < idx)
	{
		if ((contact[i]).phone_number == new_contact.phone_number)
			return;
		i++;
	}
	if (idx == 8)
		contact[0] = Contact(new_contact);
	else
	{
		contact[idx] = Contact(new_contact);
		idx++;
	}
}

void PhoneBook::search(void)
{
	int i;
	std::string j;

	i = 0;
	if (!idx)
	{
		std::cout << "There are no contacts in phone book" << std::endl;
		return;
	}
	while (i < idx)
	{
		std::cout << i << std::endl;
		std::cout << contact[i].first_name << std::endl;
		std::cout << contact[i].last_name << std::endl;
		std::cout << contact[i].nick_name << std::endl;
		i++;
	}
	std::cout << "input index: ";
	std::getline(std::cin, j);
	i = std::stoi(j);
	if (i < idx)
	{
		std::cout << i << std::endl;
		std::cout << contact[i].first_name << std::endl;
		std::cout << contact[i].last_name << std::endl;
		std::cout << contact[i].nick_name << std::endl;
	}
	else
		std::cout << "There is no contact in that index" << std::endl;
}

int main(int argc, char *argv[])
{
	PhoneBook phoneBook;
	Contact	contact;
	std::string command;

	std::getline(std::cin, command);
	phoneBook.idx = 0;
	while (!command.empty())
	{
		if (!command.length())
			exit(EXIT_FAILURE);
		else
		{
			if (!command.compare("ADD"))
			{
				std::cout << "first name : ";
				std::getline(std::cin, contact.first_name);
				std::cout << "last name : ";
				std::getline(std::cin, contact.last_name);
				std::cout << "nickname : ";
				std::getline(std::cin, contact.nick_name);
				std::cout << "phone number : ";
				std::getline(std::cin, contact.phone_number);
				std::cout << "darkest secret : ";
				std::getline(std::cin, contact.darkest_secret);
				phoneBook.add(contact);
			}
			else if (!command.compare("SEARCH"))
				phoneBook.search();
			else if (!command.compare("EXIT"))
				exit(EXIT_SUCCESS);
			std::cout << "input command: ";
			std::getline(std::cin, command);
		}
	}
	return 0;
}
