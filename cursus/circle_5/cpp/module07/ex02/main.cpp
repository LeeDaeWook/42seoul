#include "Array.hpp"

void check_leaks()
{
	system("leaks Array");
}

int	main()
{
	Array<int> arr(10);
	Array<int> arr1 = arr;
	try {
		std::cout << arr[16] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	atexit(check_leaks);

	return 0;
}