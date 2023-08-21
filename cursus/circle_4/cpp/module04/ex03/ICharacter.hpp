#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__
# include <iostream>
# include <string>

class AMateria;

class ICharacter {
    public:
        std::string name;

        AMateria *inventory[4];
        AMateria *addressDB;

        // ICharacter();
        // ICharacter(std::string const& type);
        // ICharacter(const ICharacter& iCharacter);
        // ICharacter& operator=(const ICharacter& iCharacter);
        virtual ~ICharacter() {};
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif