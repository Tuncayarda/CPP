#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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

    std::cout << "----- ScavTrap tests -----" << std::endl;

    ScavTrap s1;
    std::string sname = "Guardian";
    ScavTrap s2(sname);

    s1.attack("EnemyA");
    s2.attack("EnemyB");

    s1.takeDamage(30);
    s2.takeDamage(99);

    s1.beRepaired(10);
    s2.beRepaired(5);

    s1.guardGate();
    s2.guardGate();

    ScavTrap s3(s2);
    s3.attack("EnemyC");
    s3.guardGate();

    ScavTrap s4;
    s4 = s1;
    s4.attack("EnemyD");
    s4.guardGate();

    s2.takeDamage(200);
    s2.attack("EnemyE");
    s2.beRepaired(50);
    s2.guardGate();

    return 0;
}