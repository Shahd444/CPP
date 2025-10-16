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
    bool operator==(const Fixed& ref) const;
    bool operator!=(const Fixed& ref) const;
    bool operator>(const Fixed& ref) const;
    bool operator<(const Fixed& ref) const;
    bool operator>=(const Fixed& ref) const;
    bool operator<=(const Fixed& ref) const;
    Fixed operator+(const Fixed& num) const;
    Fixed operator-(const Fixed& num) const;
    Fixed operator*(const Fixed& num) const;
    Fixed operator/(const Fixed& num) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    static  Fixed& min(Fixed& num1, Fixed& num2);
    static  const Fixed& min(const Fixed& num1, const Fixed& num2);
    static  Fixed& max(Fixed& num1, Fixed& num2);
    static  const Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

# endif