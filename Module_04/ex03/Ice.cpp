#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice &old_obj) : AMateria(old_obj)
{
    std::cout << "Ice copy constructor called\n";
}
Ice& Ice::operator=(const Ice &ref)
{
    if (&ref != this)
        AMateria::operator=(ref);
    return *this;
}
Ice::~Ice()
{
    std::cout << "Ice destructor called\n";
}
AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}