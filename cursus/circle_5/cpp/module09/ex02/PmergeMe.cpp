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
        for (iter = PmergeMe.list.begin(); iter != PmergeMe.list.end(); ++iter)
            this->list.push_back(*iter);
    }
    return *this;
}

void PmergeMe::addElement(int number) {
    this->list.push_back(number);
}

void PmergeMe::show() {
    std::list<int>::iterator it;

    for (it = this->list.begin(); it != this->list.end(); it++) {
        std::cout << *it << std::endl;
    }
}

void PmergeMe::split(int* inputArr, int size) {
    this->size = size;
    if (!this->pairs) {
        this->pairs = new std::pair<int, int>*[size];
    }
    for (int i = 0; i < size / 2; i++) {
        this->pairs[i] = new std::pair<int, int>;
        this->pairs[i]->first = inputArr[i * 2];
        this->pairs[i]->second = inputArr[i * 2 + 1];
        sortPair(this->pairs[i]);
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

// temp 함수
void PmergeMe::showPairs() {
    for (unsigned int i = 0; i < this->size / 2; i++) {
        std::cout << this->pairs[i]->first << std::endl;
    }
}

unsigned int PmergeMe::getSize() {
    return this->size;
}
