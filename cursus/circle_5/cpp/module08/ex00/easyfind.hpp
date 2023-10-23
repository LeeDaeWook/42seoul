#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__
# include <iostream>
# include <string>
# include <list>

template <typename T>
void easyfind(T cont, int e) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), e);
    if (it == cont.end())
        throw std::exception();
    else
        std::cout << "Find " << e << " in container!" << std::endl;
}

#endif