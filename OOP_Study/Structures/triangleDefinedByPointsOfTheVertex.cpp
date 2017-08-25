#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
	double x;
	double y;
};

void create_point(Point& p)
{
	cout << "X coordinate: "; cin >> p.x;
	cout << "Y coordinate: "; cin >> p.y;
}

void print_point(const Point& p)
{
	cout << "Point (" << p.x << "," << p.y << ")\n";
}

double segment(const Point& p1, const Point& p2)
{
	return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

struct Triangle
{
	Point A, B, C;
};

void create_triangle(Triangle& t)
{
	create_point(t.A);
	create_point(t.B);
	create_point(t.C);
}

void print_triangle(Triangle& t)
{
	cout << "Triangle (";
	print_point(t.A);
	cout << ", ";
	print_point(t.B);
	cout << ", ";
	print_point(t.C);
	cout <<")\n";
}

double perimeter(const Triangle& t)
{
	return (segment(t.A, t.B) + segment(t.A, t.C) + segment(t.B, t.C));
}

double surface(const Triangle& t)
{
	double p = perimeter(t);
	return sqrt(p*(p-segment(t.A, t.B))*(p-segment(t.A, t.C))*(p-segment(t.B, t.C)));
}

int main()
{
	Triangle t;
	create_triangle(t);

	print_triangle(t);

	cout << "Perimeter: " << perimeter(t) << endl;
	cout << "Surface: " << surface(t) << endl;

	return 0;
}