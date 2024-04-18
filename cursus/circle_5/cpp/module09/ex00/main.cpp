#include "BitcoinExchange.hpp"

void check_leaks()
{
	system("leaks btc");
}

int	main(int argc, char *argv[])
{	
	(void)argc;
	(void)argv;
	BitcoinExchange btc;
	btc.makeDict();

	// atexit(check_leaks);

	return 0;
}

