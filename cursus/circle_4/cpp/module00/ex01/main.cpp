#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
	PhoneBook 	phoneBook;
	Contact		contact;
	std::string command;

	if (argc != 1)
		exit(EXIT_FAILURE);
	phoneBook.input(command, "input command: ");
	phoneBook.idx = 0;
	while (!command.empty())
	{
		if (!command.compare("ADD") || !command.compare("add"))
			phoneBook.add();
		else if (!command.compare("SEARCH") || !command.compare("search"))
			phoneBook.search();
		else if (!command.compare("EXIT") || !command.compare("exit"))
			exit(EXIT_SUCCESS);
		else
			std::cout << "You entered wrong command, try again" << std::endl;
		phoneBook.input(command, "input command: ");
	}
	return 0;
}