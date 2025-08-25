#ifndef EASYFIND
#define EASYFIND

#include <algorithm>

template < typename Container >
typename Container::iterator easyfind(Container& con, int to_find)
{
	typename Container::iterator it = std::find( con.begin(), con.end(), to_find);
	if ( it == con.end())
		throw std::runtime_error("Element requested cannot be found.");
	return it;
}

#endif 