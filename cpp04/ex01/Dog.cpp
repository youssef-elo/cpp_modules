#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Dog::Dog()
{
	dog_brain = new Brain;
	type = "Dog";
	std::cout << "Dog default constructor." << std::endl;
}
Dog::~Dog()
{
	delete dog_brain;
	std::cout << type << " is being destroyed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	dog_brain = new Brain;
	dog_brain->operator=(*(other.dog_brain));
	std::cout << "Dog copy constructor." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	dog_brain->operator=(*(other.dog_brain));
	dog_brain = other.dog_brain;
	type = other.type;
	std::cout << "Dog copy assignement operator." << std::endl;
	return *this;
}

const std::string& Dog::get_idea(int index) const
{
	dog_brain->get_idea(index);
}

void Dog::set_idea(std::string thought)
{
	dog_brain->set_idea(thought);
}