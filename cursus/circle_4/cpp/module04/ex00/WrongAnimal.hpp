#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__
# include <iostream>
# include <string>

class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& wrongAnimal);
        WrongAnimal& operator=(const WrongAnimal& wrongAnimal);

        void makeSound() const;
        std::string getType() const;
};

#endif