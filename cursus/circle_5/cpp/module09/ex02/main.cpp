#include "PmergeMe.hpp"

void check_leaks()
{
	system("leaks PmergeMe");
}

int	main(int argc, char *argv[])
{	
    // int input[argc-1];
    std::vector<int> input;

    // 입력
    for (int i = 1; i < argc; i++) {
        int number = std::atoi(argv[i]);
        if (number < 0) {
            std::cout << "Error" << std::endl;
            exit(1);
        }
        input.push_back(number);
        // std::cout << number << " ";
    }
    // std::cout << std::endl;

	PmergeMe c1;

    // time 함수 사용
    // time_t start = time(NULL); 
 
    // c1.split(input, argc - 1);
    // c1.sortPairs();
    // c1.dividePairs();
    // c1.mergeInsertionSort();
 
    // time_t finish  = time(NULL); 
    
    // double duration = (double)(finish - start);
    // std::cout << duration * 1000000 << "ms" << std::endl;

    // clock 함수 사용
    clock_t start, finish;
    double duration;
 
    start = clock();
    
    // c1.split(input, argc - 1);
    // c1.sortPairs();
    // c1.dividePairs(c1.getMainVec(), c1.getPendingVec());
    // c1.mergeInsertionSortVec(c1.getMainVec(), c1.getPendingVec(), c1.getSize());
    c1.execute(input, argc - 1);
 
    finish = clock();
 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << duration << "초" << std::endl;

    std::cout << c1.isSorted(c1.getMainVec()) << std::endl;
    // c1.showPairs();
    // c1.showMainChain();
    // c1.showPendingChain();

	// atexit(check_leaks);

	return 0;
}

