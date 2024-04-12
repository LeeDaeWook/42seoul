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

// void PmergeMe::sortPair(std::pair<int, int>& p) {
void PmergeMe::sortPair(std::pair<std::pair<int, int>*, std::pair<int, int>*>& p) {
    if (p.first->first < p.second->first) {
        std::pair<int, int>* temp;
        temp = p.first;
        p.first = p.second;
        p.second = temp;
    }
}

std::vector<std::pair<int, int>>& PmergeMe::split(std::vector<std::pair<int, int>> input) {
    this->size = input.size();
    std::vector<std::pair<std::pair<int, int>*, std::pair<int, int>*>> newVec;
    for (int i = 0; i < size / 2; i++) {
        // newVec.push_back(std::pair<int, int> (input[i].first, input[i+1].first));
        newVec.push_back(std::pair<std::pair<int, int>*, std::pair<int, int>*> (&(input[i]), &(input[i+1])));
        sortPair(newVec.back());
    }
    if (this->size % 2 == 1) {
        // 입력 요소의 개수가 홀수인 경우
        // newVec.push_back(std::pair<int, int> (0, input.back().first));
        newVec.push_back(std::pair<std::pair<int, int>*, std::pair<int, int>*> (NULL, &(input.back())));
    }
    return newVec;
}

std::vector<std::pair<int, int>>& PmergeMe::split(std::vector<int> input) {
    this->size = input.size();
    std::vector<std::pair<int, int>> newVec;
    for (int i = 0; i < size / 2; i++) {
        newVec.push_back(std::pair<int, int> (input[i * 2], input[i * 2 + 1]));
        sortPair(&(newVec.back()));
    }
    if (this->size % 2 == 1) {
        // 입력 요소의 개수가 홀수인 경우
        newVec.push_back(std::pair<int, int> (0, input[this->size - 1]));
    }
    return newVec;
}

// void PmergeMe::split(std::vector<int> input, int size) {
//     this->size = size;
//     for (int i = 0; i < size / 2; i++) {
//         // this->pairsVec.push_back(std::pair<int, int> (input[i * 2], input[i * 2 + 1]));
//         this->pairsVec.push_back(new std::pair<int, int> (input[i * 2], input[i * 2 + 1]));
//         sortPair(this->pairsVec.back());
//     }
//     if (this->size % 2 == 1) {
//         // 입력 요소의 개수가 홀수인 경우
//         // this->pairsVec.push_back(std::pair<int, int> (0, input[this->size - 1]));
//         this->pairsVec.push_back(new std::pair<int, int> (0, input[this->size - 1]));
//     }
// }

void PmergeMe::execute(std::vector<int> input, int size) {
    std::vector<std::pair<int, int>>& vec = this->split(input);
    this->mergeInsertionSortVec(vec);

    // std::vector<int> mainChain;
    // std::vector<int> pendingChain;

    // this->dividePairs(mainChain, this->pendingVector);
    // this->dividePairs(this->mainVector, this->pendingVector);

    // this->split(mainChain, mainChain.size());
    // this->dividePairs(this->mainVector, pendingChain);
    // this->mergeInsertionSortVec(this->mainVector, pendingChain, mainChain.size());

    // this->mainVector.clear();
    // this->mainVector.assign(mainChain.begin(), mainChain.end());
    // this->mergeInsertionSortVec(this->mainVector, this->pendingVector, size);
}

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

        
void PmergeMe::mergeInsertionSortVec(std::vector< std::pair<int, int> >& vec) {
    if (!isSorted(vec)) {
        std::vector<std::pair<int, int>> newVec = this->split(vec);
        mergeInsertionSortVec(newVec);
        vec.clear();
        vec.assign(newVec.begin(), newVec.end());
    }
    int t = 1;
    int n = 2;
    if (size >= 2) {
        vec.insert(vec.begin(), std::pair<int, int> (vec[0].second, 0));
    }
    while (size > vec.size()) {
        t = 2 * t + std::pow(-1, n);
        for (int i = std::min(t, (int)pendingChain.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
            int findNum = pendingChain[i-1];
            int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)mainChain.size()), mainChain);
            mainChain.insert(mainChain.begin() + targetIdx, findNum);
        }
        n++;
    }
}

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
//         // std::cout << pendingChain[0] << std::endl;
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

int PmergeMe::binarySearch(int num, int endIdx, std::vector<int> vec) {
    int l = 0;
    int r = endIdx - 1;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (num > vec[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

bool PmergeMe::isSorted(std::vector<std::pair<int, int>>& vec) {
    for (unsigned int i = 1; i < vec.size(); i++) {
        if (vec[i-1].first > vec[i].first)
            return false;
    }
    return true;
}

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

void PmergeMe::sortPairs() {
    // using insertion sort
    for (unsigned int i = 1; i < this->size / 2; i++) {
        std::pair<int, int>* pair = this->pairsVec[i];
        for (int j = i - 1; j >= 0; j--) {
            if (this->pairsVec[j]->first > pair->first) {
                std::pair<int, int>* temp = this->pairsVec[j];
                this->pairsVec[j] = pair;
                this->pairsVec[j+1] = temp;
            }
            else {
                break;
            }
        }
    }
}

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
// void PmergeMe::showPairs() {
//     std::cout << "pairs : ";
//     for (unsigned int i = 0; i < this->size / 2; i++) {
//         std::cout << this->pairsVec[i]->first << " ";
//     }
//     std::cout << std::endl;
// }

void PmergeMe::showMainChain() {
    std::cout << "main chain : ";
    for (std::vector<int>::iterator it = this->mainVector.begin(); it != this->mainVector.end() ;it++) {
        std::cout << *it << " ";
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