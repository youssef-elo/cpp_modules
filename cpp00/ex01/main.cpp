#include "PhoneBook.hpp"

void display_prompt(std::string prompt, std::string &input)
{
	std::cout << prompt << " : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl << "EOF EXITING" << std::endl;
		exit(0);
	}
	if (input.empty())
		display_prompt(prompt, input);
}

void read_input(PhoneBook &book)
{
	std::string input;

	display_prompt("ENTER NAME", input);
	while (!book.set_name(input))
		display_prompt("ENTER NAME", input);

	display_prompt("ENTER LAST NAME", input);
	while (!book.set_last_name(input))
		display_prompt("ENTER LAST NAME", input);

	display_prompt("ENTER NICKNAME", input);
	while (!book.set_nickname(input))
		display_prompt("ENTER NICKNAME", input);

	display_prompt("ENTER PHONE NUMBER", input);
	while (!book.set_phone(input))
		display_prompt("ENTER PHONE NUMBER", input);

	display_prompt("ENTER DARKEST SECRET", input);
	while (!book.set_secret(input))
		display_prompt("ENTER DARKEST SECRET", input);
}

int get_index(PhoneBook &book, std::string prompt)
{
	std::string input;
	int index;

	display_prompt(prompt, input);
	if (input[0] == '+' && input.length() == 2)
	{
		input[0] = input[1];
		input[1] = '\0';
	}
	else if (input.length() != 1)
	{
		std::cout << "Index must be an integer in the range 1-8" << std::endl;
		return 0;
	}
	index = input[0] - '0';
	if (index > 8 || index < 1)
	{
		std::cout << "Index must be an integer in the range 1-8" << std::endl;
		return 0;
	}
	if (!book.list_item(index - 1))
	{
		std::cout << "Contact does not exist" << std::endl;
		return 0;
	}
	return 1;
}

void start_search(PhoneBook &book)
{
	book.list_contacts();
	while (!get_index(book, "Enter an index for more info on a contact"));
}

int main()
{
	PhoneBook book;
	std::string input;

	while (1)
	{
		display_prompt("Enter a Command : ADD, SEARCH, EXIT", input);
		if (input == "EXIT")
			return 0;
		if (input == "ADD")
			read_input(book);
		if (input == "SEARCH")
			start_search(book);
	}
	return 0;
}