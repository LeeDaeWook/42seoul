#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
	PhoneBook 	phoneBook;
	Contact		contact;
	std::string command;

	phoneBook.input(command, "None");
	phoneBook.idx = 0;
	while (!command.empty())
	{
		if (!command.compare("ADD") || !command.compare("add"))
			phoneBook.add();
		else if (!command.compare("SEARCH") || !command.compare("search"))
			phoneBook.search();
		else if (!command.compare("EXIT") || !command.compare("exit"))
			exit(EXIT_SUCCESS);
		phoneBook.input(command, "input command: ");
	}
	return 0;
}