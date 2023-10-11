#include "ScalarConverter.hpp"

// void check_leaks()
// {
// 	system("leaks ScalarConverter");
// }

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	static ScalarConverter scalarConverter;
	std::string str = argv[1];
	scalarConverter.convert(str);

	// atexit(check_leaks);

	return 0;
}

