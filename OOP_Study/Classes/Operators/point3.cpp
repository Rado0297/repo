#include <iostream>

using namespace std;

//implemented with member functions
class Point3
{
private:
	int x, y, z;

public:
	Point3(int = 0, int = 0, int = 0);
	Point3(const Point3&);
	
	int getX() const;
	int getY() const;
	int getZ() const;
	
	void setX(int);
	void setY(int);
	void setZ(int);
	
	Point3 operator-() const;
	Point3 operator-(const Point3&) const;

	Point3& operator++();
	Point3 operator++(int);

	Point3& operator--();
	Point3 operator--(int);
};

Point3::Point3(int a, int b, int c)
{
	x = a;
	y = b;
	z = c;
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

void Point3::setX(int a)
{
	x = a;
}

void Point3::setY(int b)
{
	y = b;
}

void Point3::setZ(int c)
{
	z = c;
}

Point3 Point3::operator-() const
{
	Point3 temp;
	temp.x = -x;
	temp.y = -y;
	temp.z = -z;
	return temp;
}

Point3 Point3::operator-(const Point3& p) const
{
	Point3 temp;
	temp.x = x - p.x;
	temp.y = y - p.y;
	temp.z = z - p.z;
	return temp;
}

Point3& Point3::operator++()
{
	++x;
	++y;
	++z;
	return *this;
}

Point3 Point3::operator++(int notused)
{
	Point3 temp(x, y, z);
	x++;
	y++;
	z++;
	return temp;
}

Point3& Point3::operator--()
{
	--x;
	--y;
	--z;
	return *this;
}

Point3 Point3::operator--(int notused)
{
	Point3 temp(x, y, z);
	x--;
	y--;
	z--;
	return temp;
}

/* Using friend functions

//put this into public:
friend Point3 operator-(const Point3&);
friend Point3 operator-(const Point3&, const Point3&);

friend Point3& operator++(Point3&);
friend Point3 operator++(Point3&, int);
friend Point3& operator--(Point3&);
friend Point3 operator--(Point3&, int);

//and this is declaration in global scope:
Point3 operator-(const Point3& p)
{
	Point3 temp;
	temp.x = -p.x;
	temp.y = -p.y;
	temp.z = -p.z;
	return temp;
}

Point3 operator-(const Point3& p1, const Point3& p2)
{
	Point3 temp;
	temp.x = p1.x - p2.x;
	temp.y = p1.y - p2.y;
	temp.z = p1.z - p2.z;
}

Point3& operator++(Point3& p)
{
	++p.x;
	++p.y;
	++p.z;
	return p;
}

Point3 operator++(Point3& p, int notused)
{
	Point3 temp(p);
	p.x++;
	p.y++;
	p.z++;
	return temp;
}

Point3& Point3::operator--(Point3& p)
{
	--p.x;
	--p.y;
	--p.z;
	return p;
}

Point3 Point3::operator--(Point3& p, int notused)
{
	Point3 temp(p);
	p.x--;
	p.y--;
	p.z--;
	return temp;
}

*/

int main()
{
	Point3 P(1, 2, -4);

	cout << "P = (" << P.getX() << ", " << P.getY() << ", " << P.getZ() << ")\n";

	Point3 P1 = P;
	P1 = -P1;

	cout << "P1 = (" << P1.getX() << ", " << P1.getY() << ", " << P1.getZ() << ")\n";

	P = P - P1;

	cout << "P = (" << P.getX() << ", " << P.getY() << ", " << P.getZ() << ")\n";

	P++;

	cout << "P = (" << P.getX() << ", " << P.getY() << ", " << P.getZ() << ")\n";


	return 0;
}