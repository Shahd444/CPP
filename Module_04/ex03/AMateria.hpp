#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
protected:
    std::string type;
public:
AMateria();
AMateria(std::string const & type);
AMateria(const AMateria &old_obj);
AMateria& operator=(const AMateria &ref);
virtual ~AMateria();
std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};

# endif