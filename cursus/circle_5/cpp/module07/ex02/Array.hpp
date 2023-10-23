#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__
# include <iostream>
# include <string>

template <typename T>
class Array {
    private:
        T* arr;
        unsigned int n;

    public:
        Array();
        Array(unsigned int n);
        virtual ~Array();
        Array(const Array& array);
        Array& operator=(const Array& array);
        T& operator[](unsigned int idx);

        unsigned int size();
};

#include "Array.tpp"

#endif