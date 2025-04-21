#include "Contact.hpp"

Contact::Contact()
{
	name = "EMPTY";
	last_name = "EMPTY";
	nickname = "EMPTY";
	phone_number = "EMPTY";
	phone_number = "EMPTY";
	darkest_secret = "EMPTY";
}

int Contact::printable(std::string str)
{
	size_t count = 0;

	if (str[0] == '\0' || str[0] == '\n')
		return 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == 32)
			count++;
		if (str[i] < 32 || str[i] > 126)
			return 0;
	}
	if (count == str.length())
		return 0;
	return 1;
}
int Contact::all_digit(std::string str)
{
	if (str[0] == '\0')
		return 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

int Contact::set_phone(std::string phone)
{
	if (all_digit(phone))
	{
		phone_number = phone;
		return 1;
	}
	return 0;
}

int Contact::set_secret(std::string secret)
{
	if (printable(secret))
	{
		darkest_secret = secret;
		return 1;
	}
	return 0;
}

int Contact::set_nickname(std::string nickname)
{
	if (printable(nickname))
	{
		this->nickname = nickname;
		return 1;
	}
	return 0;
}

int Contact::set_last_name(std::string last_name)
{
	if (printable(last_name))
	{
		this->last_name = last_name;
		return 1;
	}
	return 0;
}

int Contact::set_name(std::string name)
{
	if (printable(name))
	{
		this->name = name;
		return 1;
	}
	return 0;
}
