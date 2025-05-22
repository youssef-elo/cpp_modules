#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Meoooooooooooooooooow" << std::endl;
}

Cat::Cat()
{
	type = "Cat";
	cat_brain = new Brain;
	std::cout << "Cat default constructor." << std::endl;
}
Cat::~Cat()
{
	delete cat_brain;
	std::cout << type << " is being destroyed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	cat_brain = new Brain;
	cat_brain = other.cat_brain;
	std::cout << "Cat copy constructor." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	type = other.type;
	cat_brain = other.cat_brain;
	std::cout << "Cat copy assignement operator." << std::endl;
	return *this;
}

const std::string& Cat::get_idea(int index) const
{
	cat_brain->get_idea(index);
}

void Cat::set_idea(std::string thought)
{
	cat_brain->set_idea(thought);
}
