#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &old_obj);
    WrongCat& operator=(const WrongCat &ref);
    ~WrongCat();
    void    makeSound() const;
};

# endif