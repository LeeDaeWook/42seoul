#include "phoneBook.hpp"

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
	std::cin >> i;
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

	phoneBook.idx = 0;
	while (true)
	{
		if (argc <= 1)
			exit(EXIT_FAILURE);
		else
		{
			if (!std::strcmp(argv[1], "ADD"))
			{
				std::cout << "first name : ";
				std::cin >> contact.first_name;
				std::cout << "last name : ";
				std::cin >> contact.last_name;
				std::cout << "nickname : ";
				std::cin >> contact.nick_name;
				std::cout << "phone number : ";
				std::cin >> contact.phone_number;
				std::cout << "darkest secret : ";
				std::cin >> contact.darkest_secret;
				phoneBook.add(contact);
			}
			else if (!std::strcmp(argv[1], "SEARCH"))
				phoneBook.search();
			else if (!std::strcmp(argv[1], "EXIT"))
				exit(EXIT_SUCCESS);
		}
		std::cout << "input command: ";
		std::cin >> argv[1];
	}
	return 0;
}