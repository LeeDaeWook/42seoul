#include "BitcoinExchange.hpp"

void check_leaks()
{
	system("leaks btc");
}

int	main(int argc, char *argv[])
{	
	if (argc != 2) {
        std::cout << "Error : Only one file available" << std::endl;
		exit(1);
	}

	BitcoinExchange btc;
	btc.makeDict();
	btc.calculate(argv[1]);
	
	atexit(check_leaks);

	return 0;
}

