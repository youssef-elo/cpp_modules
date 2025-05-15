#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> 
#include <cmath>

class Fixed{
	private:
		int num;
		static const int bits;
	public:
		~Fixed();
		Fixed();
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed& operator=(const Fixed& other);
		Fixed(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif