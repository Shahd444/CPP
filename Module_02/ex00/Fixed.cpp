#include "Fixed.hpp"

Fixed::Fixed()
    : fixed_value(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->fixed_value;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->fixed_value = raw;
}
Fixed::Fixed(const Fixed &old_obj)
{
    std::cout << "Copy constructor called\n";
    this->fixed_value = old_obj.fixed_value;
}

Fixed& Fixed::operator=(const Fixed &ref)
{
    std::cout << "Copy assignment operator called\n";
    if (&ref == this)
        return *this;
    this->fixed_value = ref.fixed_value;
    return *this;
}
