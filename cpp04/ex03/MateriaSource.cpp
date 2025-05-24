#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for ( int i  = 0; i < 4; i++)
		materials[i] = NULL;
	index = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for ( int i = 0; i < 4; i++)
	{
		if ( other.materials[i])
		{
			materials[i] = other.materials[i]->clone();
		}
		types[i] = other.types[i];
	}
	index = other.index;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if ( this == &other )
		return *this;
	for ( int i = 0; i < 4; i++ )
	{
		if ( materials[i] )
			delete materials[i];
		if ( other.materials[i] )
			materials[i] = other.materials[i]->clone();
		else 
			materials[i] = NULL;
		types[i] = other.types[i];
	}
	index = other.index;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for ( int i =0 ; i < 4; i++)
	{
		if (materials[i])
			delete materials[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if ( materials[index] )
		delete materials[index];
	materials[index] = m->clone();
	types[index] = m->getType();
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for ( int i =0; i < 4; i++)
	{
		if (types[i] == type)
			return materials[i]->clone();
	}
	return 0;
}