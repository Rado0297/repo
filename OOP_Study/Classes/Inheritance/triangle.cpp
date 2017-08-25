#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Triangle
{
protected:
	double a, b, c;

public:
	void init(double, double, double);
	double perimeter() const;
	double area() const;
	void print() const;

};

void Triangle::init(double x, double y, double z)
{
	if (x > 0 && y > 0 && z > 0 && x + y > z && x + z > y && y + z > x)
	{
		a = x;
		b = y;
		c = z;
	}

	else
	{
		cout << x << ", " << y << ", " << z << " can't be sides of Triangle!\n";
		exit(1);
	}
}

double Triangle::perimeter() const
{
	return a + b + c;
}

double Triangle::area() const
{
	double p = (a + b + c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

void Triangle::print() const
{
	cout << a << ", " << b << ", " << c << endl;
}

class RightTriangle : public Triangle
{
public:
	void init(double, double, double);
	double area() const;
};

void RightTriangle::init(double x, double y, double z)
{
	Triangle::init(x, y, z);
	if (fabs(x*x + y*y - z*z) > 1.0e-14 && fabs(x*x + z*z - y*y) > 1.0e-14 && fabs(y*y + z*z - x*x) > 1.0e-14)
	{
		cout << "Triangle is not RightTriangle!\n";
		exit(1);
	}
}

double RightTriangle::area() const
{
	if (fabs(a*a + b*b - c*c) <= 1e-14)
	{
		return a * b / 2;
	}

	else if (fabs(a*a + c*c - b*b) <= 1e-14)
	{
		return a * c / 2;
	}

	else
	{
		return b * c / 2;
	}
}

class IsoscelesTriangle : public Triangle
{
public:
	void init(double, double, double);
	double area() const;
};

void IsoscelesTriangle::init(double x, double y, double z)
{
	Triangle::init(x, y, z);
	if (fabs(x - y) > 1e-14 && fabs(x - z) > 1e-14 && fabs(z - y) > 1e-14)
	{
		cout << "Triangle is not IsoscelesTriangle!\n";
		exit(1);
	}
}

double IsoscelesTriangle::area() const
{
	if (fabs(a - b) <= 1e-14)
	{
		return sqrt(a*a - c*c/4)*c/2;
	}

	else if (fabs(a - c) <= 1e-14)
	{
		return sqrt(a*a - b*b/4)*b/2;
	}

	else
	{
		return sqrt(b*b - a*a/4)*a/2;
	}
}

int main()
{
	Triangle t1;
	t1.init(2, 3, 4);

	t1.print();

	cout << t1.perimeter() << " " << t1.area() << endl;

	RightTriangle t2;
	t2.init(6, 10, 8);

	t2.print();

	cout << t2.perimeter() << " " << t2.area() << endl;

	IsoscelesTriangle t3;
	t3.init(5, 4, 5);
	t3.print();

	cout << t3.perimeter() << " " << t3.area() << endl;

	return 0;
}