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

bool Fixed::operator<( const Fixed &other ) const
{
    return (this->raw < other.raw);
}


bool Fixed::operator>( const Fixed &other ) const
{
    return (this->raw > other.raw);
}


bool Fixed::operator>=( const Fixed &other ) const
{
    return (this->raw >= other.raw);
}


bool Fixed::operator<=( const Fixed &other ) const
{
    return (this->raw <= other.raw);
}


bool Fixed::operator==( const Fixed &other ) const
{
    return (this->raw == other.raw);
}


bool Fixed::operator!=( const Fixed &other ) const
{
    return (this->raw != other.raw);
}

Fixed Fixed::operator+( const Fixed &other ) const
{
    Fixed res;

    res.setRawBits(this->raw + other.getRawBits());
    return res;
}

Fixed Fixed::operator-( const Fixed &other ) const
{
    Fixed res;

    res.setRawBits(this->raw - other.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;
    long tmp = (long)this->raw * (long)other.getRawBits();
    res.setRawBits((int)(tmp >> frac));
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed res;
    long num = ((long)this->raw << frac);
    res.setRawBits((int)(num / other.getRawBits()));
    return res;
}

int Fixed::getRawBits( void ) const
{
    return raw;
}

Fixed &Fixed::operator++( void )
{
    this->raw += 1;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed res;

    res.raw = this->raw;
    this->raw += 1;
    return res;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

void Fixed::setRawBits( int const raw )
{
    this->raw = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}
