#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : size(0)
{
    // std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(unsigned int size) : size(size)
{
    // std::cout << "Parameter PmergeMe constructor called" << std::endl;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "Default PmergeMe destructor called" << std::endl;
    // for (unsigned int i = 0; i < this->size / 2; i++) {
    //     delete this->pairsVec[i];
    // }
    // if (this->size % 2 == 1)
    //     delete this->pairsVec[size / 2];
}

PmergeMe::PmergeMe(PmergeMe &PmergeMe)
{
    // std::cout << "PmergeMe Copy constructor called" << std::endl;
    *this = PmergeMe;
}

PmergeMe &PmergeMe::operator=(PmergeMe &PmergeMe)
{
    // std::cout << "PmergeMe Copy assignment operator called" << std::endl;
    std::list<int>::iterator iter;

    if (this != &PmergeMe)
    {
        this->size = PmergeMe.size;
        // for (iter = PmergeMe.list.begin(); iter != PmergeMe.list.end(); ++iter)
        //     this->list.push_back(*iter);
    }
    return *this;
}

void PmergeMe::init(std::vector<int>& vec, std::vector<std::vector<int> >& newVec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        newVec.push_back(std::vector<int>());
        newVec.back().push_back(vec[i]);
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

void PmergeMe::makeMainChain(std::vector<std::vector<int> >& vec, std::vector<std::vector<int> >& newVec) {
    for (unsigned int i = 0; i < vec.size(); i += 2) {
        newVec.push_back(std::vector<int>(vec[i]));
        newVec.back().push_back(i);
    }
    // if (vec.size() % 2 == 1) {
    //     newVec.push_back(std::vector<int>(vec.back()));
    //     newVec.back().erase(newVec.back().begin());
    //     newVec.back().insert(newVec.back().begin(), vec.size() - 1);
    //     newVec.back().insert(newVec.back().begin(), INT_MAX);
    // }
}

bool PmergeMe::isSorted(std::vector<std::vector<int> >& vec) {
    for (unsigned int i = 1; i < vec.size(); i++) {
        if (vec[i-1].front() > vec[i].front())
            return false;
    }
    return true;
}

void PmergeMe::copyIdx(std::vector<std::vector<int> >& vec, std::vector<int>& newVec, int depth) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        newVec.push_back(vec[i][depth]);
    }
}

void PmergeMe::makeEven(std::vector<std::vector<int> >& vec) {
    vec.insert(vec.begin() + vec.size() - 1, std::vector<int>(vec.front()));
    vec[vec.size() - 1][0] = INT_MAX;
    vec[vec.size() - 1].push_back(vec.size()-1);
}

void PmergeMe::attachLastElement(std::vector<std::vector<int> >& vec, std::vector<std::vector<int> >& newVec) {
    newVec.push_back(vec[vec.size() - 2]);
}

void PmergeMe::mergeInsertionSortVec(std::vector<std::vector<int> >& vec, int depth) {
    this->split(vec);
    std::vector<std::vector<int> > newVec;
    this->makeMainChain(vec, newVec);
    std::vector<int> tempIdx;
    this->copyIdx(newVec, tempIdx, depth+1);
    if (!isSorted(newVec)) {
        mergeInsertionSortVec(newVec, depth + 1);
    }
    if (vec.size() % 2 == 1) {
        makeEven(vec);
        attachLastElement(vec, newVec);
        tempIdx.push_back(newVec.back()[depth+1]);
    }
    newVec.insert(newVec.begin(), vec[tempIdx[0] + 1]);
    int t = 1;
    int n = 2;
    while (std::pow(2, n) <= vec.size()) {
        t = 2 * t + std::pow(-1, n);
        for (int i = std::min(t, (int)tempIdx.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
            int findNum = vec[tempIdx[i-1] + 1].front();
            int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)newVec.size()), newVec);
            newVec.insert(newVec.begin() + targetIdx, vec[tempIdx[i-1] + 1]);
        }
        n++;
    }
    if (newVec[newVec.size()-1].front() == INT_MAX) {
        newVec.erase(newVec.end() - 1);
    }
    vec.clear();
    vec.assign(newVec.begin(), newVec.end());
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

