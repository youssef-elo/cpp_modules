#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0){}

int PhoneBook::set_name(std::string name)
{
	if (list[index].set_name(name))
		return 1;
	return 0;
}

int PhoneBook::set_last_name(std::string last_name)
{
	if (list[index].set_last_name(last_name))
		return 1;
	return 0;
}

int PhoneBook::set_nickname(std::string nickname)
{
	if (list[index].set_nickname(nickname))
		return 1; 
	return 0;
}

int PhoneBook::set_phone(std::string phone_number)
{
	if (list[index].set_phone(phone_number))
		return 1;
	return 0;
}

int PhoneBook::set_secret(std::string secret)
{
	if (list[index].set_secret(secret))
	{
		index = ((index + 1) % 8);
		return 1;
	}
	return 0;
}