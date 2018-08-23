#include <iostream>

#include "point3.hpp"

using namespace std;

void enteArrValues(Point3 array[], int countOfElments)
{
	for (int i = 0; i < countOfElments; ++i)
	{
		int _x, _y, _z;
		cout << "Enter x:";
		cin >> _x;

		cout << "Enter y:";
		cin >> _y;

		cout << "Enter z:";
		cin >> _z;

		array[i].setX(_x);
		array[i].setY(_y);
		array[i].setZ(_z);
	}
}

void simetricCoords(Point3 array[], int countOfElments)
{
	for (int i = 0; i < countOfElments; ++i)
	{
		int _x = array[i].getX();
		int _y = array[i].getY();
		int _z = array[i].getZ();

		array[i].setX(_x*(-1));
		array[i].setY(_y*(-1));
		array[i].setZ(_z*(-1));
	}
}

void out(Point3 array[], int countOfElments)
{
	for (int i = 0; i < countOfElments; ++i)
	{
		array[i].print();
	}
}

void sortPoints(Point3 array[], int countOfElments)
{
	for (int i = 0; i < countOfElments; ++i)
	{
		for (int j = 0; j < countOfElments; ++j)
		{
			if (array[i].getX() < array[j].getX())
			{
				swap(array[j], array[i]);
			}

			else if (array[i].getX() == array[j].getX())
			{
				if (array[i].getY() < array[j].getY())
				{
					swap(array[j], array[i]);
				}

				else if (array[i].getY() == array[j].getY())
				{
					if (array[i].getZ() < array[j].getZ())
					{
						swap(array[j], array[i]);
					}	
				}
			}
		}
	}
}

int main()
{
	Point3 p(1,2,3);
	cout << p.getX() << endl;

	Point3 array[10];
	enteArrValues(array, 10);

	simetricCoords(array, 10);

	out(array, 10);

	return 0;
}