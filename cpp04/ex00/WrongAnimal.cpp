#include "WrongAnimal.hpp"


void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal constructor." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	type = other.type;
	std::cout << "WrongAnimal copy constructor." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	type = other.type;
	std::cout << "WrongAnimal copy assignement constructor." << std::endl;
	return *this;
}

const std::string& WrongAnimal::getType() const
{
	return type;
}
