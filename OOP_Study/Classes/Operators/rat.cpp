#include <iostream>
#include <cmath>

using namespace std;

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}

	return gcd(y, x % y);
}

class Rat
{
private:
	int num;
	int den;

public:
	Rat(int = 0, int = 1);
	Rat(const Rat&);
	Rat sum(const Rat&) const;
	Rat mult(const Rat&) const;
	Rat sub(const Rat&) const;
	Rat div(const Rat&) const;

	void print() const;

	int numer() const;
	int denom() const;

	void setNum(int);
	void setDen(int);
};

Rat operator+(const Rat&, const Rat&);
Rat operator*(const Rat&, const Rat&);
Rat operator-(const Rat&, const Rat&);
Rat operator/(const Rat&, const Rat&);

Rat::Rat(int n, int d)
{
	if (d == 0)
	{
		cout << "Denom can't be 0! It will be replaced with 1!\n";
		num = n;
		den = 1;
	}

	else
	{
		if (n == 0)
		{
			num = 0;
			den = 1;
		}

		else
		{
			int g = gcd(abs(n), abs(d));
			
			if (n > 0 && d > 0 || n < 0 && d < 0)
			{
				num = abs(n);
				den = abs(d);
			}

			else
			{
				num = -abs(n);
				den = abs(d);
			}
		}
	}
}

Rat::Rat(const Rat& p)
{
	num = p.num;
	den = p.den;
}

int Rat::numer() const
{
	return num;
}

int Rat::denom() const
{
	return den;
}

void Rat::print() const
{
	cout << num << "/" << den;
}

void Rat::setNum(int n)
{
	num = n;
}

void Rat::setDen(int d)
{
	if (d != 0)
	{
		den = d;
	}

	else
	{
		cout << "Denom can't be 0! It will be replaced with 1!\n";
		den = 1;
	}
}

Rat Rat::sum(const Rat& r) const
{
	return Rat(num*r.den + den*r.num, den*r.den);
}

Rat Rat::sub(const Rat& r) const
{
	return Rat(num*r.den - den*r.num, den*r.den);
}

Rat Rat::mult(const Rat& r) const
{
	return Rat(num*r.num, den*r.den);
}

Rat Rat::div(const Rat& r) const
{
	return Rat(num*r.den, den*r.num);
}

Rat operator+(const Rat& r, const Rat& s)
{
	return r.sum(s);
}

Rat operator-(const Rat& r, const Rat& s)
{
	return r.sub(s);
}

Rat operator*(const Rat& r, const Rat& s)
{
	return r.mult(s);
}

Rat operator/(const Rat& r, const Rat& s)
{
	return r.div(s);
}

int main()
{
	int a, b;

	cout << "a, b = ";
	cin >> a >> b;

	Rat r(a, b);

	int c, d;

	do
	{
		cout << "c, d = ";
		cin >> c >> d;
	} while (c == 0 || d == 0);

	Rat s(c, d);

	Rat sum = r + s;
	Rat sub = r - s;
	Rat mult = r * s;
	Rat div = r / s;

	r.print(); cout << " + "; s.print(); cout << " = "; sum.print(); cout << endl;
	r.print(); cout << " - "; s.print(); cout << " = "; sub.print(); cout << endl;
	r.print(); cout << " * "; s.print(); cout << " = "; mult.print(); cout << endl;
	r.print(); cout << " / "; s.print(); cout << " = "; div.print(); cout << endl;

	r.setNum(5);
	r.setDen(7);
	r.print();
	cout << endl;

	return 0;
}