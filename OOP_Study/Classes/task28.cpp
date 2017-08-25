#include <iostream>
#include <cmath>

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

double Distance(const Point3& p)
{
	return sqrt((double)(p.getX()*p.getX() + p.getY()*p.getY() + p.getZ()*p.getZ()));
}

int main()
{
	Point3 ** array = new Point3*[10];

	if (!array)
	{
		cout << "Error occured!\n";
		return 1;
	}

	int i;
	for (i = 0; i < 10; ++i)
	{
		int x,y,z;
		cout << "array[" << i << "] (x, y, z) = ";
		cin >> x >> y >> z;
		array[i] = new Point3(x, y, z);
		if(!array[i])
		{
			cout << "Error!\n";
			return 1;
		}
	}

	double min = Distance(*array[0]),
			max = Distance(*array[0]);

	for (i = 1; i < 10; ++i)
	{
		double d = Distance(*array[i]);
		if(d < min) min = d;
		if(d > max) max = d;
	}

	cout << "Smallest distance is: " << min << endl;

	for (i = 0; i < 10; ++i)
	{
		if(fabs(Distance(*array[i]) - min) < 1E-14)
		{
			cout << "Point (" << array[i]->getX() << ", "
			<< array[i]->getY() << ", "
			<< array[i]->getZ() << ")\n";
		}
	}

	cout << "Biggest distance is: " << max << endl;

	for (i = 0; i < 10; ++i)
	{
		if(fabs(Distance(*array[i]) - max) < 1E-14)
		{
			cout << "Point (" << array[i]->getX() << ", "
			<< array[i]->getY() << ", "
			<< array[i]->getZ() << ")\n";
		}
	}

	for (i = 0; i < 10; ++i)
	{
		delete array[i];
	}

	delete [] array;

	return 0;
}