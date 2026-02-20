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
    raw = roundf(val * 256);
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

bool Fixed::operator<( const Fixed &other )
{
    return (this->raw < other.raw);
}


bool Fixed::operator>( const Fixed &other )
{
    return (this->raw > other.raw);
}


bool Fixed::operator>=( const Fixed &other )
{
    return (this->raw >= other.raw);
}


bool Fixed::operator<=( const Fixed &other )
{
    return (this->raw <= other.raw);
}


bool Fixed::operator==( const Fixed &other )
{
    return (this->raw == other.raw);
}


bool Fixed::operator!=( const Fixed &other )
{
    return (this->raw != other.raw);
}

Fixed &Fixed::operator+( const Fixed &other )
{
    Fixed res;

    res.setRawBits(this->raw + other.getRawBits());
    return res;
}

Fixed &Fixed::operator-( const Fixed &other )
{
    Fixed res;

    res.setRawBits(this->raw - other.getRawBits());
    return res;
}

Fixed &Fixed::operator*( const Fixed &other )
{
    Fixed res;

    res.setRawBits((this->raw / (1 << frac)) * other.getRawBits());
    return res;
}

Fixed &Fixed::operator/( const Fixed &other )
{
    Fixed res;

    res.setRawBits((this->raw << frac) / other.getRawBits());
    return res;
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
