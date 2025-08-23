#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T >
void increment( T& a)
{
	a++;
}

template < typename T >
void print_element( const T& a)
{
	std::cout << a << std::endl;
}

template < typename TYPE, typename FUNCTION >
void iter(TYPE *arr, size_t size, FUNCTION func)
{
	if (!arr)
		return ;
	for ( size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

#endif