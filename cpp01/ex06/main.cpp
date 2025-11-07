#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    Harl harl;
    std::string level = av[1];
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            index = i;
            break;
        }
    }

    switch (index)
    {
        case 3:
            harl.complain("ERROR");
            break;
        case 2:
            harl.complain("WARNING");
            harl.complain("ERROR");
            break;
        case 1:
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
            break;
        case 0:
            harl.complain("DEBUG");
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
            break;
        default:
            break;
    }

    return 0;
}
