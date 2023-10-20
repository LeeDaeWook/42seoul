#ifndef __ITER_HPP__
# define __ITER_HPP__
# include <iostream>
# include <string>

template <typename T>
void iter(T *addr, size_t len, void (*funcPtr)(T &e))
{
    std::cout << "function template T called" << std::endl;
    for (size_t i = 0; i < len; i++) {
        funcPtr(addr[i]);
    }
}

template <typename T>
void iter(const T *addr, size_t len, void (*funcPtr)(const T &e))
{
    std::cout << "function template const T called" << std::endl;
    for (size_t i = 0; i < len; i++) {
        funcPtr(addr[i]);
    }
}

template <typename T>
void printElement(T &e)
{
    std::cout << "printElement T called" << std::endl;
    std::cout << e << std::endl;
}

template <typename T>
void printElement(const T &e)
{
    std::cout << "printElement const T called" << std::endl;
    std::cout << e << std::endl;
}

#endif