#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Expr
{
private:
	int n;
	double x;

public:
	Expr(int, double);

	double Ex1() const;
	double Ex2() const;
	double Ex3() const;
};

Expr::Expr(int m, double y)
{
	n = m;
	x = y;
}

double Expr::Ex1() const
{
	double S = 1, x1 = 1;

	for (int i = 1; i <= n; ++i)
	{
		x1 = x1*x/i;
		S += x1;
	}

	return S;
}

double Expr::Ex2() const
{
	double S = 1, x1 = 1;

	for (int i = 1; i <= 2*n; ++i)
	{
		x1 = -x1*x*x/(i*(i+1));
		S += x1;
	}

	return S;
}

double Expr::Ex3() const
{
	double S = x, x1 = x;

	for (int i = 2; i <= 2*n; i = i+2)
	{
		x1 = -x1*x*x/(i*(i+1));
		S += x1;
	}

	return S;
}

int main()
{
	int n;

	do
	{
		cout << "n = ";
		cin >> n;
	} while (n < 0);

	double x;

	do
	{
		cout << "x = ";
		cin >> x;
	} while (fabs(x) > 1);

	Expr t(n, x);

	cout << setiosflags(ios::fixed) << setprecision(6);
	cout << "S1 = " << t.Ex1() << endl;
	cout << "exp(" << x << ") = " << exp(x) << endl;
	cout << "S2 = " << t.Ex2() << endl;
	cout << "cos(" << x << ") = " << cos(x) << endl;
	cout << "S3 = " << t.Ex3() << endl;
	cout << "sin(" << x << ") = " << sin(x) << endl;

	return 0;
}