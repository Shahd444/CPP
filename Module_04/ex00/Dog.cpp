#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &old_obj)
{
    std::cout << "Dog copy constructor called\n";
    this->type = old_obj.type;
}

Dog& Dog::operator=(const Dog &ref)
{
    std::cout << "Dog copy assignment operator called\n";
    if(&ref == this)
        return *this;
    this->type = ref.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "bark!\n";
}

const std::string& Dog::getType() const
{
    return this->type;
}