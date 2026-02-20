#pragma once
#include <iostream>

class Fixed 
{
    public:
        Fixed();
        Fixed( const Fixed &other );
        Fixed( const int val );
        Fixed( const float val );
        Fixed &operator=( const Fixed &other );
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int raw;
        static const int frac = 8;
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);
