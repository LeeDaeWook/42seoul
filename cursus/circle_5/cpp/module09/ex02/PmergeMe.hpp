#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__
# include <iostream>
# include <string>
# include <list>

class PmergeMe {
    private:
        unsigned int size;
        std::list<int> list;
        // std::list<std::pair<int, int>> pairs;
        std::pair<int, int>** pairs;

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

        // temp 함수 (나중에 삭제)
        void show();
        void showPairs();

        unsigned int getSize();
};

#endif