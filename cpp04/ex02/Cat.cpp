#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Meoooooooooooooooooow" << std::endl;
}

Cat::Cat()
{
	std::cout << "Cat default constructor." << std::endl;
	type = "Cat";
	cat_brain = new Brain;
}
Cat::~Cat()
{
	delete cat_brain;
	std::cout << type << " is being destroyed." << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor." << std::endl;
	cat_brain = new Brain;
	*(cat_brain) = *(other.cat_brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement operator." << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	*(cat_brain) = *(other.cat_brain);
	return *this;
}

const std::string& Cat::get_idea(int index) const
{
	return cat_brain->get_idea(index);
}

void Cat::set_idea(std::string thought)
{
	cat_brain->set_idea(thought);
}
