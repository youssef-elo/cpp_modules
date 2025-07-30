#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

Base * generate(void)
{
	srand(time(0));
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2: 
			return new C;
	}
	return new C;
}

void identify(Base* p)
{
	A *aptr;
	B *bptr;
	C *cptr;

	aptr = dynamic_cast<A *>(p);
	bptr = dynamic_cast<B *>(p);
	cptr = dynamic_cast<C *>(p);
	if ( aptr)
		std::cout << "A" << std::endl;
	else if ( bptr)
		std::cout << "B" << std::endl;
	else if ( cptr)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& aref = dynamic_cast<A&>(p);
		(void)aref;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		B& aref = dynamic_cast<B&>(p);
		(void)aref;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		C& aref = dynamic_cast<C&>(p);
		(void)aref;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}