#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called." << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat &other )
{
    std::cout << "WrongCat copy constructor called." << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator= ( const WrongCat &other )
{
    std::cout << "WrongCat assign operator called." << std::endl;
    if ( this != &other )
        this->type = other.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow." << std::endl;
}

