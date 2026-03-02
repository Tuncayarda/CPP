#pragma once

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap( std::string& name );
        ScavTrap( ScavTrap &other );
        ScavTrap &operator=( const ScavTrap& other );
        ~ScavTrap();

        void guardGate();
        void attack( const std::string& target );

    protected:

    private:
        
};