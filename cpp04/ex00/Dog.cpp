#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor." << std::endl;
}
Dog::~Dog()
{
	std::cout << type << " is being destroyed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	type = other.type;
	std::cout << "Dog copy assignement operator." << std::endl;
	return *this;
}
