#pragma once

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap( std::string& name );
        FragTrap( FragTrap &other );
        FragTrap &operator=( const FragTrap& other );
        ~FragTrap();

        void highFivesGuys( void );
        void attack( const std::string& target );

    protected:

    private:
        
};