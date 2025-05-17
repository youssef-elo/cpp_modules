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
		Point(const Point& other);
		Point(const float x_arg, const float y_arg);
		const Fixed getx() const;
		const Fixed gety() const;
		Point& operator=(const Point& other);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif