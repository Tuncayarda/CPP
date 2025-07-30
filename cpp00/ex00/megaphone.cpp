#include <iostream>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		for (int i = 0; av[1][i] != '\0'; ++i)
		{
			if (std::islower(av[1][i]))
				std::cout << (char)std::toupper(av[1][i]);
			else
				std::cout << av[1][i];
		}
		std::cout << std::endl;
	}
	return 0;
}
