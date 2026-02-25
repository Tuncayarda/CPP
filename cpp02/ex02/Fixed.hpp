#pragma once
#include <iostream>

class Fixed 
{
    public:
        Fixed();
        Fixed( const Fixed &other );
        Fixed( const int val );
        Fixed( const float val );
        ~Fixed();

        Fixed &operator=( const Fixed &other );
        bool operator<( const Fixed &other ) const;
        bool operator>( const Fixed &other ) const;
        bool operator>=( const Fixed &other ) const;
        bool operator<=( const Fixed &other ) const;
        bool operator==( const Fixed &other ) const;
        bool operator!=( const Fixed &other ) const;

        Fixed operator+( const Fixed &other ) const;
        Fixed operator-( const Fixed &other ) const;
        Fixed operator*( const Fixed &other ) const;
        Fixed operator/( const Fixed &other ) const;

        Fixed &operator++( void );
        Fixed operator++( int );

        Fixed &operator--( void );
        Fixed operator--( int );

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);

        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int raw;
        static const int frac = 8;
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);
