#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "Default PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe &PmergeMe)
{
    // std::cout << "PmergeMe Copy constructor called" << std::endl;
    *this = PmergeMe;
}

PmergeMe &PmergeMe::operator=(PmergeMe &PmergeMe)
{
    // std::cout << "PmergeMe Copy assignment operator called" << std::endl;

    (void)PmergeMe;
    return *this;
}

void PmergeMe::init(std::vector<int>& vec, std::vector<std::vector<int> >& newVec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        newVec.push_back(std::vector<int>());
        newVec.back().push_back(vec[i]);
    }
}

void PmergeMe::init(std::deque<int>& deque, std::deque<std::deque<int> >& newDeque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        newDeque.push_back(std::deque<int>());
        newDeque.back().push_back(deque[i]);
    }
}

void PmergeMe::split(std::vector<std::vector<int> >& input) {
    for (unsigned int i = 0; i < input.size() / 2; i++) {
        if (input[i * 2].front() < input[i * 2 + 1].front()) {
            std::vector<int> temp = input[i * 2];
            input[i * 2] = input[i * 2 + 1];
            input[i * 2 + 1] = temp;
        }
    }
}

void PmergeMe::split(std::deque<std::deque<int> >& input) {
    for (unsigned int i = 0; i < input.size() / 2; i++) {
        if (input[i * 2].front() < input[i * 2 + 1].front()) {
            std::deque<int> temp = input[i * 2];
            input[i * 2] = input[i * 2 + 1];
            input[i * 2 + 1] = temp;
        }
    }
}

void PmergeMe::makeMainChain(std::vector<std::vector<int> >& vec, std::vector<std::vector<int> >& newVec) {
    for (unsigned int i = 0; i < vec.size() - 1; i += 2) {
        newVec.push_back(std::vector<int>(vec[i]));
        newVec.back().push_back(i);
    }
}

void PmergeMe::makeMainChain(std::deque<std::deque<int> >& deque, std::deque<std::deque<int> >& newDeque) {
    for (unsigned int i = 0; i < deque.size() - 1; i += 2) {
        newDeque.push_back(std::deque<int>(deque[i]));
        newDeque.back().push_back(i);
    }
}

void PmergeMe::copyIdx(std::vector<std::vector<int> >& vec, std::vector<int>& newVec, int depth) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        newVec.push_back(vec[i][depth]);
    }
}

void PmergeMe::copyIdx(std::deque<std::deque<int> >& deque, std::deque<int>& newDeque, int depth) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        newDeque.push_back(deque[i][depth]);
    }
}

int PmergeMe::find(std::vector<std::vector<int> >& vec, std::vector<int>& tempIdx, unsigned int idx) {
    if (idx == tempIdx.size() && vec.size() % 2 == 1)
        return vec[tempIdx[idx-1]].front();
    else
        return vec[tempIdx[idx-1] + 1].front();
}

int PmergeMe::find(std::deque<std::deque<int> >& deque, std::deque<int>& tempIdx, unsigned int idx) {
    if (idx == tempIdx.size() && deque.size() % 2 == 1)
        return deque[tempIdx[idx-1]].front();
    else
        return deque[tempIdx[idx-1] + 1].front();
}

void PmergeMe::insert(std::vector<std::vector<int> >& vec, std::vector<std::vector<int> >& newVec, std::vector<int>& tempIdx, unsigned int idx, unsigned int targetIdx) {
    if (idx == tempIdx.size() && vec.size() % 2 == 1)
        newVec.insert(newVec.begin() + targetIdx, vec[tempIdx[idx-1]]);
    else
        newVec.insert(newVec.begin() + targetIdx, vec[tempIdx[idx-1] + 1]);
}

void PmergeMe::insert(std::deque<std::deque<int> >& deque, std::deque<std::deque<int> >& newDeque, std::deque<int>& tempIdx, unsigned int idx, unsigned int targetIdx) {
    if (idx == tempIdx.size() && deque.size() % 2 == 1)
        newDeque.insert(newDeque.begin() + targetIdx, deque[tempIdx[idx-1]]);
    else
        newDeque.insert(newDeque.begin() + targetIdx, deque[tempIdx[idx-1] + 1]);
}

