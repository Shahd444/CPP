#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &old_obj)
{
    std::cout << "Cat copy constructor called\n";
    this->type = old_obj.type;
}

Cat& Cat::operator=(const Cat &ref)
{
    std::cout << "Cat copy assignment operator called\n";
    if(&ref == this)
        return *this;
    this->type = ref.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}
const std::string& Cat::getType() const
{
    return this->type;
}