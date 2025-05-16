#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		~Point();
		Point(const float x_arg, const float y_arg);
		Point(const Point& other);
		Point& operator=(const Point& other);
		const Fixed getx() const;
		const Fixed gety() const;
};



bool bsp( Point const a, Point const b, Point const c, Point const point);



#endif