#include "Character.hpp"

garbage* Character::head = NULL;

void Character::keep_add(AMateria *keep)
{
	garbage *tmp;

	if ( head == NULL)
	{
		head = new garbage;
		head->add = keep;
		head->next = NULL;
	}
	else
	{
		tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new garbage;
		tmp = tmp->next;
		tmp->add = keep;
		tmp->next = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if( items[idx] )
	{
		items[idx]->use(target);
	}
}

void Character::equip(AMateria *m)
{
	for ( int i = 0; i < 4; i++)
	{
		if (items[i] == NULL)
		{
			std::cout << i << std::endl;
			items[i] = m->clone();
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (items[idx] != NULL)
	{
		keep_add(items[idx]);
		items[idx] = NULL;
	}
}


Character::Character()
{
	name = "default";
	head = NULL;
	for ( int i  = 0; i < 4;i++)
		items[i] = NULL;
}

Character::Character(std::string name_arg)
{
	name = name_arg;
	for ( int i = 0; i < 4; i++)
		items[i] = NULL;
}

Character::~Character()
{
	garbage *tmp;
	for ( int i = 0; i < 4; i++)
	{
		if (items[i])
			delete items[i];
	}
	while(head)
	{
		tmp = head->next;
		delete head->add;
		delete head;
		head = tmp;
	}
}

Character::Character(const Character &other)
{
	name = other.name;
	for ( int i =0 ; i < 4; i++)
	{
		items[i] = other.items[i] != NULL ? other.items[i]->clone() : NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return *this;
	name = other.name;
	for ( int i =0 ; i < 4; i++)
	{
		items[i] = other.items[i] != NULL ? other.items[i]->clone() : NULL;
	}
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}
