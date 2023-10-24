#include "Span.hpp"

// void check_leaks()
// {
// 	system("leaks Span");
// }

int	main()
{	
	{
		std::cout << "CASE 1 : addNumber()로 수를 넣는 경우" << std::endl;

		unsigned int n = 10;
		Span span(n);

		int result1 = 0;
		int result2 = 0;

		try {
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
			result1 = span.shortestSpan();
			result2 = span.longestSpan();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "Shortest span: " << result1 << std::endl;
		std::cout << "Longest span: " << result2 << std::endl;
	}

	std::cout << "\n=======================\n" << std::endl;

	{
		std::cout << "CASE 2 : n보다 많은 수를 리스트에 넣을 때" << std::endl;

		unsigned int n = 1;
		Span span(n);

		int result1 = 0;
		int result2 = 0;
		try {
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
			result1 = span.shortestSpan();
			result2 = span.longestSpan();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "Shortest span: " << result1 << std::endl;
		std::cout << "Longest span: " << result2 << std::endl;
	}

	std::cout << "\n=======================\n" << std::endl;

	{
		std::cout << "CASE 3 : addNumbers()로 한 번에 일정 범위의 수를 넣을 때" << std::endl;

		unsigned int n = 10000;
		Span span(n);

		std::list<int> lst;
		unsigned int start = 1;
		unsigned int end = 10000;

		for (unsigned int i = start; i <= end; ++i) {
		    lst.push_back(i);
		}

		int result1 = 0;
		int result2 = 0;

		try {
			span.addNumbers(1000, lst.begin(), lst.end());
			result1 = span.shortestSpan();
			result2 = span.longestSpan();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "Shortest span: " << result1 << std::endl;
		std::cout << "Longest span: " << result2 << std::endl;
	}

	// atexit(check_leaks);

	return 0;
}

