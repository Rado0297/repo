#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if(y == 0) return x;

	return gcd(y, x/y);
}

class GCD
{
private:
	int x, y;

public:
	GCD(int a, int b)
	{
		x = a;
		y = b;
	}

	int value() const
	{
		if(y == 0) return x;
		else
		{
			GCD t(y, x/y);
			return t.value();
		}
	}
};

int main()
{
	int a, b;

	do
	{
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
	} while (a < 0 || b < 0 || a == 0 && b == 0);

	GCD t(a, b);

	cout << t.value() << endl;

	return 0;
}