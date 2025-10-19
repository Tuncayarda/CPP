#include "Zombie.hpp"

int main() {

    Zombie *z1 = NULL;

    z1 = z1->newZombie("Zombie1");
    z1->announce();

    z1->randomChump("Zombie2");

    delete z1;
    return 0;
}
