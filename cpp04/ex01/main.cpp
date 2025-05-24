#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void fill_dog_brain(Dog &dog, std::string str)
{
	for (int i = 0; i < 100; i++)
		dog.set_idea(str);
}
void fill_cat_brain(Cat &cat, std::string str)
{
	for (int i = 0; i < 100; i++)
		cat.set_idea(str);
}

int main()
{
	const Animal *first_dog = new Dog();
	const Animal *first_cat = new Cat();
	delete first_dog; // should not create a leak
	delete first_cat;

	Animal *arr[6];

	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new Dog;
		fill_dog_brain(*((Dog *)arr[i]), "Haw Haw");
	}
	std::cout << std::endl;
	for (int i = 3; i < 6; i++)
	{
		arr[i] = new Cat;
		fill_cat_brain(*((Cat *)(arr[i])), "Meow Meow");
	}
	std::cout << std::endl;

	for(int i = 0; i < 3; i++)
		std::cout << ((Dog *)(*arr))->get_idea(i) << std::endl;
	std::cout << std::endl;

	for(int i = 0; i < 3; i++)
		std::cout << ((Cat *)(*(arr + 3)))->get_idea(i) << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete (arr[i]);
	std::cout << std::endl;

	Dog rex;
	Dog rex2;

	std::cout << std::endl;
	fill_dog_brain(rex, "Haw Haw");
	for(int i = 0; i < 3; i++)
		std::cout << rex.get_idea(i) << std::endl;
	fill_dog_brain(rex2, "Woof Woof");
	std::cout << std::endl;
	rex = rex2;
	std::cout << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << rex.get_idea(i) << std::endl;
	std::cout << std::endl;
	return 0;
}