void PmergeMe::showMainChain(std::vector<std::vector<int> >& vec) {
    std::cout << "main chain : ";
    for (std::vector<std::vector<int> >::iterator it = vec.begin(); it != vec.end() ;it++) {
        std::cout << (*it).front() << " ";
    }
    std::cout << std::endl;
}

// std::vector<std::pair<int, int> >& PmergeMe::split(std::vector<int> input) {
//     this->size = input.size();
//     std::vector<std::pair<int, int> > newVec;
//     for (int i = 0; i < size / 2; i++) {
//         newVec.push_back(std::pair<int, int> (input[i * 2], input[i * 2 + 1]));
//         sortPair(newVec.back());
//     }
//     if (this->size % 2 == 1) {
//         // 입력 요소의 개수가 홀수인 경우
//         newVec.push_back(std::pair<int, int> (0, input[this->size - 1]));
//     }
//     return newVec;
// }

// void PmergeMe::sortPair(std::vector<std::pair<int, int> >& vec, int mainIdx, int pendingIdx) {
//     if (vec[mainIdx].first < vec[pendingIdx].first) {
//         std::pair<int, int> temp;
//         temp = vec[mainIdx];
//         vec[mainIdx] = vec[pendingIdx];
//         vec[pendingIdx] = temp;
//     }
// }

// std::vector<std::vector<std::pair<int, int> > >& PmergeMe::split(std::vector<int> input, std::vector<std::vector<std::pair<int, int> > >& vec) {
//     this->size = input.size();
//     std::vector<std::vector<std::pair<int, int> > > newVec;
//     for (int i = 0; i < (int)input.size() / 2; i++) {
//         // vec.push_back(std::vector<std::pair<int, int> > ((input[i * 2], input[i * 2 + 1])));
//         vec.push_back(std::vector<std::pair<int, int> >());
//         vec.back().push_back(std::pair<int, int>(input[i * 2], input[i * 2 + 1]));
//     }
//     return vec;
// }

// std::vector<std::vector<std::pair<int, int> > >& PmergeMe::split(std::vector<std::vector<std::pair<int, int> > > input, std::vector<std::vector<std::pair<int, int> > >& newVec) {
//     this->size = input.size();
//     for (int i = 0; i < (int)input.size() / 2; i++) {
//         if (input[i * 2].front().first > input[i * 2 + 1].front().first) {
//             input[i * 2]
//         }
//         else {
//         }
//         // sortPair(newVec.back(), 0, newVec.back().size() / 2);
//     }
//     // if (input.size() % 2 == 1) {
//     //     // 입력 요소의 개수가 홀수인 경우
//     //     newVec.push_back(std::vector<std::pair<int, int> > ((NULL, input[input.size() - 1])));
//     // }
//     return newVec;
// }

// void PmergeMe::execute(std::vector<int> input) {
//     std::vector<std::vector<std::pair<int, int> > > vec;
//     vec = this->split(input, vec);
//     // showMainChain(vec);
//     if (vec.size() % 2 == 1) {
//         vec = this->mergeInsertionSortVec(vec, vec.back());
//     }
//     else {
//         std::vector<std::pair<int, int> > emptyVec;
//         vec = mergeInsertionSortVec(vec, emptyVec);
//     }

//     // this->showMainChain(vec);

//     // std::vector<int> mainChain;
//     // std::vector<int> pendingChain;

//     // this->split(input, input.size());
//     // this->dividePairs(this->mainVector, this->pendingVector);
//     // this->mergeInsertionSortVec(this->mainVector, this->pendingVector, this->mainVector.size());

//     // this->mainVector.clear();
//     // this->mainVector.assign(mainChain.begin(), mainChain.end());
//     // this->mergeInsertionSortVec(this->mainVector, this->pendingVector, size);
// }

