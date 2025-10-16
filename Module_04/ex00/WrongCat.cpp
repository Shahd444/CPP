#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &old_obj)
{
    std::cout << "WrongCat copy constructor called\n";
    this->type = old_obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat &ref)
{
    std::cout << "WrongCat copy assignment operator called\n";
    if(&ref == this)
        return *this;
    this->type = ref.type;
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat sounds\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";    
}