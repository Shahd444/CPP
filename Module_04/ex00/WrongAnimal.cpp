#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &old_obj)
{
    std::cout << "WrongAnimal copy constructor called\n";
    this->type = old_obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref)
{
    std::cout << "WrongAnimal copy assignment operator called\n";
    if(&ref == this)
        return *this;
    this->type = ref.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "wrong animal sounds\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

const std::string& WrongAnimal::getType() const
{
    return this->type;
}
