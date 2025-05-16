#include "Point.hpp"

int main()
{
	// if (bsp(Point(0,0), Point(2, 4), Point(4, 0), Point(200, 2)))
	// if (bsp(Point(2,2), Point(6,2), Point(4, 6), Point(0, 0)))
	if (bsp(Point(4, 6), Point(4, 6),Point(4, 6),  Point(0, 0)))
		std::cout << "the point is inside the triangle" << std::endl;
	else
		std::cout << "the point is outside the triangle" << std::endl;
}
