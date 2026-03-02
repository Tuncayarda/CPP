#pragma once

# include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap( std::string& name );
        ClapTrap( ClapTrap &other );
        ClapTrap &operator=( const ClapTrap& other );
        ~ClapTrap();

        virtual void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );

    protected:
        std::string _name;
        unsigned int _hit_points;
        unsigned int _energy_points;
        unsigned int _attack_damage;

    private:
        
};