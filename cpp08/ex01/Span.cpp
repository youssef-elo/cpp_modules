#include "Span.hpp"

int Span::longestSpan()
{
	if ( container.size() < 2)
		throw std::runtime_error("Span doesnt have enough elements to calculate longest span");
	
	Span::iterator first = container.begin();
	Span::iterator last = container.end();
	last--;
	return *last - *first;
}
int Span::shortestSpan()
{
	if ( container.size() < 2)
		throw std::runtime_error("Span doesnt have enough elements to calculate shortest span");
	
	Span::iterator it = container.begin();
	int prev = *it;
	int current = 0;
	int ret = *(++it) - prev;
	while ( it != container.end())
	{
		current = *it - prev;
		if ( ret > current)
			ret = current;
		prev = *it;
		++it;
	}
	return ret;
}

void Span::addNumber(int nb)
{
	if ( container.size() == span_size)
		throw std::runtime_error("Span is full cannot insert element.");
	container.insert(nb);
}

Span::Span(){}

Span::Span( unsigned int size ): span_size(size) {}

Span::Span( const Span& other ) : span_size(other.span_size) , container(other.container){}

Span& Span::operator=( const Span& other )
{
	if ( this == &other)
		return *this;
	container = other.container;
	span_size = other.span_size;
	return *this;
}

Span::~Span()
{
	std::cout << "Destroying Span object" << std::endl;
}