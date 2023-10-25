#include "Array.hpp"

void check_leaks()
{
	system("leaks Array");
}

int	main()
{
	{
		int n = 5;
		Array<int> arr(n);
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		arr[4] = 4;
		try {
			for (int i = 0; i < n; i++)
				std::cout << arr[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n========================\n" << std::endl;

	{
		int n = 5;
		Array<int> arr(n);
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		arr[4] = 4;
		Array<int> arr1 = arr;
		try {
			for (int i = 0; i < n; i++)
				std::cout << arr1[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n========================\n" << std::endl;

	{
		int n = 5;
		Array<int> arr(n);
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		arr[4] = 4;
		try {
			std::cout << arr[5] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n========================\n" << std::endl;

	{
		int n = 5;
		Array<int> arr(n);
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		arr[3] = 4;
		arr[4] = 5;

		Array<int> arr1(n);
		arr1[0] = 10;
		arr1[1] = 20;
		arr1[2] = 30;
		arr1[3] = 40;
		arr1[4] = 50;

		arr = arr1;

		try {
			for (int i = 0; i < n; i++)
				std::cout << arr[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	// atexit(check_leaks);

	return 0;
}