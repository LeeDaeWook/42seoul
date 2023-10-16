#include "ScalarConverter.hpp"

// void check_leaks()
// {
// 	system("leaks ScalarConverter");
// }

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	std::string str = argv[1];
	ScalarConverter::convert(str);

	// atexit(check_leaks);

	return 0;
}

