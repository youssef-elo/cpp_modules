#include "WrongCat.hpp"

void WrongCat::makeSound() const
{
	std::cout << "Meoooooooooooooooooow" << std::endl;
}

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor." << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << type << " is being destroyed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	type = other.type;
	std::cout << "WrongCat copy assignement operator." << std::endl;
	return *this;
}
