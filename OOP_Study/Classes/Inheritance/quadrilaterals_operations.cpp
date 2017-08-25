#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Point
{
private:
	double x, y;

public:
	Point(double, double);
	void scale(double);
	void translate(double, double);
	double distance(const Point&) const;
	void print() const;
};

Point::Point(double _x, double _y)
{
	x = _x;
	y = _y;
}

void Point::scale(double num)
{
	x *= num;
	y *= num;
}

void Point::translate(double _x, double _y)
{
	x += _x;
	y += _y;
}

double Point::distance(const Point& p1) const
{
	double xdist = x - p1.x;
	double ydist = y - p1.y;

	return sqrt(xdist*xdist + ydist*ydist);
}

void Point::print() const
{
	cout << "(" << x << ", " << y << ")\n";
}

class Quadrilateral
{
private:
	double triangleArea(Point, Point, Point) const;

protected:
	Point p1, p2, p3, p4;

public:
	Quadrilateral(Point, Point, Point, Point);
	void scale(double);
	void translate(double, double);
	double perimeter() const;
	double area() const;
	void print() const;
};

double Quadrilateral::triangleArea(Point pp1, Point pp2, Point pp3) const
{
	double a = pp1.distance(pp2);
	double b = pp2.distance(pp3);
	double c = pp3.distance(pp1);
	double pp = (a + b + c)/2;

	return sqrt(pp*(pp-a)*(pp-b)*(pp-c));
}

Quadrilateral::Quadrilateral(Point pp1, Point pp2, Point pp3, Point pp4)
	: p1(pp1), p2(pp2), p3(pp3), p4(pp4)
{}

void Quadrilateral::scale(double num)
{
	p1.scale(num);
	p2.scale(num);
	p3.scale(num);
	p4.scale(num);
}

void Quadrilateral::translate(double _x, double _y)
{
	p1.translate(_x, _y);
	p2.translate(_x, _y);
	p3.translate(_x, _y);
	p4.translate(_x, _y);
}

double Quadrilateral::perimeter() const
{
	return p1.distance(p2) + p2.distance(p3) + p3.distance(p4) + p4.distance(p1);
}

double Quadrilateral::area() const
{
	return triangleArea(p1, p2, p3) + triangleArea(p1, p3, p4);
}

void Quadrilateral::print() const
{
	cout << "Quadrilateral with poitns:\n";
	p1.print();
	p2.print();
	p3.print();
	p4.print();
}

class Rectangle : public Quadrilateral
{
private:
	double diag;

public:
	Rectangle(Point, Point, Point, Point);
	double perimeter() const;
	double area() const;
	double diagonal() const;
	void print() const;
	void print_diag() const;
};

Rectangle::Rectangle(Point q1, Point q2, Point q3, Point q4)
	: Quadrilateral(q1, q2, q3, q4)
{
	if (fabs(p1.distance(p3) - p2.distance(p4)) > 1.0e-14 || fabs(p1.distance(p2) - p3.distance(p4)) > 1.0e-14 || fabs(p1.distance(p4) - p2.distance(p3)) > 1.0e-14)
	{
		cout << "This is not a rectagle!\n";
		exit(1);
	}

	diag = p1.distance(p3);
}

double Rectangle::perimeter() const
{
	return p1.distance(p2) * 2 + p1.distance(p4) * 2;
}

double Rectangle::area() const
{
	return p1.distance(p2) * p1.distance(p4);
}

double Rectangle::diagonal() const
{
	return diag;
}

void Rectangle::print() const
{
	cout << "Rectangle with points:\n";
	p1.print();
	p2.print();
	p3.print();
	p4.print();
}

void Rectangle::print_diag() const
{
	cout << "Rectangle diagonal is: " << diag << endl;
}

class Square : public Rectangle
{
public:
	Square(Point, Point, Point, Point);
	double perimeter() const;
	double area() const;
	void print() const;
};

Square::Square(Point q1, Point q2, Point q3, Point q4)
	: Rectangle(q1, q2, q3, q4)
{
	if (fabs(p1.distance(p2) - p2.distance(p3)) > 1.0e-7)
	{
		cout << "This is not a square!\n";
		exit(1);
	}
}

double Square::perimeter() const
{
	return 4 * p1.distance(p2);
}

double Square::area() const
{
	return p1.distance(p2) * p1.distance(p2);
}

void Square::print() const
{
	cout << "Square with points:\n";
	p1.print();
	p2.print();
	p3.print();
	p4.print();
}

int main()
{
	Point P1(0, 0), P2(3, 1), P3(3, 0),
			P4(0, 1), P5(1, 1), P6(0, 3), P7(3, 3);

	Quadrilateral q(P1, P2, P3, P4);
	q.print();

	cout << "Perimeter: " << q.perimeter() << endl
		<< "Area: " << q.area() << endl;

	q.translate(2, 5);
	q.print();

	cout << "Perimeter: " << q.perimeter() << endl
	<< "Area: " << q.area() << endl;

	q.scale(3);
	q.print();

	cout << "Perimeter: " << q.perimeter() << endl
	<< "Area: " << q.area() << endl;

	Rectangle r(P1, P3, P2, P4);
	r.print();

	cout << "Perimeter: " << r.perimeter() << endl
	<< "Area: " << r.area() << endl;

	r.diagonal();
	r.print_diag();

	r.translate(2, 5);
	r.print();
	r.scale(3);
	r.print();

	Square s(P1, P3, P7, P6);
	s.print();

	cout << "Perimeter: " << s.perimeter() << endl
	<< "Area: " << s.area() << endl;

	s.diagonal();

	s.print_diag();

	s.translate(2, 5);
	s.print();
	s.scale(3);
	s.print();

	return 0;
}