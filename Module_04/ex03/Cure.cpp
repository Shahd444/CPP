#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure &old_obj) : AMateria(old_obj)
{
    std::cout << "Cure copy constructor called\n";
}
Cure& Cure::operator=(const Cure &ref)
{
    if (&ref != this)
        AMateria::operator=(ref);
    return *this;
}
Cure::~Cure()
{
    std::cout << "Cure destructor called\n";
}
AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}