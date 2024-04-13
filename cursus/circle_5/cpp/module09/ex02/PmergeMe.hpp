#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__
# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <cmath>
# include <algorithm>
# include <ctime>
# include <deque>

class PmergeMe {
    private:
        unsigned int size;
        std::vector< std::pair<int, int>* > pairsVec;
        // std::vector< std::pair<int, int> > pairsVec;
        std::vector< std::pair<int, int> > vec;
        std::vector<int> mainVector;
        std::vector<int> pendingVector;
        std::deque<int> mainDeque;
        std::deque<int> pendingDeque;

    public:
        PmergeMe();
        PmergeMe(unsigned int size);
        ~PmergeMe();
        PmergeMe(PmergeMe &PmergeMe);
        PmergeMe &operator=(PmergeMe& PmergeMe);

        // void split(std::vector<int> input, int size);
        // std::vector<std::pair<int, int>>& split(std::vector<int> input);
        std::vector<std::vector<std::pair<int, int> > >& split(std::vector<int> input, std::vector<std::vector<std::pair<int, int> > >& vec);
        std::vector<std::vector<std::pair<int, int> > >& split(std::vector<std::vector< std::pair<int, int> > > input, std::vector<std::vector<std::pair<int, int> > >& newVec);
        // void sortPair(std::pair<int, int>& p);
        void sortPair(std::vector<std::pair<int, int> >& vec, int firstIdx, int secondIdx);
        void sortPairs();
        void dividePairs(std::vector<int>& mainVec, std::vector<int>& pendingVec);
        std::vector<std::vector<std::pair<int, int> > >& mergeInsertionSortVec(std::vector<std::vector< std::pair<int, int> > >& vec, std::vector<std::pair<int, int> >& odd);
        // void mergeInsertionSortVec(std::vector<int>& mainChain, std::vector<int>& pendingChain, unsigned int size);
        // void mergeInsertionSortVec(std::vector< std::pair<int, int> >& vec);
        void moveElements(std::vector<std::vector< std::pair<int, int> > >& dst, int idx, std::vector< std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end);
        // bool isSorted(std::vector<int>& vec);
        bool isSorted(std::vector<std::vector< std::pair<int, int> > > vec);
        // int binarySearch(int num, int end, std::vector<int> vec);
        int binarySearch(int num, int endIdx, std::vector<std::vector< std::pair<int, int> > > vec);

        void execute(std::vector<int> input);


        // temp 함수 (나중에 삭제)
        void showPairs();
        void showMainChain(std::vector< std::vector< std::pair<int, int> > > vec);
        void showPendingChain();

        unsigned int getSize();
        std::vector<int>& getMainVec();
        std::vector<int>& getPendingVec();
};

#endif