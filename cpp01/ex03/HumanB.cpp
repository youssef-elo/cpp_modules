#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	weapon_ = NULL;
	name_ = name;
}
void HumanB::attack( void )
{
	std::cout << name_ << " attacks with their " 
		<< ((weapon_ != NULL) ? weapon_->getType() : "Bare hands") 
		<< std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	weapon_ = &weapon;
}
