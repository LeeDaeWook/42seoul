#ifndef __DOG_HPP__
# define __DOG_HPP__
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:

    public:
        Dog();
        ~Dog();
        Dog(const Dog& dog);
        Dog& operator=(const Dog& dog);

        void makeSound() const;

        Brain* brain;

};

#endif