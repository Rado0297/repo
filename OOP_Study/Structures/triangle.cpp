#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

struct Triangle
{
	int a;
	int b;
	int c;
};

Triangle create_triangle()
{
	Triangle t;

	cout << "Side a:"; cin >> t.a;
	cout << "Side b:"; cin >> t.b;
	cout << "Side c:"; cin >> t.c;

	return t;
}

void print_triangle(Triangle t)
{
	cout << setw(10) << t.a;
	cout << setw(10) << t.b;
	cout << setw(10) << t.c;
	cout << endl;
}

int perimeter(Triangle t)
{
	return (t.a + t.b + t.c);
}

int area(Triangle t)
{
	int p = (t.a + t.b + t.c)/2;

	int S = sqrt(p*(p-t.a)*(p-t.b)*(p-t.c));

	return S;
}

int main()
{
	print_triangle(create_triangle());

	cout << perimeter(t) << " " << area(t) << endl;

	return 0;
}