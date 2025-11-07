#pragma once

#include <string>
#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();

    void attack();
    void setWeapon(Weapon& weapon);

private:
    std::string name;
    Weapon &weapon;
};
