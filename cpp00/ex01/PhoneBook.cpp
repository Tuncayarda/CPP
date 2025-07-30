#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

std::string truncate(std::string input);

PhoneBook::PhoneBook() { _count = 0; }

void PhoneBook::add()
{
	Contact		contact;
	std::string	input;

	std::cout << "First Name: ";
	if (std::getline(std::cin, input).eof())
		return ;
	contact.setFirstName(input);

	std::cout << "Last Name: ";
	if (std::getline(std::cin, input).eof())
		return ;
	contact.setLastName(input);

	std::cout << "Nick Name: ";
	if (std::getline(std::cin, input).eof())
		return ;
	contact.setNickName(input);

	std::cout << "Phone Number: ";
	if (std::getline(std::cin, input).eof())
		return ;
	contact.setPhoneNumber(input);

	std::cout << "Darkest Secret: ";
	if (std::getline(std::cin, input).eof())
		return ;
	contact.setDarkestSecret(input);

	this->contacts[_count % 8] = contact;

	_count++;
}

void PhoneBook::search()
{
	std::cout << "|     Index|First Name| Last Name| Nick Name|" << std::endl;
	for (size_t i = 0; i < _count; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getFirstName());
		std::cout << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getLastName());
		std::cout << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
}
