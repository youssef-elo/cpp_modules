#include "Span.hpp"

unsigned long Span::longestSpan()
{
	if ( container.size() < 2)
		throw std::runtime_error("Span doesnt have enough elements to calculate longest span");
	
	Span::iterator first = container.begin();
	Span::iterator last = container.end();
	last--;
	return static_cast<unsigned long>(*last) - *first;
}
unsigned long Span::shortestSpan()
{
	if ( container.size() < 2)
		throw std::runtime_error("Span doesnt have enough elements to calculate shortest span");
	
	Span::iterator it = container.begin();
	unsigned long prev = *it;
	unsigned long current = 0;
	unsigned long ret = *(++it) - prev;
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

Span::~Span(){}

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
