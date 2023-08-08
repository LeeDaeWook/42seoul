#include "Harl.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
		exit(EXIT_FAILURE);

	Harl harl;

	harl.complain(argv[1]);
	return 0;
}