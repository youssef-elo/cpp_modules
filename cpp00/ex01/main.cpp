#include "PhoneBook.hpp"


void display_prompt(std::string prompt, std::string &input)
{
	std::cout << prompt << " : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "\n"
				  << "EOF EXITING" << std::endl;
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

int main()
{
	PhoneBook book;
	std::string input;

	while (1)
	{
		// std::cin >> input;

		// if (std::cin.eof())
		// {
		// 	input = "";
		// 	std::cin.clear();
		// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 	// exit(0);
		// }
		// else
		// std::cout << input << std::endl;
		if (input == "ADD")
			read_input(book);
	}
}