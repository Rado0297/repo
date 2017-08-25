#include <iostream>
#include <math.h>

using namespace std;

const double PI = 3.14159265;

struct Polar
{
	double radius;
	double angle;
};

struct Rect
{
	double x;
	double y;
};

//rect to polar coordinates
//x = r*cos(angle)
//y = r*sin(angle)
Polar rect_to_polar(const Rect& r)
{
	Polar p;
	p.radius = sqrt(r.x * r.x + r.y * r.y);
	p.angle = atan2(r.y, r.x);
	return p;
}

Rect polar_to_rect(const Polar& p)
{
	const double deg_to_rad = PI/180;
	Rect r;
	r.x = p.radius * cos(p.angle*deg_to_rad);
	r.y = p.radius * sin(p.angle*deg_to_rad);
	return r;
}

void print_vector_rect_coordinates(Rect r)
{
	cout << "Rect coordinates: (" << r.x << ", " << r.y << ")\n";
}

void print_vector_polar_coordinates(Polar p)
{
	cout << "Polar coordinates: (" << p.radius << ", " << p.angle << ")\n";
}

int main()
{
	Rect rcoords;
	Polar pcoords;

	char type[1];
	cin >> type;

	switch(type)
	{
		case 'r': while(cin >> rcoords.x >> rcoords.y)
		{
			pcoords = rect_to_polar(rcoords);
			print_vector_polar_coordinates(rcoords);
		} break;

		case 'p': while(cin >> pcoords.x >> pcoords.y)
		{
			rcoords = polar_to_rect(pcoords);
			print_vector_rect_coordinates(pcoords);
		} break;
	}

	return 0;
}