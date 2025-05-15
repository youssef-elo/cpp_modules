#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	num = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->num = other.getRawBits();
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawbits member function called" << std::endl;
	return num;
}
void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawbits member function called" << std::endl;
	num = raw;
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	num = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int integer)
{
	// std::cout << "Int constructor called" << std::endl;
	num = roundf(integer * std::pow(2, bits));	
}
Fixed::Fixed(const float floating)
{
	// std::cout << "Float constructor called" << std::endl;
	num = roundf(floating * std::pow(2, bits));	
}

float Fixed::toFloat( void ) const
{
	return num / pow(2, bits);
}

int Fixed::toInt( void ) const
{
	return num / pow(2, bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}



bool Fixed::operator<(const Fixed& left)
{
    return (this->getRawBits() < left.getRawBits());
}

bool Fixed::operator<=(const Fixed& left)
{
    return (this->getRawBits() <= left.getRawBits());
}


bool Fixed::operator>(const Fixed& left)
{
    return (this->getRawBits() > left.getRawBits());
}

bool Fixed::operator>=(const Fixed& left)
{
    return (this->getRawBits() >= left.getRawBits());
}


bool Fixed::operator==(const Fixed& left)
{
    return (this->getRawBits() == left.getRawBits());
}

bool Fixed::operator!=(const Fixed& left)
{
    return (this->getRawBits() != left.getRawBits());
}



Fixed Fixed::operator+(const Fixed &right)
{
	Fixed tmp(right);

	tmp.setRawBits(this->getRawBits() + tmp.getRawBits());
	return tmp;
}

Fixed Fixed::operator-(const Fixed &right)
{
	Fixed tmp(right);

	tmp.setRawBits(this->getRawBits() - tmp.getRawBits());
	return tmp;
}


Fixed Fixed::operator*(const Fixed &right)
{
	Fixed tmp(right);

	tmp.setRawBits((this->getRawBits() * tmp.getRawBits()) / pow(2, bits));
	return tmp;
}

Fixed Fixed::operator/(const Fixed &right)
{
	Fixed tmp(right);

	tmp.setRawBits((this->getRawBits() / (float)tmp.getRawBits()) * pow(2, bits));
	return tmp;
}


Fixed& Fixed::operator--()
{
	num--;
	return *this;
}
Fixed& Fixed::operator++()
{
	num++;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	num--;
	return tmp;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	num++;
	return tmp;
}



Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	int first_num = first.getRawBits();
	int second_num = second.getRawBits();

	if (first_num < second_num)
		return first;
	return second;
}
Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	int first_num = first.getRawBits();
	int second_num = second.getRawBits();

	if (first_num < second_num)
		return second;
	return first;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	int first_num = first.getRawBits();
	int second_num = second.getRawBits();

	if (first_num < second_num)
		return first;
	return second;
}
const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	int first_num = first.getRawBits();
	int second_num = second.getRawBits();

	if (first_num < second_num)
		return second;
	return first;
}