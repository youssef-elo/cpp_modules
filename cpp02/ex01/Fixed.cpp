#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	num = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->num = other.getRawBits();
}

int Fixed::getRawBits( void ) const
{
	return num;
}
void Fixed::setRawBits(int const raw)
{
	num = raw;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	num = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	num = roundf((float)integer * (1 << bits));	
}
Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called" << std::endl;
	num = roundf(floating * (1 << bits));	
}

float Fixed::toFloat( void ) const
{
	return num / (float)(1 << bits);
}

int Fixed::toInt( void ) const
{
	return num / (float)(1 << bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}