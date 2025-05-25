#include "AMateria.hpp"

AMateria::~AMateria(){
	std::cout << "destroying material " << type << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

AMateria::AMateria(std::string const &type) {
	this->type = type;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "shoots at" << target.getName() << std::endl;
}