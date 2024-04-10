#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : size(0)
{
    // std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(unsigned int size) : size(size)
{
    // std::cout << "Parameter PmergeMe constructor called" << std::endl;
    this->pairs = new std::pair<int, int>*[size];
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
    std::list<int>::iterator iter;

    if (this != &PmergeMe)
    {
        this->size = PmergeMe.size;
        // for (iter = PmergeMe.list.begin(); iter != PmergeMe.list.end(); ++iter)
        //     this->list.push_back(*iter);
    }
    return *this;
}

void PmergeMe::show() {
    std::list<int>::iterator it;

    // for (it = this->list.begin(); it != this->list.end(); it++) {
    //     std::cout << *it << std::endl;
    // }
}

void PmergeMe::split(int* inputArr, int size) {
    this->size = size;
    this->pairs = new std::pair<int, int>*[size / 2 + 1];
    for (int i = 0; i < size / 2; i++) {
        this->pairs[i] = new std::pair<int, int>;
        this->pairs[i]->first = inputArr[i * 2];
        this->pairs[i]->second = inputArr[i * 2 + 1];
        sortPair(this->pairs[i]);
    }
    if (this->size % 2 == 1) {
        // 입력 요소의 개수가 홀수인 경우
        this->pairs[this->size / 2] = new std::pair<int, int>;
        this->pairs[this->size / 2]->second = inputArr[this->size - 1];
    }
}

void PmergeMe::sortPair(std::pair<int, int>* p) {
    if (p->first < p->second) {
        int temp;
        temp = p->first;
        p->first = p->second;
        p->second = temp;
    }
}

void PmergeMe::sortPairs() {
    // using insertion sort
    for (unsigned int i = 1; i < this->size / 2; i++) {
        std::pair<int, int>* pair = this->pairs[i];
        for (int j = i - 1; j >= 0; j--) {
            if ((this->pairs[j])->first > pair->first) {
                std::pair<int, int>* temp = this->pairs[j];
                this->pairs[j] = pair;
                this->pairs[j+1] = temp;
            }
            else {
                break;
            }
        }
    }
}

void PmergeMe::dividePairs() {
    /*
        check if there is memory in pointer
    */
    // this->mainChain = new int[this->size / 2];
    // this->pendingChain = new int[this->size / 2];


    for (unsigned int i = 0; i < this->size / 2; i++) {
        this->mainChain.insert(this->mainChain.begin() + i, this->pairs[i]->first);
        // this->mainChain[i] = this->pairs[i]->first;
        this->pendingChain.insert(this->pendingChain.begin() + i, this->pairs[i]->second);
        // this->pendingChain[i] = this->pairs[i]->second;
    }
    if (this->size % 2 == 1) {
        // this->pendingChain[this->size / 2] = this->pairs[this->size / 2]->second;
        this->pendingChain.insert(this->pendingChain.begin() + this->size / 2, this->pairs[this->size / 2]->second);
    }
}

void PmergeMe::mergeInsertionSort() {
    int t = 1;
    int n = 2;
    if (this->size >= 2) {
        this->mainChain.insert(this->mainChain.begin(), this->pendingChain[0]);
        // this->pendingChain.erase(this->pendingChain.begin());
    }
    while (this->size > this->mainChain.size()) {
    // while (this->pendingChain.size()) {
    // while (!this->pendingChain.empty()) {
        t = 2 * t + std::pow(-1, n);
        std::cout << n << std::endl;
        for (int i = std::min(t, (int)this->pendingChain.size()); i > (t - (int)std::pow(-1, n)) / 2; i--) {
            int findNum = this->pendingChain[i-1];
            // this->pendingChain.erase(this->pendingChain.begin() + i - 1);
            std::cout << "size : " << (int)this->mainChain.size() << std::endl;
            std::cout << findNum << std::endl;
            int targetIdx = binarySearch(findNum, std::min((int)std::pow(2, n) - 1, (int)this->mainChain.size()), this->mainChain);
            this->mainChain.insert(this->mainChain.begin() + targetIdx, findNum);
            showMainChain();
        }
        n++;
    }
}

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
    return mid;
}

unsigned int PmergeMe::getSize() {
    return this->size;
}

// temp 함수
void PmergeMe::showPairs() {
    std::cout << "pairs : ";
    for (unsigned int i = 0; i < this->size / 2; i++) {
        std::cout << this->pairs[i]->first << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showMainChain() {
    std::cout << "main chain : ";
    for (std::vector<int>::iterator it = this->mainChain.begin(); it != this->mainChain.end() ;it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showPendingChain() {
    std::cout << "pending chain : ";
    for (unsigned int i = 0; i < this->size / 2; i++) {
        std::cout << this->pendingChain[i] << " ";
    }
    if (this->size % 2 == 1) {
        std::cout << this->pendingChain[this->size / 2] << " ";
    }
    std::cout << std::endl;
}