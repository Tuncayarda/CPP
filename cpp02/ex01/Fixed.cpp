#include <math.h>
#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int val )
{
    std::cout << "Int constructor called" << std::endl;
    raw = val << frac;
}

Fixed::Fixed( const float val )
{
    std::cout << "Float constructor called" << std::endl;
    raw = roundf(val * (1 << frac));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) : raw(other.raw)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

float Fixed::toFloat() const
{
    return ((float)raw / (1 << frac));
}

int Fixed::toInt( void ) const
{
    return raw >> frac;
}

Fixed &Fixed::operator=( const Fixed &other )
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other)
        raw = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return raw;
}

void Fixed::setRawBits( int const raw )
{
    this->raw = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}
