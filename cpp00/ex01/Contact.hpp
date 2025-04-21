#ifndef  CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
class Contact
{
private:
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int all_digit(std::string str);
	int printable(std::string str);
public:
	Contact();
	int set_name(std::string name);
	int set_last_name(std::string last_name);
	int set_nickname(std::string nickname);
	int set_phone(std::string phone_number);
	int set_secret(std::string secret);
};

#endif
