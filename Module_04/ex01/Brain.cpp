#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &old_obj)
{
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; i++)
        this->ideas[i] = old_obj.ideas[i];
}

Brain& Brain::operator=(const Brain &ref)
{
    std::cout << "Brain copy assignment operator called\n";
    if(&ref == this)
        return *this;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = ref.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}