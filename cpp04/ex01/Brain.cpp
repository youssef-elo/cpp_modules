#include "Brain.hpp"
#include "Cat.hpp"

Brain::Brain()
{
	index_of_thoughts = 0;
	std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destroying the brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0 ; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	this->index_of_thoughts = other.index_of_thoughts;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return *this;
	for (int i = 0 ; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	index_of_thoughts = other.index_of_thoughts;
}

void Brain::set_idea(std::string thought)
{
	ideas[index_of_thoughts] = thought;
	index_of_thoughts = (index_of_thoughts + 1) % 100;
}


const std::string &Brain::get_idea(int index) const
{
	return ideas[index];
}
