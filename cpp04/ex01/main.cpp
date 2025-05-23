#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void fill_dog_brain(Dog &dog)
{
	for (int i = 0; i < 100; i++)
		dog.set_idea("Haw Haw");
}

void fill_cat_brain(Cat &cat)
{
	for (int i = 0; i < 100; i++)
		cat.set_idea("Haw Haw");
}

int main()
{
	Animal *arr[6];

	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new Dog;
		fill_dog_brain((Dog)(arr[i]));
	}
	std::cout << std::endl;
	for (int i = 3; i < 6; i++)
	{
		arr[i] = new Cat;
		fill_cat_brain(*(Cat *)arr[i]);
	}
	std::cout << std::endl;
	for(int i = 0; i< 100; i++)
		std::cout << ((Dog *)(arr + i))->get_idea(i) << std::endl;
	for (int i = 0; i < 6; i++)
		delete (arr[i]);
	return 0;
}
