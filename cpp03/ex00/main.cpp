#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a;
    std::string name = "Tuncay";
    ClapTrap b(name);

    a.attack("Enemy1");
    b.attack("Enemy2");

    a.takeDamage(5);
    b.takeDamage(3);

    a.beRepaired(2);
    b.beRepaired(4);

    ClapTrap c(b);
    c.attack("Enemy3");

    ClapTrap d;
    d = a;
    d.attack("Enemy4");

    a.takeDamage(20);
    a.attack("Enemy5");
    a.beRepaired(5);

    return 0;
}