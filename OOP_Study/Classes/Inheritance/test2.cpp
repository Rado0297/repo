#include <iostream>

using namespace std;

class base
{
private:
	int b;

public:
	base(int x = 0)
	{
		b = x;
	}
	int get_b() const
	{
		return b;
	}
	void f() const
	{
		cout << "b: " << b << endl;
	}
};

class der1 : public base
{
private:
	int d;

public:
	der1(int x = 0) : base(x)
	{
		d = 1;
	}
	int get_d() const
	{
		return d;
	}
	void f_der1() const
	{
		cout << "class der1: d: " << d << "b: " << get_b() << endl;
	}
};

class der2 : public base
{
private:
	int d;

public:
	der2(int x = 0) : base(x)
	{
		d = 2;
	}
	int get_d() const
	{
		return d;
	}
	void f_der2() const
	{
		cout << "class der2: d: " << d << "b: " << get_b() << endl;
	}
};

int main()
{
	der1 d1;
	der2 d2;
	base x = d2;
	d1 = x;
	der1 &d3 = d1;
	base &y = d3;
	d3 = y;
	der2 *d4 = &d2;
	d4->f_der2();
	base *z = d4;
	z->f();
	d4 = z;

	return 0;
}