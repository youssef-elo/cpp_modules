#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact list[8];
	int index;
public:
	PhoneBook();
	int set_name(std::string name);
	int set_last_name(std::string last_name);
	int set_nickname(std::string nickname);
	int set_phone(std::string phone_number);
	int set_secret(std::string secret);
};

#endif