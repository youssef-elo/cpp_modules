#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Meoooooooooooooooooow" << std::endl;
}

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor." << std::endl;
}
Cat::~Cat()
{
	std::cout << type << " is being destroyed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	type = other.type;
	std::cout << "Cat copy assignement operator." << std::endl;
	return *this;
}
