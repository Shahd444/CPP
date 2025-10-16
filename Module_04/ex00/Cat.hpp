#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &old_obj);
    Cat& operator=(const Cat &ref);
    ~Cat();
    void    makeSound() const;
    const std::string& getType() const;
};

# endif