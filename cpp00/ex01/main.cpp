#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook   phoneBook;
	std::string input;

	while (1)
	{
		std::cout << ">";
		if (std::getline(std::cin, input).eof())
			break ;

		std::istringstream iss(input); 
		iss >> input;
	
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
		{
			int	idx = -1;

			iss >> idx;
			phoneBook.search(idx);
		}
		else if (input == "EXIT")
			break ;
	}

	return (0);
}
