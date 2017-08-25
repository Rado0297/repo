#include <iostream>
#include <cmath>

using namespace std;

struct rat
{
	private:
		int num;
		int den;

	public:
		void makerat(int, int); //create rational number
		int numer() const; //find numer
		int denom() const; //find denominator
		void printrat() const; //print rational number


};

int gcd(int a, int b)
{
	while(a != b)
	{
		if(a > b) a = a - b;
		else b = b - a;
	}
	return a;
}

void rat::makerat(int a, int b)
{
	if(a == 0)
	{
		num = 0;
		den = 1;
	}
	else
	{
		int absA = abs(a);
		int absB = abs(b);

		int g = gcd(absA, absB);
		if(a > 0 && b > 0 || a < 0 && b < 0)
		{
			num = abs(a)/g;
			den = abs(b)/g;
		}
		else
		{
			num = -abs(a)/g;
			den = abs(b)/g;
		}
	}
}

int rat::numer() const
{
	return num;
}

int rat::denom() const
{
	return den;
}

void rat::printrat() const
{
	cout << num << "/" << den << endl;
}

rat sumrat(const rat& r1, const rat& r2)
{
	rat r;
	r.makerat(r1.numer()*r2.denom() + r2.numer()*r1.denom(), r1.denom()*r2.denom());
	return r;
}

rat multrat(const rat& r1, const rat& r2)
{
	rat r;
	r.makerat(r1.numer()*r2.numer(), r1.denom()*r2.denom());
	return r;
}

rat Horner(int n, rat a[], const rat& x)
{
	rat s;

	s = a[0];

	for (int i = 0; i < n; ++i)
	{
		s = sumrat(multrat(s, x), a[i]);
	}
	return s;
}

int main()
{
	rat x, a[10];

	int p, q;

	do
	{
		cout << "x_numer, x_denom? ";
		cin >> p >> q;
	} while (q == 0);

	x.makerat(p, q);

	cout << "n = ";
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		do
		{
			cout << "x_numer, x_denom? ";
			cin >> p >> q;
		} while (q == 0);
		a[i].makerat(p, q);
	}

	Horner(n, a, x).printrat();

	return 0;
}