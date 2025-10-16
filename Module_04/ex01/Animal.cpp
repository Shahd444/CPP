#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &old_obj)
{
    std::cout << "Animal copy constructor called\n";
    this->type = old_obj.type;
}

Animal& Animal::operator=(const Animal &ref)
{
    std::cout << "Animal copy assignment operator called\n";
    if(&ref == this)
        return *this;
    this->type = ref.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

const std::string& Animal::getType() const
{
    return this->type;
}