// std::vector<std::vector<std::pair<int, int> > >& PmergeMe::mergeInsertionSortVec(std::vector<std::vector<std::pair<int, int> > >& vec, std::vector<std::pair<int, int> >& odd) {
//     if (!isSorted(vec)) {
//         // showMainChain(vec);
//         std::vector<std::vector<std::pair<int, int> > > splitVec;
//         this->split(vec, splitVec);
//         showMainChain(splitVec);
//         vec.clear();
//         if (vec.size() % 2 == 1)
//             vec = mergeInsertionSortVec(splitVec, vec.back());
//         else {
//             std::vector<std::pair<int, int> > emptyVec;
//             vec = mergeInsertionSortVec(splitVec, emptyVec);
//         }
//     }
//     // std::cout << vec.size() << std::endl;
//     // std::cout << vec.back().back().first << std::endl;
//     // std::cout << vec.back().back().second << std::endl;
//     int t = 1;
//     int n = 2;
//     this->moveElements(vec, 0, vec[0].begin() + vec[0].size() / 2, vec[0].end());
//     vec[0].erase(vec[0].begin() + vec[0].size() / 2, vec[0].end() - 1);
//     unsigned int size = vec.size() % 2 == 0 ? vec.size() * 2 : vec.size() * 2 + 1;
//     while (size > vec.size()) {
//         t = 2 * t + std::pow(-1, n);
//         for (int i = std::min(t, odd.empty() ? (int)vec.size() : (int)vec.size() + 1); i > (t - (int)std::pow(-1, n)) / 2; i--) {
//             int findNum;
//             if (i == (int)vec.size())
//                 findNum = odd[vec.size() / 2].first;
//             else
//                 findNum = vec[i-1][vec.size() / 2].first;
//             int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)vec.size()), vec);
//             this->moveElements(vec, targetIdx, vec[i-1].begin() + vec[i-1].size() / 2, vec[i-1].end());
//         }
//         n++;
//     }
//     return vec;
// }

// void PmergeMe::moveElements(std::vector<std::vector<std::pair<int, int> > >& dst, int idx, std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end) {
//     dst.insert(dst.begin() + idx, std::vector<std::pair<int, int> >());
//     std::vector<std::pair<int, int> >::iterator it;
//     for (it = begin; it != end; it++) {
//         dst[idx].push_back(*it);
//     }
// }

// bool PmergeMe::isSorted(std::vector<std::vector<std::pair<int, int> > > vec) {
//     for (unsigned int i = 1; i < vec.size(); i++) {
//         if (vec[i-1][0].first > vec[i][0].first)
//             return false;
//     }
//     return true;
// }

// void PmergeMe::mergeInsertionSortVec(std::vector<int>& mainChain, std::vector<int>& pendingChain, unsigned int size) {
//     if (!isSorted(mainChain)) {
//         std::vector<int> tempMain; 
//         std::vector<int> tempPending;
//         this->split(mainChain, mainChain.size());
//         this->dividePairs(tempMain, tempPending);
//         mergeInsertionSortVec(tempMain, tempPending, mainChain.size());
//         mainChain.clear();
//         mainChain.assign(tempMain.begin(), tempMain.end());
//     }
//     int t = 1;
//     int n = 2;
//     if (size >= 2) {
//         mainChain.insert(mainChain.begin(), pendingChain[0]);
//     }
//     while (size > mainChain.size()) {
//         t = 2 * t + std::pow(-1, n);
//         for (int i = std::min(t, (int)pendingChain.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
//             int findNum = pendingChain[i-1];
//             int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)mainChain.size()), mainChain);
//             mainChain.insert(mainChain.begin() + targetIdx, findNum);
//         }
//         n++;
//     }
// }

// void PmergeMe::dividePairs(std::vector<int>& mainVec, std::vector<int>& pendingVec) {
//     /*
//         check if there is memory in pointer
//     */
//     for (unsigned int i = 0; i < this->size / 2; i++) {
//         mainVec.insert(mainVec.begin() + i, this->pairsVec[i]->first);
//         pendingVec.insert(pendingVec.begin() + i, this->pairsVec[i]->second);
//     }
//     if (this->size % 2 == 1) {
//         pendingVec.insert(pendingVec.begin() + this->size / 2, this->pairsVec[this->size / 2]->second);
//     }
//     this->pairsVec.clear();
//     // for (unsigned int i = 0; i < this->size / 2; i++) {
//     //     delete this->pairsVec[i];
//     // }
//     // if (this->size % 2 == 1)
//     //     delete this->pairsVec[size / 2];
// }

