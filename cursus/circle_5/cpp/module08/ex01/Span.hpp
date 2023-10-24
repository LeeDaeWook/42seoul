#ifndef __SPAN_HPP__
# define __SPAN_HPP__
# include <iostream>
# include <string>
# include <list>

class Span {
    private:
        unsigned int n;
        std::list<int> list;

    public:
        Span();
        Span(unsigned int n);
        ~Span();
        Span(Span &span);
        Span &operator=(Span& span);

        void addNumber(int n);
        void addNumbers(unsigned int size, std::list<int>::iterator begin, std::list<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        std::list<int> copyList();

        unsigned int getSize();
        std::list<int> getList();
};

#endif