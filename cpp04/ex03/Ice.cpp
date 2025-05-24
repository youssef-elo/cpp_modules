#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::~Ice()
{
	std::cout << "Destrcuting Ice class" << std::endl;
}
Ice::Ice(const Ice &other) : AMateria(other.getType()) {}

Ice &Ice::operator=(const Ice &other)
{
	other.getType();
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}