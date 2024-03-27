#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__
# include <iostream>
# include <string>
# include <list>

template <typename T>
typename T::iterator easyfind(T cont, int e) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), e);
    if (it == cont.end())
        throw std::exception();
    else
        return it;
}

#endif