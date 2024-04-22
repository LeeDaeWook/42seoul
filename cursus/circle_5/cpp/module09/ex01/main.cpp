#include "RPN.hpp"

void check_leaks()
{
	system("leaks RPN");
}

int	main(int argc, char *argv[])
{	
	if (argc != 2) {
		std::cout << "Error :Only one argument available" << std::endl;
		exit(1);
	}
    RPN rpn;
    std::cout << rpn.calculate(argv) << std::endl;

	// atexit(check_leaks);

	return 0;
}

