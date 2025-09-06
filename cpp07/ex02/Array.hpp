#ifndef Array_HPP
#define Array_HPP

#include <iostream>

template <typename TYPE>
class Array
{
	private:
		TYPE* arr;
		unsigned int array_size;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		TYPE& operator[](unsigned int index);
		const TYPE& operator[](unsigned int index) const;

		unsigned int size() const;
};

template < typename TYPE >
Array<TYPE>::~Array()
{
	std::cout << "Destroying the array" << std::endl;
	delete arr;
}

template < typename TYPE>
Array<TYPE>::Array(unsigned int n)
{
	array_size = n;
	arr = new TYPE[n]();
}

template < typename TYPE>
Array<TYPE>::Array()
{
	array_size = 0;
	arr = new TYPE[0]();
}

template < typename TYPE>
Array<TYPE>::Array(const Array& other)
{
	array_size = other.array_size;

	arr = new TYPE[array_size]();
	for ( unsigned int i = 0; i < array_size; i++)
	{
		arr[i] = other.arr[i];
	}
}


template < typename TYPE>
const TYPE& Array<TYPE>::operator[](unsigned int index) const
{
	if ( index < 0 || index >= array_size)
		throw std::out_of_range("Index requested is out of bounds");
	return arr[index];
}

template < typename TYPE>
TYPE& Array<TYPE>::operator[](unsigned int index) 
{
	if ( index < 0 || index >= array_size)
		throw std::out_of_range("Index requested is out of bounds");
	return arr[index];
}

template < typename TYPE>
Array<TYPE>& Array<TYPE>::operator=(const Array& other)
{
	if ( this == &other)
		return *this;
	delete arr;
	array_size = other.array_size;
	arr = new TYPE[array_size]();
	for (unsigned int i = 0; i < array_size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

template < typename TYPE>
unsigned int Array<TYPE>::size() const
{
	return array_size;
}

#endif