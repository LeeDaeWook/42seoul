#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__
# include <iostream>
# include <string>
# include <vector>
# include <cmath>
# include <deque>

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &PmergeMe);
        PmergeMe &operator=(PmergeMe& PmergeMe);

        void init(std::vector<int>& vec, std::vector<std::vector<int> >& newVec);
        void split(std::vector<std::vector<int> >& input);
        void makeMainChain(std::vector<std::vector<int> >& vec, std::vector<std::vector<int> >& newVec);
        int binarySearch(int num, int end, std::vector<std::vector<int> >& vec);
        void copyIdx(std::vector<std::vector<int> >& vec, std::vector<int>& newVec, int depth);
        void makeEven(std::vector<std::vector<int> >& vec);
        void attachLastElement(std::vector<std::vector<int> >& vec, std::vector<std::vector<int> >& newVec);
        int find(std::vector<std::vector<int> >& vec, std::vector<int>& tempIdx, unsigned int idx);
        void insert(std::vector<std::vector<int> >& vec, std::vector<std::vector<int> >& newVec, std::vector<int>& tempIdx, unsigned int idx, unsigned int targetIdx);
        void mergeInsertionSortVec(std::vector<std::vector<int> >& vec, int depth);
        bool isSorted(std::vector<std::vector<int> >& vec);
        void showInputVec(std::vector<int>& vec);
        void showVec(std::vector<std::vector<int> >& vec);

        void init(std::deque<int>& deque, std::deque<std::deque<int> >& newDeque);
        void split(std::deque<std::deque<int> >& input);
        void makeMainChain(std::deque<std::deque<int> >& deque, std::deque<std::deque<int> >& newDeque);
        bool isSorted(std::deque<std::deque<int> >& deque);
        void copyIdx(std::deque<std::deque<int> >& deque, std::deque<int>& newDeque, int depth);
        void makeEven(std::deque<std::deque<int> >& deque);
        void attachLastElement(std::deque<std::deque<int> >& deque, std::deque<std::deque<int> >& newDeque);
        int find(std::deque<std::deque<int> >& deque, std::deque<int>& tempIdx, unsigned int idx);
        void insert(std::deque<std::deque<int> >& deque, std::deque<std::deque<int> >& newDeque, std::deque<int>& tempIdx, unsigned int idx, unsigned int targetIdx);
        void mergeInsertionSortVec(std::deque<std::deque<int> >& deque, int depth);
        int binarySearch(int num, int endIdx, std::deque<std::deque<int> >& deque);
        void showInputDeque(std::deque<int>& deque);
        void showDeque(std::deque<std::deque<int> >& deque);

};

#endif