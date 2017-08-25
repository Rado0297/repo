#include <iostream>

using namespace std;

class Base
{
public:
	int x;
	Base(int a)
	{
		x = a;
	}
	virtual void f() const
	{
		cout << "Base::f()\n" << "Base::x " << x << endl;
	}
};

class Der1 : public Base
{
public:
	Der1(int a) : Base(a)
	{}
	void f() const
	{
		cout << "Der1::f() " << x+1 << endl;
	}
};

class Der2 : public Der1
{
public:
	Der2(int a) : Der1(a)
	{}
	void f() const
	{
		cout << "Der2::f() " << 2*x+1 << endl;
	}
};

class Der3 : public Der2
{
private:
	void f() const
	{
		cout << "Der3::f() " << 3*x+1 << endl;
	}

public:
	Der3(int a) : Der2(a)
	{}
};

class Der4 : public Der3
{
public:
	Der4(int a) : Der3(a)
	{}

	void f() const
	{
		cout << "Der4::f() " << 4*x+1 << endl;
	}
};

int main()
{
	Base b(1);
	Der1 d1(5);
	Der2 d2(10);
	Der3 d3(15);
	Der4 d4(20);

	Base *ptr = &b;
	ptr->f();

	ptr = &d1;
	ptr->f();

	ptr = &d2;
	ptr->f();

	ptr = &d3;
	ptr->f();

	ptr = &d4;
	ptr->f();

	Der2* ptr2;
	ptr2 = &d2;
	ptr->f();

	ptr2 = &d3;
	ptr->f();

	ptr2 = &d4;
	ptr->f();

	return 0;
}