#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	type = "AAnimal";
	std::cout << "AAnimal constructor." << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	type = other.type;
	std::cout << "AAnimal copy constructor." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	type = other.type;
	std::cout << "AAnimal copy assignement constructor." << std::endl;
	return *this;
}

const std::string& AAnimal::getType() const
{
	return type;
}
