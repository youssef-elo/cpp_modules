#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
};

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor." << std::endl;
}
Cat::~Cat()
{
	std::cout << type << "is being destroyed." << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement operator." << std::endl;
}

#endif