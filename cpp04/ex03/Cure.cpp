#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::~Cure()
{
	std::cout << "Destrcuting Cure class" << std::endl;
}
Cure::Cure(const Cure &other) : AMateria(other.getType()) {}

Cure &Cure::operator=(const Cure &other)
{
	other.getType();
	return *this;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
