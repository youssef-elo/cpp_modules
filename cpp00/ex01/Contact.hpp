#ifndef  CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <iomanip>

class Contact
{
private:
	int index;
	int initialized;
	static int start_index;
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int all_digit(std::string str);
	int printable(std::string str);
	std::string truncate(std::string);
public:
	Contact();
	int is_initiliazed();
	int print_info();
	int full_info();
	int set_name(std::string name);
	int set_last_name(std::string last_name);
	int set_nickname(std::string nickname);
	int set_phone(std::string phone_number);
	int set_secret(std::string secret);
};

#endif