// int PmergeMe::binarySearch(int num, int endIdx, std::vector<int> vec) {
//     int l = 0;
//     int r = endIdx - 1;
//     int mid;
//     while (l <= r) {
//         mid = (l + r) / 2;
//         if (num > vec[mid]) {
//             l = mid + 1;
//         }
//         else {
//             r = mid - 1;
//         }
//     }
//     return l;
// }

// void PmergeMe::mergeInsertionSortVec(std::vector<int>& mainChain, std::vector<int>& pendingChain, unsigned int size) {
//     int t = 1;
//     int n = 2;
//     if (size >= 2) {
//         mainChain.insert(mainChain.begin(), pendingChain[0]);
//     }
//     while (size > mainChain.size()) {
//         t = 2 * t + std::pow(-1, n);
//         for (int i = std::min(t, (int)pendingChain.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
//             int findNum = pendingChain[i-1];
//             int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)mainChain.size()), mainChain);
//             mainChain.insert(mainChain.begin() + targetIdx, findNum);
//         }
//         n++;
//     }
// }

unsigned int PmergeMe::getSize() {
    return this->size;
}

std::vector<int>& PmergeMe::getMainVec() {
    return this->mainVector;
}

std::vector<int>& PmergeMe::getPendingVec() {
    return this->pendingVector;
}

// void PmergeMe::sortPairs() {
//     // using insertion sort
//     for (unsigned int i = 1; i < this->size / 2; i++) {
//         std::pair<int, int>* pair = this->pairsVec[i];
//         for (int j = i - 1; j >= 0; j--) {
//             if (this->pairsVec[j]->first > pair->first) {
//                 std::pair<int, int>* temp = this->pairsVec[j];
//                 this->pairsVec[j] = pair;
//                 this->pairsVec[j+1] = temp;
//             }
//             else {
//                 break;
//             }
//         }
//     }
// }

// void PmergeMe::dividePairs() {
//     /*
//         check if there is memory in pointer
//     */
//     for (unsigned int i = 0; i < this->size / 2; i++) {
//         this->mainVector.insert(this->mainVector.begin() + i, this->pairsVec[i]->first);
//         this->pendingVector.insert(this->pendingVector.begin() + i, this->pairsVec[i]->second);
//     }
//     if (this->size % 2 == 1) {
//         this->pendingVector.insert(this->pendingVector.begin() + this->size / 2, this->pairsVec[this->size / 2]->second);
//     }
// }

// void PmergeMe::mergeInsertionSort() {
//     int t = 1;
//     int n = 2;
//     if (this->size >= 2) {
//         this->mainVector.insert(this->mainVector.begin(), this->pendingVector[0]);
//         // this->pendingChain.erase(this->pendingChain.begin());
//     }
//     while (this->size > this->mainVector.size()) {
//         t = 2 * t + std::pow(-1, n);
//         for (int i = std::min(t, (int)this->pendingVector.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
//             int findNum = this->pendingVector[i-1];
//             // this->pendingChain.erase(this->pendingChain.begin() + i - 1);
//             int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)this->mainVector.size()), this->mainVector);
//             this->mainVector.insert(this->mainVector.begin() + targetIdx, findNum);
//         }
//         n++;
//     }
// }

// temp 함수

void PmergeMe::showMainChain(std::vector<std::vector<std::pair<int, int> > > vec) {
    std::cout << "main chain : ";
    for (std::vector<std::vector<std::pair<int, int> > >::iterator it = vec.begin(); it != vec.end() ;it++) {
        std::cout << (*it)[0].first << ":" << (*it)[0].second << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showPendingChain() {
    std::cout << "pending chain : ";
    for (unsigned int i = 0; i < this->size / 2; i++) {
        std::cout << this->pendingVector[i] << " ";
    }
    if (this->size % 2 == 1) {
        std::cout << this->pendingVector[this->size / 2] << " ";
    }
    std::cout << std::endl;
}