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

        bool operator<(const Fixed& left);
        bool operator<=(const Fixed& left);

        bool operator>(const Fixed& left);
        bool operator>=(const Fixed& left);
        
        bool operator!=(const Fixed& left);
        bool operator==(const Fixed& left);
};




#endif