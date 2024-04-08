#include "PmergeMe.hpp"

void check_leaks()
{
	system("leaks PmergeMe");
}

int	main(int argc, char *argv[])
{	
    int input[argc-1];

    // 입력
    for (int i = 1; i < argc; i++) {
        int number = std::atoi(argv[i]);
        if (number < 0) {
            std::cout << "Error" << std::endl;
            exit(1);
        }
        input[i-1] = number;
    }

	PmergeMe c1;
	PmergeMe c2;

    c1.split(input, argc - 1);
    c1.sortPairs();
    c1.dividePairs();

    c1.showPairs();
    c1.showMainChain();
    c1.showPendingChain();

	// atexit(check_leaks);

	return 0;
}

