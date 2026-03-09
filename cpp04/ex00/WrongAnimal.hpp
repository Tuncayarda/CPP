
#pragma once

#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal( WrongAnimal &other );
        WrongAnimal &operator= ( const WrongAnimal &other );
        ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;

    protected:
        std::string type;

    private:
};