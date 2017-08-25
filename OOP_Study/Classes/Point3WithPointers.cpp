#include <iostream>

using namespace std;

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
};

Point3::Point3(int a, int b, int c): x(a), y(b), z(c){}

Point3::Point3(const Point3& point)
{
	x = point.x;
	y = point.y;
	z = point.z;
}

int Point3::getX() const { return x; }
int Point3::getY() const { return y; }
int Point3::getZ() const { return z; }

void Point3::setX(int a) { x = a; }
void Point3::setY(int b) { y = b; }
void Point3::setZ(int c) { z = c; }

void Input(int n, Point3 *a)
{
	for (int i = 0; i < n; ++i)
	{
		int p;
		cout << "x = ";
		cin >> p;
		a[i].setX(p);
		
		cout << "y = ";
		cin >> p;
		a[i].setY(p);
		
		cout << "z = ";
		cin >> p;
		a[i].setZ(p);
	}
}

void Symmetry(int n, Point3 *a)
{
	for (int i = 0; i < n; ++i)
	{
		a[i].setX(-a[i].getX());
		a[i].setY(-a[i].getY());
		a[i].setZ(-a[i].getZ());
	}
}

void Output(int n, Point3 *a)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Point3(" << a[i].getX() << ", " << a[i].getY() << ", " << a[i].getZ() << ")\n";
	}
}

int main()
{
	Point3 P, P1(1,1,1);

	cout << "P(" << P.getX() << ", " << P.getY() << ", " << P.getZ() << ")\n";
	cout << "P1(" << P1.getX() << ", " << P1.getY() << ", " << P1.getZ() << ")\n";

	Point3 P2 = P1;

	cout << "P2(" << P2.getX() << ", " << P2.getY() << ", " << P2.getZ() << ")\n";

	P1.setX(6); P1.setY(1); P1.setZ(10);
	//P2.setX(6); P2.setY(6); P2.setZ(6);

	cout << "P1(" << P1.getX() << ", " << P1.getY() << ", " << P1.getZ() << ")\n";
	cout << "P2(" << P2.getX() << ", " << P2.getY() << ", " << P2.getZ() << ")\n";

	cout << "========================================= Pointers part =========================================\n";

	Point3 a[10];

	Input(3, a);
	Symmetry(3, a);
	Output(3, a);

	return 0;
}