#include "easyfind.hpp"

void check_leaks()
{
	system("leaks easyfind");
}

int	main()
{	
	std::list<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);

	try {
		std::cout << *(easyfind(arr, 5)) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Not found!" << std::endl;
	}

	try {
		std::cout << *(easyfind(arr, 100)) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Not found!" << std::endl;
	}

	atexit(check_leaks);

	return 0;
}

