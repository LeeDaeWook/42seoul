#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& wrongCat);
        WrongCat& operator=(const WrongCat& wrongCat);

        void makeSound() const;
};

#endif