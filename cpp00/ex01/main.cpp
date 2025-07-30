#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook   phoneBook;
	std::string input;

	while (1)
	{
		if (std::getline(std::cin, input).eof())
			break ;
		else if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (input == "EXIT")
			break ;
	}

	return (0);
}
