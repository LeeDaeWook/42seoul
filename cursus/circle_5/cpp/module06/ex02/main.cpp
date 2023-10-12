#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// void check_leaks()
// {
// 	system("leaks TypeInfo");
// }

int	main()
{
	Base base;
	Base *ptr;
	ptr = base.generate();
	std::cout << "===========================" << std::endl;
	base.identify(ptr);
	std::cout << "===========================" << std::endl;
	base.identify(*ptr);

	if (ptr)
		delete ptr;

	// atexit(check_leaks);

	return 0;
}

