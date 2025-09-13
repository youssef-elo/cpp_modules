#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template < typename T >
typename T::iterator easyfind(T& con, int to_find)
{
	typename T::iterator it = std::find( con.begin(), con.end(), to_find);
	if ( it == con.end())
		throw std::runtime_error("Element requested cannot be found.");
	return it;
}

#endif