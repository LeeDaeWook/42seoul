#include "Span.hpp"

Span::Span() : n(0)
{
    std::cout << "Default Span constructor called" << std::endl;
}

Span::Span(unsigned int n) : n(n)
{
    std::cout << "Parameter Span constructor called" << std::endl;
}

Span::~Span()
{
    std::cout << "Default Span destructor called" << std::endl;
}

Span::Span(Span &span)
{
    std::cout << "Span Copy constructor called" << std::endl;
    *this = span;
}

Span &Span::operator=(Span &span)
{
    std::cout << "Span Copy assignment operator called" << std::endl;
    std::list<int>::iterator iter;

    if (this != &span)
    {
        this->n = span.n;
        for (iter = span.list.begin(); iter != span.list.end(); ++iter)
            this->list.push_back(*iter);
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (this->n > this->list.size())
        this->list.push_back(num);
    else
        throw std::exception();
}

std::list<int> Span::copyList()
{
    std::list<int>::iterator iter;
    std::list<int> copyList; 

    for (iter = list.begin(); iter != list.end(); ++iter) {
        copyList.push_back(*iter);
    }
    return copyList;
}

int Span::shortestSpan()
{
    if (list.size() <= 1)
        throw std::exception();

    std::list<int> copyLt = copyList();
    copyLt.sort();

    int shortestSpan = std::numeric_limits<int>::max();
    std::list<int>::reverse_iterator iter;

    for (iter = copyLt.rbegin(); iter != --(copyLt.rend()); ++iter)
    {
        int span = *iter - *(++iter);
        if (span < shortestSpan)
            shortestSpan = span;
        --iter;
    }
    return shortestSpan;
}

int Span::longestSpan()
{
    if (list.size() <= 1)
        throw std::exception();

    std::list<int> copyLt = copyList();
    copyLt.sort();

    return copyLt.back() - copyLt.front();
}

void Span::addNumbers(unsigned int size, std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if (this->n >= this->list.size() + size)
        this->list.insert(this->list.end(), begin, end);
    else
        throw std::exception();
}

unsigned int Span::getSize()
{
    return this->n;
}

std::list<int> Span::getList()
{
    return this->list;
}
