#include "Animal.hpp"

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor." << std::endl;
}

Animal::Animal(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy constructor." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy assignement constructor." << std::endl;
	return *this;
}

const std::string& Animal::getType() const
{
	return type;
}
