#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *dog_brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual void makeSound() const;
		void set_idea(std::string thought);
		const std::string& get_idea(int index) const;
};


#endif