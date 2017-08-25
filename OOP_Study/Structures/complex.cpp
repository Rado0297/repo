#include <iostream>
#include <cmath>

using namespace std;

struct complex
{
private:
	double Re,
		   Im;
public:
	void create(double, double);
	void print();
	double get_Re() const;
	double get_Im() const;
	bool isZero();
	complex sum(const complex&);
	complex sub(const complex&);
	complex mult(const complex&);
	complex quot(const complex&);
};

void complex::create(double x, double y)
{
	Re = x;
	Im = y;
}

void complex::print()
{
	cout << Re << (Im < 0 ? "" : "+") << Im << "i\n";
}

double complex::get_Re() const
{
	return Re;
}

double complex::get_Im() const
{
	return Im;
}

bool complex::isZero()
{
	return (Re == 0 && Im == 0);
}

complex complex::sum(const complex& c)
{
	complex p;
	p.create(Re + c.Re, Im + c.Im);
	return p;
}

complex complex::sub(const complex& c)
{
	complex p;
	p.create(Re - c.Re, Im - c.Im);
	return p;
}

complex complex::mult(const complex& c)
{
	complex p;
	p.create(Re*c.Re - Im*c.Im, Re*c.Im + Im*c.Re);
	return p;
}

complex complex::quot(const complex& c)
{
	complex p;
	double den = c.Re*c.Re + c.Im*c.Im;
	p.create((Re*c.Re + Im*c.Im)/den, (Im*c.Re + Re*c.Im)/den);
	return p;
}

int main()
{
	int p, q;
	cout << "Enter first complex number\n";
	cout << "Re: "; cin >> p;
	cout << "Im: "; cin >> q;

	complex c1;
	c1.create(p, q);

	cout << "Enter second complex number\n";
	cout << "Re: "; cin >> p;
	cout << "Im: "; cin >> q;

	complex c2;
	c2.create(p, q);

	complex result;

	result = c1.sum(c2);
	result.print();

	result = c1.sub(c2);
	result.print();

	result = c1.mult(c2);
	result.print();

	result = c1.quot(c2);
	result.print();

	return 0;
}