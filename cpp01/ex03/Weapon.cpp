#include "Weapon.hpp"

const std::string& Weapon::getType(void){
	return type;
}

void Weapon::setType( std::string arg )
{
	type = arg;
}

Weapon::Weapon(std::string arg)
{
	type = arg;
}

Weapon::Weapon()
{
	type.clear();
}