#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	Base *ptr  = generate();
	Base& ref = *ptr;
	A a;
	B b;
	C c;

	identify(&a);
	identify(&b);
	identify(&c);

	std::cout << std::endl;

	identify(ptr);
	identify(ref);
	
	delete ptr;
}