#ifndef __CAT_HPP__
# define __CAT_HPP__
# include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat();
        Cat(const Cat& cat);
        Cat& operator=(const Cat& cat);

        void makeSound() const;
};

#endif