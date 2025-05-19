#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
};

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor." << std::endl;
}

Animal::Animal(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy constructor." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy assignement constructor." << std::endl;
	return *this;
}

#endif