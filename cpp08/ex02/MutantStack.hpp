#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename Type>
class MutantStack : public std::stack<Type>
{
	public:
		typedef typename std::stack< Type >::container_type::iterator iterator;
		virtual ~MutantStack() {}
		MutantStack() : std::stack<Type>() {}
		MutantStack(const MutantStack &other) : std::stack<Type>( other ) {}
		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return *this;
			std::stack<Type>::operator=(other);
			return *this;
		}
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}

};

#endif