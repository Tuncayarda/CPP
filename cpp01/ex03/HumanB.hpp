#pragma once

#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
    HumanB();
    HumanB(const std::string& name);
    ~HumanB();

    void attack();
    void setWeapon(Weapon& weapon);

private:
    std::string name;
    Weapon *weapon;
};
