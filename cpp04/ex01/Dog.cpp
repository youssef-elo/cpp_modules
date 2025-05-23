#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Dog::Dog()
{
	std::cout << "Dog default constructor." << std::endl;
	dog_brain = new Brain;
	type = "Dog";
}
Dog::~Dog()
{
	delete dog_brain;
	std::cout << type << " is being destroyed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor." << std::endl;
	dog_brain = new Brain;
	*(dog_brain) = *(other.dog_brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignement operator." << std::endl;
	if (this == &other)
		return *this;
	*dog_brain = *(other.dog_brain);
	type = other.type;
	return *this;
}

const std::string& Dog::get_idea(int index) const
{
	 return dog_brain->get_idea(index);
}

void Dog::set_idea(std::string thought)
{
	dog_brain->set_idea(thought);
}