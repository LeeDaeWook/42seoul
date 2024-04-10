#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__
# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <cmath>
# include <algorithm>

class PmergeMe {
    private:
        unsigned int size;
        std::pair<int, int>** pairs;
        std::vector<int> mainChain;
        std::vector<int> pendingChain;
        // int* pendingChain;

    public:
        PmergeMe();
        PmergeMe(unsigned int size);
        ~PmergeMe();
        PmergeMe(PmergeMe &PmergeMe);
        PmergeMe &operator=(PmergeMe& PmergeMe);

        void split(int* inputArr, int size);
        void sortPair(std::pair<int, int>* p);
        void sortPairs();
        void dividePairs();
        void mergeInsertionSort();
        int binarySearch(int num, int end, std::vector<int> vec);

        // temp 함수 (나중에 삭제)
        void show();
        void showPairs();
        void showMainChain();
        void showPendingChain();

        unsigned int getSize();
};

#endif