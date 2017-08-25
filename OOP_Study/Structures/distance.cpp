#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
	double x, y;
};

void create_point(Point& p)
{
	cout << "Enter X: ";
	cin >> p.x;

	cout << "Enter Y: ";
	cin >> p.y;
}

void print_point(const Point& p)
{
	cout << "Point (" << p.x << ", " << p.y << ")\n";
}

double segment(const Point& p1, const Point& p2)
{
	return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

void read_points(int n, Point* p)
{
	for (int i = 0; i < n; ++i)
	{
		create_point(p[i]);
	}
}

void print_points(int n, Point* p)
{
	for (int i = 0; i < n; ++i)
	{
		print_point(p[i]);
		cout << endl;
	}
}

double max_distance(int n, Point* p)
{
	double max = 0;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i + 1; j < n; j++)
		{
			double temp = segment(p[i], p[j]);
			if(temp > max) max = temp;
		}
	}

	return max;
}

int main()
{
	int n;
	do
	{
		cout << "Enter n: ";
		cin >> n;
	} while(n < 2 || n > 100);

	Point p[100];

	read_points(n, p);
	print_points(n, p);
	cout << "Max distance is: " << max_distance(n, p) << endl;

	return 0;
}