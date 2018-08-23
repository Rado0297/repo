#include <iostream>

#include "point3.hpp"

Point3::Point3(int _x, int _y, int _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Point3::Point3(const Point3& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

int Point3::getX() const
{
	return x;
}

int Point3::getY() const
{
	return y;
}

int Point3::getZ() const
{
	return z;
}

void Point3::setX(int _x)
{
	x = _x;
}

void Point3::setY(int _y)
{
	y = _y;
}

void Point3::setZ(int _z)
{
	z = _z;
}

void Point3::print() const
{
	std::cout << x << " " << y << " " << z << std::endl;
}