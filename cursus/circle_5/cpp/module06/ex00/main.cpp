#include "ScalarConverter.hpp"

// void check_leaks()
// {
// 	system("leaks ScalarConverter");
// }

int	main(int argc, char *argv[])
{
	// (void)argc;
	// (void)argv;
	if (argc != 2)
		return 1;
	ScalarConverter scalarConverter;
	std::string str = argv[1];
	try {
		scalarConverter.convert(str);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// // test
	// char *end;
	// double value;
	// value = std::strtod("inf", &end);

	// std::cout << value << std::endl;
	// std::cout << *end << std::endl;

	// std::cout << "\n==========================\n" << std::endl;

	// atexit(check_leaks);

	// std::string str = "123.0f";
	// char *end;
	// double d = std::strtod(str.c_str(), &end);
	// // int num = static_cast<int>(d);
	// std::cout << d << std::endl;
	// std::cout << *(end - 1) << std::endl;

	return 0;
}

