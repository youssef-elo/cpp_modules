#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x_arg, const float y_arg) : x(x_arg), y(y_arg) {}

Point::~Point() {}

Point::Point(const Point &other) : x(other.getx()), y(other.gety()) {}

const Fixed Point::getx() const
{
	return x;
}
const Fixed Point::gety() const
{
	return y;
}

Point &Point::operator=(const Point &other)
{
	other.getx();
	return *this;
}
