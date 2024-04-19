#include "BitcoinExchange.hpp"

void check_leaks()
{
	system("leaks btc");
}

int	main(int argc, char *argv[])
{	
	// (void)argv;
	// (void)argc;
	if (argc != 2) {
        std::cout << "Error : Only one file available" << std::endl;
		exit(1);
	}

	BitcoinExchange btc;
	btc.makeDict();
	btc.calculate(argv[1]);

    // std::map<std::string, double> dict;
	// dict.insert(std::make_pair("key", 0));
	// std::string str = "0.08";
	// dict["key"] = std::strtod(str.c_str(), NULL);
	// std::cout << dict["key"] << std::endl; 
	// // std::cout << btc.dict["2022-03-30"] << std::endl; 
	
	// atexit(check_leaks);

	return 0;
}

