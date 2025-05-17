#include "Point.hpp"

int main()
{
	if (bsp(Point(4, 0), Point(2, 4),Point(0, 0),  Point(0.1, 0.1)))
		std::cout << "the point is inside the triangle" << std::endl;
	else
		std::cout << "the point is outside the triangle" << std::endl;
}