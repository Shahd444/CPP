#include "Fixed.hpp"

Fixed::Fixed()
    : fixed_value(0)
{

}
Fixed::~Fixed()
{

}
int Fixed::getRawBits(void) const
{
    return this->fixed_value;
}

void    Fixed::setRawBits(int const raw)
{
    this->fixed_value = raw;
}
Fixed::Fixed(const Fixed &old_obj)
{
    this->fixed_value = old_obj.fixed_value;
}

Fixed& Fixed::operator=(const Fixed &ref)
{
    if (&ref == this)
        return *this;
    this->fixed_value = ref.fixed_value;
    return *this;
}

Fixed::Fixed(const int num)
{
    this->fixed_value = num << fractional_bits;
}

Fixed::Fixed(const float float_num)
{
    this->fixed_value = roundf(float_num * 256.0f);
}

int Fixed::toInt( void ) const
{
    return this->fixed_value >> 8;
}

float Fixed::toFloat( void ) const
{
    return this->fixed_value / 256.0f;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    return out << obj.toFloat();
}

bool Fixed::operator==(const Fixed& ref) const
{
    return this->fixed_value == ref.fixed_value;
}

bool Fixed::operator!=(const Fixed& ref) const
{
    return this->fixed_value != ref.fixed_value;
}

bool Fixed::operator>(const Fixed& ref) const
{
    return this->fixed_value > ref.fixed_value;
}

bool Fixed::operator<(const Fixed& ref) const
{
    return this->fixed_value < ref.fixed_value;
}

bool Fixed::operator>=(const Fixed& ref) const
{
    return this->fixed_value >= ref.fixed_value;
}

bool Fixed::operator<=(const Fixed& ref) const
{
    return this->fixed_value <= ref.fixed_value;
}

Fixed Fixed::operator+(const Fixed& num) const
{
    return this->fixed_value + num.fixed_value;
}

Fixed Fixed::operator-(const Fixed& num) const
{
    return this->fixed_value - num.fixed_value;
}

Fixed Fixed::operator*(const Fixed& num) const
{
    Fixed res;
    res.setRawBits((this->fixed_value * num.fixed_value) >> fractional_bits);
    return res;
}

Fixed Fixed::operator/(const Fixed& num) const
{
    return Fixed((this->fixed_value << fractional_bits) / num.fixed_value);
}

Fixed& Fixed::operator++()
{
    this->fixed_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->fixed_value++;
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->fixed_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
     Fixed tmp(*this);
    this->fixed_value--;
    return tmp;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
    if (num1 > num2)
        return num2;
    else
        return num1;
}
const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
    if (num1 > num2)
        return num2;
    else
        return num1;
}
Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
     if (num1 > num2)
        return num1;
    else
        return num2;
}
const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
     if (num1 > num2)
        return num1;
    else
        return num2;
}
