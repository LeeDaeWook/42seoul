#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__
# include "ICharacter.hpp"

class AMateria {
    protected:
        std::string type;

    public:
        AMateria();
        AMateria(std::string const& type);
        virtual ~AMateria();
        AMateria(const AMateria& aMateria);
        AMateria& operator=(const AMateria& aMateria);

        std::string const& getType() const; // returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif