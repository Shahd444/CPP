#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int fixed_value;
    static const int    fractional_bits = 8;
public:
    Fixed();
    Fixed(const Fixed &old_obj);
    Fixed(const int num);
    Fixed(const float float_num);
    Fixed& operator=(const Fixed &ref);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

# endif