#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__
# include <iostream>
# include <string>
# include <list>
# include <vector>

class PmergeMe {
    private:
        unsigned int size;
        std::vector<int> vec;
        std::pair<int, int>** pairs;
        int* mainChain;
        int* pendingChain;

    public:
        PmergeMe();
        PmergeMe(unsigned int size);
        ~PmergeMe();
        PmergeMe(PmergeMe &PmergeMe);
        PmergeMe &operator=(PmergeMe& PmergeMe);

        void addElement(int number);
        void split(int* inputArr, int size);
        void sortPair(std::pair<int, int>* p);
        void sortPairs();
        void dividePairs();
        void mergeInsertionSort();
        int binarySearch(int num, int end, int* arr);

        // temp 함수 (나중에 삭제)
        void show();
        void showPairs();
        void showMainChain();
        void showPendingChain();

        unsigned int getSize();
};

#endif