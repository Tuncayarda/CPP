#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

std::string truncate(std::string input);
bool is_digits_only(std::string str);

PhoneBook::PhoneBook() { _count = 0; }
PhoneBook::~PhoneBook() {}

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
	if (is_digits_only(input))
		contact.setPhoneNumber(input);
	else
	{
		std::cout << "Invalid Phone Number (Digits Only)" << std::endl;
		return ;
	}

	std::cout << "Darkest Secret: ";
	if (std::getline(std::cin, input).eof())
		return ;
	contact.setDarkestSecret(input);

	this->contacts[_count % 8] = contact;
	this->contacts[_count % 8].setAsFilled();
	if (_count != 8)
		_count++;
}

void PhoneBook::search(int idx)
{
	if (idx == -1)
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
	else if (idx <= 7 && idx >= 0)
	{
		if (this->contacts[idx].getFilledStatus())
		{
			std::cout << "First Name: " << this->contacts[idx].getFirstName() << std::endl;
			std::cout << "Last Name: " << this->contacts[idx].getLastName() << std::endl;
			std::cout << "Nick Name: " << this->contacts[idx].getNickName() << std::endl;
			std::cout << "Phone Number: " << this->contacts[idx].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << this->contacts[idx].getDarkestSecret() << std::endl;
		}
		else std::cout << "Empty Field" << std::endl;
	}
	else std::cout << "Invalid index (0-7)" << std::endl;
}
