#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AAnimal *pure_dog = new Dog;
	AAnimal *pure_cat = new Cat;
	std::cout << std::endl;
	pure_dog->makeSound();
	pure_cat->makeSound();
	std::cout << std::endl;
	delete pure_cat;
	delete pure_dog;
	return 0;
}
