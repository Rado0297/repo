#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
	double x, y;

public:
	Point(double, double);

	double xcoord() const;
	double ycoord() const;
};

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

double Point::xcoord() const
{
	return x;
}

double Point::ycoord() const
{
	return y;
}

class Line
{
private:
	Point p1, p2;

public:
	Line(const Point&, const Point&);

	Point point1() const;
	Point point2() const;
	double len() const;
	double slope() const;
	Point intersection(const Line&) const;
};

Line::Line(const Point& pt1, const Point& pt2): p1(pt1), p2(pt2){}

Point Line::point1() const
{
	return p1;
}

Point Line::point2() const
{
	return p2;
}

double Line::len() const
{
	double xdist = p2.xcoord() - p1.xcoord();
	double ydist = p2.ycoord() - p1.ycoord();

	return sqrt(xdist*xdist + ydist*ydist);
}

double Line::slope() const
{
	double xdist = p2.xcoord() - p1.xcoord();
	double ydist = p2.ycoord() - p1.ycoord();

	if(fabs(xdist) < 1E-14)
	{
		cout << "Angle koef is undefined!\n";
		return 0;
	}
	else return ydist/xdist;
}

Point Line::intersection(const Line& l) const
{
	//Convertion of first line in type
	//a1*x + b1*y + c1 = 0
	double a1 = p1.ycoord() - p2.ycoord();
	double b1 = p2.xcoord() - p1.xcoord();
	double c1 = p1.xcoord()*p2.ycoord() - p2.xcoord()*p1.ycoord();

	//Convertion of first line in type
	//a2*x + b2*y + c2 = 0
	double a2 = l.p1.ycoord() - l.p2.ycoord();
	double b2 = l.p2.xcoord() - l.p1.xcoord();
	double c2 = l.p1.xcoord()*p2.ycoord() - l.p2.xcoord()*p1.ycoord();

	if(fabs(a1*b2 - a2*b1) < 1E-14)
	{
		if(fabs(b1*c2 - b2*c1) < 1E-14)
		{
			cout << "Lines match!\n";
			return p1;
		}
		else
		{
			cout << "Lines are towards!\n";
			return p1;
		}
	}
	else
	{
		double x1 = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
		double y1 = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);
		return Point(x1, y1);
	}
}

int main()
{
	Point P1(0, 0);
	Point P2(8, 0);
	Point P3(8, 4);
	Point P4(0, 4);

	Line line1(P1, P3);
	Line line2(P2, P4);

	cout << "Length of diag of rect: " << line1.len() << endl;
	cout << "Angle koef: " << line1.slope() << " " << line2.slope() << endl;

	Point intersect = line1.intersection(line2);
	cout << "coordinates of crosspoint of diags: " << intersect.xcoord() << ", " << intersect.ycoord() << endl;

	return 0;
}