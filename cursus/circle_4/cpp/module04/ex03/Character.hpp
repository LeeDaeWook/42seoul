#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__
# include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        std::string name;
        AMateria *inventory[4];
        AMateria *addressDB;

        void checkAddress();
        
    public:
        Character();
        Character(std::string const& name);
        Character(const Character& iCharacter);
        Character& operator=(const Character& iCharacter);
        ~Character();

        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif