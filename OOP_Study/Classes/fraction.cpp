#include <iostream>

using namespace std;

class Fraction
{
private:
	int n;
	int d;

public:
	Fraction(int x, int y);
	int getN() const;
	int getD() const;
	
	friend bool IsFraction(const Fraction& obj);
};

Fraction::Fraction(int x, int y)
{
	n = x;
	d = y;
}

int Fraction::getN() const
{
	return n;
}

int Fraction::getD() const
{
	return d;
}

bool IsFraction(const Fraction& obj)
{
	return obj.n % obj.d != 0;
}

int main()
{
	int a, b;

	do
	{
		cout << "a, b (b different from 0): ";
		cin >> a >> b;
	} while(b == 0);

	Fraction f(a,b);

	if (IsFraction(f))
	{
		cout << f.getN() << " not devide by " << f.getD() << endl;
	}
	else
	{
		cout << f.getN() << " is devideable on " << f.getD() << endl;
	}

	return 0;
}