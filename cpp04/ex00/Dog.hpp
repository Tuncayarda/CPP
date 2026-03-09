#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog( Dog &other );
        Dog &operator= ( const Dog &other );
        ~Dog();

        void makeSound() const;

    protected:

    private:
};