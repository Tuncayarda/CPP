#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("ClapTrap"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string &name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called with name." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called with name." << std::endl;
};

ClapTrap::ClapTrap( ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called." << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other )
{
    if ( this != &other)
    {
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
        std::cout << "ClapTrap Assign operator called." << std::endl;
    }
    return *this;
}

void ClapTrap::attack( const std::string& target )
{
    if ( _hit_points && _energy_points )
    {
        _energy_points--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl; 
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points == 0)
    {
        std::cout << "ClapTrap " << _name << " is already destroyed." << std::endl;
        return;
    }

    if (_hit_points < amount)
        _hit_points = 0;
    else
        _hit_points -= amount;

    std::cout << "ClapTrap " << _name << " takes " << amount << " damage. Hit points left: " << _hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_points == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot be repaired because it is destroyed." << std::endl;
        return;
    }

    if (_energy_points == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy left to repair." << std::endl;
        return;
    }

    _energy_points--;
    _hit_points += amount;

    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points." << std::endl;
}
