#include "Dog.hpp"

#include <iostream>

Dog::Dog()
{
    std::cout << "Dog constructor called." << std::endl;
    this->type = "Dog";
}

Dog::Dog( Dog &other )
{
    std::cout << "Dog copy constructor called." << std::endl;
    *this = other;
}

Dog &Dog::operator= ( const Dog &other )
{
    std::cout << "Dog assign operator called." << std::endl;
    if ( this != &other )
        this->type = other.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark." << std::endl;
}

