#include <iostream>

using namespace std;

template<class T>
void swapI(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a = 4, b = 9;
	swapI(a, b);
	cout << a << " " << b << endl;

	double p = 1.5, q = -5.6;
	swapI(p, q);
	cout << p << " " << q << endl;

	char c = 'a', d = 'd';
	swapI(c, d);
	cout << c << " " << d << endl;

	return 0;
}