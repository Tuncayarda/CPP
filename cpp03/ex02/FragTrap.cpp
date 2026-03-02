#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
    this->_name = "FragTrap";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Default constructor called." << std::endl;
}

FragTrap::FragTrap( std::string &name)
{
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Default constructor called with name." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called with name." << std::endl;
};

FragTrap::FragTrap( FragTrap &other)
{
    std::cout << "FragTrap Copy constructor called." << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=( const FragTrap &other )
{
    if ( this != &other)
    {
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
        std::cout << "FragTrap Assign operator called." << std::endl;
    }
    return *this;
}

void FragTrap::attack( const std::string& target )
{
    if ( _hit_points && _energy_points )
    {
        _energy_points--;
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl; 
    }
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "High Five." << std::endl;
}
