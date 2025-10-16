#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
    std::cout << "AMateria type set constructor called\n";
}
AMateria::AMateria(const AMateria &old_obj)
{
    this->type = old_obj.type;
    std::cout << "AMateria copy constructor called\n";
}
AMateria& AMateria::operator=(const AMateria &ref)
{
    if (&ref == this)
        return *this;
    this->type = ref.type;
    return *this;
}
AMateria::~AMateria()
{
    std::cout << "AMateria destructor called\n";
}
std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}