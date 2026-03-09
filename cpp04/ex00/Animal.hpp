#pragma once

#include <string>

class Animal
{
    public:
        Animal();
        Animal( Animal &other );
        Animal &operator= ( const Animal &other );
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;

    protected:
        std::string type;

    private:
};