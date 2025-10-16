#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fixed_value;
    static const int    fractional_bits = 8;
public:
    Fixed();
    Fixed(const Fixed &old_obj);
    Fixed& operator=(const Fixed &ref);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

# endif