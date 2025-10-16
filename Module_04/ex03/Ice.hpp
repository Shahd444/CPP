#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &old_obj);
    Ice& operator=(const Ice &ref);
    ~Ice();
    AMateria* clone() const;
    void use(ICharacter& target);
};

# endif