#include <iostream>

using namespace std;

class gcd
{
private:
	int x, y;

public:
	gcd(int a, int b)
	{
		x = a;
		y = b;
	}

	int value() const
	{
		if (y == 0)
		{
			return x;
		}

		else
		{
			gcd t(y, x%y);
			return t.value();
		}
	}

	friend istream& operator>>(istream& istr, gcd& ob);
	friend ostream& operator<<(ostream& ostr, const gcd& ob);
};

istream& operator>>(istream& istr, gcd& ob)
{
	do
	{
		istr >> ob.x >> ob.y;
	} while(ob.x < 0 || ob.y < 0 || (ob.x == 0 && ob.y == 0));

	return istr;
}

ostream& operator<<(ostream& ostr, const gcd& ob)
{
	ostr << "gcd(" << ob.x << ", " << ob.y << ") = " << ob.value() << endl;
	return ostr;
}

int main()
{
	int a, b;

	do
	{
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
	} while(a < 0 || b < 0 || a == 0 && b == 0);

	gcd t(a, b);
	cout << t;
	cin >> t;
	cout << t;

	return 0;
}