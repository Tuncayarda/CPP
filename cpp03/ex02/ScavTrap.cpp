#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
    this->_name = "ScavTrap";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap( std::string &name)
{
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap Default constructor called with name." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called with name." << std::endl;
};

ScavTrap::ScavTrap( ScavTrap &other)
{
    std::cout << "ScavTrap Copy constructor called." << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
    if ( this != &other)
    {
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
        std::cout << "ScavTrap Assign operator called." << std::endl;
    }
    return *this;
}

void ScavTrap::attack( const std::string& target )
{
    if ( _hit_points && _energy_points )
    {
        _energy_points--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl; 
    }
}

void ScavTrap::guardGate()
{
    std::cout << "Like a stone." << std::endl;
}