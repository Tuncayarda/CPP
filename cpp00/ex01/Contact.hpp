#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();

		void	setFirstName(std::string);
		void	setLastName(std::string);
		void	setNickName(std::string);
		void	setPhoneNumber(std::string);
		void	setDarkestSecret(std::string);
		void	setAsFilled();

		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
		bool		getFilledStatus();

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
		bool		_is_filled;
};

#endif