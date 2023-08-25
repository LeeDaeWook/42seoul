#ifndef __CAT_HPP__
# define __CAT_HPP__
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* brain;
        
    public:
        Cat();
        ~Cat();
        Cat(const Cat& cat);
        Cat& operator=(const Cat& cat);

        void makeSound() const;
        Brain* getBrain();
        void setBrain(Brain* brain);
};

#endif