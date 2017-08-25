#include <iostream>

using namespace std;

class SquarePyramid;

class Cylinder
{
private:
	double radius,
			height;

public:
	Cylinder(double, double);
	
	//Getters
	double getRaduis() const;
	double getHeight() const;

	bool IsHigher(const SquarePyramid&) const;
};

Cylinder::Cylinder(double r, double h)
{
	radius = r;
	height = h;
}

double Cylinder::getRaduis() const
{
	return radius;
}

double Cylinder::getHeight() const
{
	return height;
}

class SquarePyramid
{
private:
	double side,
			height;

public:
	SquarePyramid(double, double);
	
	//Getters
	double getSide() const;
	double getHeight() const;

	friend bool Cylinder::IsHigher(const SquarePyramid&) const;
};

SquarePyramid::SquarePyramid(double s, double h)
{
	side = s;
	height = h;
}

double SquarePyramid::getSide() const
{
	return side;
}

double SquarePyramid::getHeight() const
{
	return height;
}

bool Cylinder::IsHigher(const SquarePyramid& SP) const
{
	return height > SP.height;
}

int main()
{
	Cylinder c(12.5, 8.0);
	SquarePyramid s(5.2, 10.5);

	if (c.IsHigher(s))
	{
		cout << "Cylinder is higher than the square pyramid!\n";
	}

	else cout << "Cylinder is not higher than the square pyramid!\n";

	return 0;
}