void PmergeMe::mergeInsertionSortVec(std::vector<std::vector<int> >& vec, int depth) {
    if (vec.size() == 1)
        return ;
    split(vec);
    std::vector<std::vector<int> > newVec;
    makeMainChain(vec, newVec);
    std::vector<int> tempIdx;
    mergeInsertionSortVec(newVec, depth + 1);
    copyIdx(newVec, tempIdx, depth+1);
    if (vec.size() % 2 == 1)
        tempIdx.push_back(vec.size() - 1);
    newVec.insert(newVec.begin(), vec[tempIdx[0] + 1]);
    int t = 1;
    int n = 2;
    while (true) {
        t = 2 * t + std::pow(-1, n);
        int i;
        for (i = std::min(t, (int)tempIdx.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
            int findNum = find(vec, tempIdx, i);
            int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)newVec.size()), newVec);
            insert(vec, newVec, tempIdx, i, targetIdx);
        }
        if (i == (int)tempIdx.size())
            break;
        n++;
    }
    vec.clear();
    vec.assign(newVec.begin(), newVec.end());
}

void PmergeMe::mergeInsertionSortVec(std::deque<std::deque<int> >& deque, int depth) {
    if (deque.size() == 1)
        return ;
    split(deque);
    std::deque<std::deque<int> > newDeque;
    makeMainChain(deque, newDeque);
    std::deque<int> tempIdx;
    mergeInsertionSortVec(newDeque, depth + 1);
    copyIdx(newDeque, tempIdx, depth+1);
    if (deque.size() % 2 == 1)
        tempIdx.push_back(deque.size() - 1);
    newDeque.insert(newDeque.begin(), deque[tempIdx[0] + 1]);
    int t = 1;
    int n = 2;
    while (true) {
        t = 2 * t + std::pow(-1, n);
        int i;
        for (i = std::min(t, (int)tempIdx.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
            int findNum = find(deque, tempIdx, i);
            int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)newDeque.size()), newDeque);
            insert(deque, newDeque, tempIdx, i, targetIdx);
        }
        if (i == (int)tempIdx.size())
            break;
        n++;
    }
    deque.clear();
    deque.assign(newDeque.begin(), newDeque.end());
}

int PmergeMe::binarySearch(int num, int endIdx, std::vector<std::vector<int> >& vec) {
    int l = 0;
    int r = endIdx - 1;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (num > vec[mid].front()) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

int PmergeMe::binarySearch(int num, int endIdx, std::deque<std::deque<int> >& deque) {
    int l = 0;
    int r = endIdx - 1;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (num > deque[mid].front()) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

void PmergeMe::showInputVec(std::vector<int >& vec) {
    std::cout << "Before : ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end() ;it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showVec(std::vector<std::vector<int> >& vec) {
    std::cout << "After : ";
    for (std::vector<std::vector<int> >::iterator it = vec.begin(); it != vec.end() ;it++) {
        std::cout << (*it).front() << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showInputDeque(std::deque<int>& deque) {
    std::cout << "Before : ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end() ;it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showDeque(std::deque<std::deque<int> >& deque) {
    std::cout << "After : ";
    for (std::deque<std::deque<int> >::iterator it = deque.begin(); it != deque.end() ;it++) {
        std::cout << (*it).front() << " ";
    }
    std::cout << std::endl;
}

bool PmergeMe::isSorted(std::vector<std::vector<int> >& vec) {
    for (unsigned int i = 1; i < vec.size(); i++) {
        if (vec[i-1].front() > vec[i].front())
            return false;
    }
    return true;
}

bool PmergeMe::isSorted(std::deque<std::deque<int> >& deque) {
    for (unsigned int i = 1; i < deque.size(); i++) {
        if (deque[i-1].front() > deque[i].front())
            return false;
    }
    return true;
}
