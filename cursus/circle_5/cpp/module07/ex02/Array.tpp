#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    std::cout << "Default Array constructor called" << std::endl;
    this->e = new T();
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    std::cout << "Default Array constructor called" << std::endl;
    this->e = new T(n);
    this->n = n;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Default Array destructor called" << std::endl;
    if (this->e)
        delete this->e;
}

template <typename T>
Array<T>::Array(const Array& array)
{
    std::cout << "Array Copy constructor called" << std::endl;
    *this = array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& array)
{
    std::cout << "Array Copy assignment operator called" << std::endl;
    if (this != &array) {
        for (unsigned int i = 0; i < this->n; i++)
            this->e[i] = array.e[i];
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size()
{
    return this->n;
}
