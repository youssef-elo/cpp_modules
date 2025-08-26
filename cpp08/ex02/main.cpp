#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element is : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of Mutant stack is " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	while ( !s.empty() )
	{
		std::cout << "Removing element : " << s.top() << std::endl;
		s.pop();
	}
	return 0;
}
