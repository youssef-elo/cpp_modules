#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// std::cout << std::endl;

	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	*((Character*) bob) = *((Character *)me);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << std::endl;
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << std::endl;
	
	delete bob;
	delete me;
	delete src;
	return 0;
}
