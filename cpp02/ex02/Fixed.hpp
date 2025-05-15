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
		Fixed(const Fixed& other);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

        bool operator<(const Fixed& right);
        bool operator<=(const Fixed& right);

        bool operator>(const Fixed& right);
        bool operator>=(const Fixed& right);
        
        bool operator!=(const Fixed& right);
        bool operator==(const Fixed& right);

		Fixed operator+(const Fixed& right);
		Fixed operator-(const Fixed& right);

		Fixed operator*(const Fixed& right);
		Fixed operator/(const Fixed& right);

		Fixed& operator--();
		Fixed& operator++();
		Fixed operator--(int);
		Fixed operator++(int);

		static Fixed& min(Fixed& first, Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);

		static const Fixed& min(const Fixed& first, const Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
};




std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif