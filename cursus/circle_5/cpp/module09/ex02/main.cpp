#include "PmergeMe.hpp"

void check_leaks()
{
	system("leaks PmergeMe");
}

int	main(int argc, char *argv[])
{	
    std::vector<int> inputVec;
    std::deque<int> inputDeq;

    // 입력
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        int number = std::atoi(argv[i]);
        if (number < 1) {
            std::cout << "Error" << std::endl;
            exit(1);
        }
        inputVec.push_back(number);
        inputDeq.push_back(number);
    }

	PmergeMe c1;

    // // clock 함수 사용
    // clock_t start, finish;
    // double duration;
 
    // start = clock();
    
    // std::vector<std::vector<int> > vec;
    // c1.showInputVec(inputVec);
    // c1.init(inputVec, vec);
    // c1.mergeInsertionSortVec(vec, 0);
 
    // finish = clock();
 
    // duration = (double)(finish - start) / CLOCKS_PER_SEC;
    // c1.showVec(vec);
    // std::cout << duration << "초" << std::endl;

    // std::cout << "\n=======================\n" << std::endl;
 
    // start = clock();
    
    // std::deque<std::deque<int> > deque;
    // c1.showInputDeque(inputDeq);
    // c1.init(inputDeq, deque);
    // c1.mergeInsertionSortVec(deque, 0);
 
    // finish = clock();
 
    // duration = (double)(finish - start) / CLOCKS_PER_SEC;
    // c1.showDeque(deque);
    // std::cout << duration << "초" << std::endl;

    // std::cout << "\n=======================\n" << std::endl;

{
    //MK: 시작/끝 시간을 측정하기 위해서 추가함 (time.h 필요)
    struct timespec  begin, end;

    c1.showInputDeque(inputDeq);

    //MK: 연산 시작과 함께 시간을 측정함
    clock_gettime(CLOCK_MONOTONIC, &begin);
    std::vector<std::vector<int> > vec;
    c1.init(inputVec, vec);
    c1.mergeInsertionSortVec(vec, 0);

    //MK: 연산이 끝나면 시간을 측정함
    clock_gettime(CLOCK_MONOTONIC, &end);

    c1.showVec(vec);

    //MK: 측정한 시간을 Nano, Micro, Milli, Second 단위로 출력함
    long long time = 1000000000 * (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
    std::cout << "Time (Micro): " << (double)time/1000 << std::endl;
    std::cout << "Time (Milli): " << (double)time/1000000 << std::endl;
    std::cout << "Time (Second): " << (double)time/1000000000 << std::endl;

    // std::cout << c1.isSorted(vec) << std::endl;

    std::cout << "\n=======================\n" << std::endl;

}

{
    //MK: 시작/끝 시간을 측정하기 위해서 추가함 (time.h 필요)
    struct timespec  begin, end;

    c1.showInputDeque(inputDeq);

    //MK: 연산 시작과 함께 시간을 측정함
    clock_gettime(CLOCK_MONOTONIC, &begin);
    std::deque<std::deque<int> > deque;
    c1.init(inputDeq, deque);
    c1.mergeInsertionSortVec(deque, 0);

    //MK: 연산이 끝나면 시간을 측정함
    clock_gettime(CLOCK_MONOTONIC, &end);

    c1.showDeque(deque);

    //MK: 측정한 시간을 Nano, Micro, Milli, Second 단위로 출력함
    long long time = 1000000000 * (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
    std::cout << "Time (Micro): " << (double)time/1000 << std::endl;
    std::cout << "Time (Milli): " << (double)time/1000000 << std::endl;
    std::cout << "Time (Second): " << (double)time/1000000000 << std::endl;

    // std::cout << c1.isSorted(deque) << std::endl;

    std::cout << "\n=======================\n" << std::endl;
}
	// atexit(check_leaks);

	return 0;
}

