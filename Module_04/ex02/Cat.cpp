#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &old_obj)
{
    std::cout << "Cat copy constructor called\n";
    this->type = old_obj.type;
    this->brain = new Brain(*old_obj.brain);
}

Cat& Cat::operator=(const Cat &ref)
{
    std::cout << "Cat copy assignment operator called\n";
    if(&ref == this)
        return *this;
    this->type = ref.type;
    delete this->brain;
    this->brain = new Brain(*ref.brain);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}
const std::string& Cat::getType() const
{
    return this->type;
}