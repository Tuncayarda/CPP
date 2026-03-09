#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat( Cat &other );
        Cat &operator= ( const Cat &other );
        ~Cat();

        void makeSound() const;

    protected:

    private:
};