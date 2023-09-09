#ifndef __ICE_HPP__
# define __ICE_HPP__
# include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        Ice(std::string const& type);
        virtual ~Ice();
        Ice(const Ice& ice);
        Ice& operator=(const Ice& ice);

        Ice* clone() const;
        void use(ICharacter& target);
};

#endif