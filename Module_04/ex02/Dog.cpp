#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &old_obj)
{
    std::cout << "Dog copy constructor called\n";
    this->type = old_obj.type;
    this->brain = new Brain(*old_obj.brain);
}

Dog& Dog::operator=(const Dog &ref)
{
    std::cout << "Dog copy assignment operator called\n";
    if(&ref == this)
        return *this;
    delete this->brain;
    this->brain = new Brain(*ref.brain);
    this->type = ref.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "bark!\n";
}

const std::string& Dog::getType() const
{
    return this->type;
}