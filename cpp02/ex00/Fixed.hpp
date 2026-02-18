#pragma once

class Fixed 
{
    public:
        Fixed();
        Fixed( Fixed &other );
        Fixed &operator=( const Fixed &other );
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int val;
        static const int frac = 8;
    
};
