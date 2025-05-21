#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
	private:
		std::string ideas[100];
		int number_of_thoughts;
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		void set_idea(std::string thought);
		void get_idea(int index);

};

Brain::Brain()
{
	number_of_thoughts = 0;
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
	this->number_of_thoughts = other.number_of_thoughts;
}

#endif