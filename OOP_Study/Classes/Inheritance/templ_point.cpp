#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

template<class T>
class Point3
{
private:
	T x;
	T y;
	T z;

public:
	Point3(T = 0, T = 0, T = 0);
	Point3(const Point3&);
	Point3& operator=(const Point3&);

	T getX() const;
	T getY() const;
	T getZ() const;

	void print() const;

	void setX(T);
	void setY(T);
	void setZ(T);
};

template<class T>
Point3<T>::Point3(T _x, T _y, T _z)
{
	x = _x;
	y = _y;
	z = _z;
}

template<class T>
Point3<T>::Point3(const Point3& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

template<class T>
Point3<T>& Point3<T>::operator=(const Point3& p)
{
	if (this != &p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
	}

	return *this;
}

template<class T>
T Point3<T>::getX() const
{
	return x;
}

template<class T>
T Point3<T>::getY() const
{
	return y;
}

template<class T>
T Point3<T>::getZ() const
{
	return z;
}

template<class T>
void Point3<T>::print() const
{
	cout << "Point3(" << x << ", " << y << ", " << z << ")\n";
}

template<class T>
void Point3<T>::setX(T _x)
{
	x = _x;
}

template<class T>
void Point3<T>::setY(T _y)
{
	y = _y;
}

template<class T>
void Point3<T>::setZ(T _z)
{
	z = _z;
}

template<class T, class U>
class ColPoint3 : public Point3<T>
{
private:
	U col;

public:
	ColPoint3(T = 0, T = 0, T = 0, U = 0);
	ColPoint3(const ColPoint3&);
	ColPoint3& operator=(const ColPoint3&);

	U getCol() const;
	void setCol(U);

	void print() const;
};

template<class T, class U>
ColPoint3<T, U>::ColPoint3(T _x, T _y, T _z, U c) : Point3<T>(_x, _y, _z)
{
	col = c;
}

template<class T, class U>
ColPoint3<T, U>::ColPoint3(const ColPoint3& p) : Point3<T>(p)
{
	col = p.col;
}

template<class T, class U>
ColPoint3<T, U>& ColPoint3<T, U>::operator=(const ColPoint3& p)
{
	if (this != &p)
	{
		Point3<T>::operator=(p);
		col = p.col;
	}

	return *this;
}

template<class T, class U>
U ColPoint3<T, U>::getCol() const
{
	return col;
}

template<class T, class U>
void ColPoint3<T, U>::setCol(U c)
{
	col = c;
}

template<class T, class U>
void ColPoint3<T, U>::print() const
{
	Point3<T>::print();
	cout << "Color: " << col << endl;
}

template<class T, class U, class V>
class WeightColPoint3 : public ColPoint3<T, U>
{
private:
	V weight;

public:
	WeightColPoint3(T = 0, T = 0, T = 0, U = 0, V = 0);
	WeightColPoint3(const WeightColPoint3&);
	WeightColPoint3& operator=(const WeightColPoint3&);

	V getWeight() const;
	void setWeight(V);

	void print();
};

template<class T, class U, class V>
WeightColPoint3<T, U, V>::WeightColPoint3(T _x, T _y, T _z, U c, V w) : ColPoint3<T, U>(_x, _y, _z, c)
{
	weight = w;
}
	
template<class T, class U, class V>
WeightColPoint3<T, U, V>::WeightColPoint3(const WeightColPoint3& p) : ColPoint3<T, U>(p)
{
	weight = p.weight;
}

template<class T, class U, class V>
WeightColPoint3<T, U, V>& WeightColPoint3<T, U, V>::operator=(const WeightColPoint3& p)
{
	if (this != &p)
	{
		ColPoint3<T, U>::operator=(p);
		weight = p.weight;
	}

	return *this;
}

template<class T, class U, class V>
V WeightColPoint3<T, U, V>::getWeight() const
{
	return weight;
}

template<class T, class U, class V>
void WeightColPoint3<T, U, V>::setWeight(V w)
{
	weight = w;
}

template<class T, class U, class V>
void WeightColPoint3<T, U, V>::print()
{
	ColPoint3<T, U>::print();
	cout << "Weight: " << weight << endl;
}

int main()
{
	//a)
	/*
	WeightColPoint3<double, double, double> Points[MAX_SIZE];

	int n, i;

	do
	{
		cout << "n= ";
		cin >> n;
	} while(n < 1 || n > MAX_SIZE);

	cout << "Enter " << n << " points with color and different weghts!\n";

	for (i = 0; i < n; ++i)
	{
		double x, y, z, c, w;
		cout << "(x, y, z, c, w) = ";
		cin >> x >> y >> z >> c >> w;
		Points[i].setX(x);
		Points[i].setY(y);
		Points[i].setZ(z);
		Points[i].setCol(c);
		Points[i].setWeight(w);
	}

	double a, b, c, d;
	cout << "ax + by + cz = d\n";
	cout << "Enter (a, b, c, d): ";
	cin >> a >> b >> c >> d;

	double MaxWeight = 0.0;
	WeightColPoint3<double, double, double> MaxWeightPoint;
	int count = 0;

	for (i = 0; i < n; ++i)
	{
		if (Points[i].getCol() >= 1 && Points[i].getCol() <= 5 && a*Points[i].getX() + b*Points[i].getY() + c*Points[i].getZ() == d && Points[i].getWeight() > MaxWeight)
		{
			MaxWeight = Points[i].getWeight();
			MaxWeightPoint = Points[i];
			count++;
		}
	}

	if (count == 0)
	{
		cout << "Point with given properties was not found!\n";
	}
	else
		MaxWeightPoint.print();
	*/

	//b)
	WeightColPoint3<double, double, double> Points[MAX_SIZE];
	int n, i;

	do
	{
		cout << "n = ";
		cin >> n;
	} while(n < 1 || n > MAX_SIZE);

	cout << "Enter " << n << " points with color and different weights!\n";

	for (i = 0; i < n; ++i)
	{
		double x, y, z, c, w;
		cout << "Enter (x, y, z, c, w): ";
		cin >> x >> y >> z >> c >> w;
		Points[i].setX(x);
		Points[i].setY(y);
		Points[i].setZ(z);
		Points[i].setCol(c);
		Points[i].setWeight(w);
	}

	double R;
	cout << "R = ";
	cin >> R;

	int m = -1;
	WeightColPoint3<double, double, double> NewPoints[MAX_SIZE];
	for (i = 0; i < n; ++i)
	{
		double x = Points[i].getX(),
				y = Points[i].getY(),
				z = Points[i].getZ(),
				c = Points[i].getCol();

		if (c >= 1 && c <= 10 && x*x + y*y + z*z <= R*R)
		{
			m++;
			NewPoints[m] = Points[i];
		}
	}

	if (m >= 0)
	{
		m++;
		for (i = 0; i < m - 1; ++i)
		{
			WeightColPoint3<double, double, double> TempPoint;
			double MaxWeight = NewPoints[i].getWeight();
			int k = i;
			for (int j = i+1; j < m; ++j)
			{
				if (NewPoints[j].getWeight() > MaxWeight)
				{
					MaxWeight = NewPoints[j].getWeight();
					k = j;
				}
			}

			TempPoint = NewPoints[i];
			NewPoints[i] = NewPoints[k];
			NewPoints[k] = TempPoint;
		}

		for (i = 0; i < m; ++i)
		{
			NewPoints[i].print();
			cout << endl;
		}
	}

	else
	{
		cout << "Points with this properties do not exist!\n";
	}

	return 0;
}