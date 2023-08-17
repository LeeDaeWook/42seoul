#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__
# include <iostream>
# include <string>

class Animal {
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& animal);
        Animal& operator=(const Animal& animal);

        virtual void makeSound() const;
        std::string getType() const;
};

#endif