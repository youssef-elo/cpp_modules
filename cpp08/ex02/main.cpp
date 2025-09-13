#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> copy;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
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
		copy = mstack;
		std::cout << std::endl;
		std::stack<int> s(mstack);
		while (!s.empty())
		{
			std::cout << "Removing element : " << s.top() << std::endl;
			s.pop();
		}
		std::cout << std::endl;
	}

	// using list instead
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "Testing const iterators: "<< std::endl;
		const MutantStack<int> constant_class(copy);
		for ( MutantStack<int>::const_iterator it = constant_class.begin(); it < constant_class.end(); ++it )
		{
			std::cout << *it << std::endl;
		}
	}

	return 0;
}
