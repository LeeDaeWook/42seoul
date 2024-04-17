#include "RPN.hpp"

void check_leaks()
{
	system("leaks RPN");
}

int	main(int argc, char *argv[])
{	
    RPN rpn;
    std::cout << rpn.calculate(argv) << std::endl;

	// atexit(check_leaks);

	return 0;
}

