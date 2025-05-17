#include "Point.hpp"


// formula (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed zero(0);
	Fixed margin(0);
	margin++;
	Fixed two(2);
	Fixed total_surface;
	Fixed triangle_surface;
	Fixed surface1, surface2, surface3; // 1 apc, 2 abp, 3 pbc 
	Fixed xa(a.getx()), ya(a.gety());
	Fixed xb(b.getx()), yb(b.gety());
	Fixed xc(c.getx()), yc(c.gety());
	Fixed xp(point.getx()), yp(point.gety());

	triangle_surface = ((xa * (yb - yc)) + (xb * (yc - ya)) + (xc * (ya - yb))) / two;
	surface1 = ((xa * (yp - yc)) + (xp * (yc - ya)) + (xc * (ya - yp))) / two;
	surface2 = ((xa * (yb - yp)) + (xb * (yp - ya)) + (xp * (ya - yb))) / two;
	surface3 = ((xp * (yb - yc)) + (xb * (yc - yp)) + (xc * (yp - yb))) / two;

	if (triangle_surface < zero)
		triangle_surface = triangle_surface * Fixed(-1);
	if(surface1 < zero)
		surface1 = surface1 * Fixed(-1);
	if(surface2 < zero)
		surface2 = surface2 * Fixed(-1);
	if(surface3 < zero)
		surface3 = surface3 * Fixed(-1);
	total_surface = surface1 + surface2 + surface3;
	if (surface1 > zero && surface2 > zero && surface3 > zero && total_surface <= triangle_surface + margin)
		return true;
	return false;
}