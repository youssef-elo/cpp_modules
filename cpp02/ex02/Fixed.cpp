#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	num = 0;
}

Fixed::Fixed(const Fixed& other)
{
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
Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& other)
{
	num = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int integer)
{
	num = roundf(integer * (float)(1 << bits));	
}
Fixed::Fixed(const float floating)
{
	num = roundf(floating * (1 << bits));	
}

float Fixed::toFloat( void ) const
{
	return num / (float)(1 << bits);
}

int Fixed::toInt( void ) const
{
	return num / (1 << bits);
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

	tmp.setRawBits((this->getRawBits() * tmp.getRawBits()) / (float)(1 << bits));
	return tmp;
}

Fixed Fixed::operator/(const Fixed &right)
{
	Fixed tmp(right);

	tmp.setRawBits((this->getRawBits() / (float)tmp.getRawBits()) * (float)(1 << bits));
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