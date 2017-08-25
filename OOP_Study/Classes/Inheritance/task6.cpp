#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class A
{
private:
	char* x;

public:
	A(char* = "");
	A(const A&);
	A& operator=(const A&);
	~A();

	void print() const;
};

A::A(char* _x)
{
	x = new char[strlen(_x) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, _x);
}

A::A(const A& a)
{
	x = new char[strlen(a.x) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, a.x);
}

A& A::operator=(const A& a)
{
	if (this != &a)
	{
		delete [] x;
		x = new char[strlen(a.x) + 1];
		if (!x)
		{
			cout << "Error while allocating memory for x!\n";
			exit(1);
		}
		strcpy(x, a.x);
	}

	return *this;
}

A::~A()
{
	cout << "~A()\n";
	delete [] x;
}

void A::print() const
{
	cout << "A::x " << x << endl;
}

class B : virtual public A
{
private:
	char* x;

public:
	B(char* = "", char* = "");
	B(const B&);
	B& operator=(const B&);
	~B();

	void print() const;
};

B::B(char* a, char* b) : A(a)
{
	x = new char[strlen(b) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, b);
}

B::B(const B& p)
{
	x = new char[strlen(p.x) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, p.x);
}

B& B::operator=(const B& p)
{
	if (this != &p)
	{
		A::operator=(p);
		delete [] x;
		x = new char[strlen(p.x) + 1];
		if (!x)
		{
			cout << "Error while allocating memory for x!\n";
			exit(1);
		}
		strcpy(x, p.x);
	}

	return *this;
}

B::~B()
{
	cout << "~B()\n";
	delete [] x;
}

void B::print() const
{
	A::print();
	cout << "B::x " << x << endl;
}

class C : virtual public A
{
private:
	char* x;

public:
	C(char* = "", char* = "");
	C(const C&);
	C& operator=(const C&);
	~C();
	
	void print() const;
};

C::C(char* a, char* c)  : A(a)
{
	x = new char[strlen(c) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, c);
}

C::C(const C& c) : A(c)
{
	x = new char[strlen(c.x) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, c.x);
}

C& C::operator=(const C& c)
{
	if (this != &c)
	{
		A::operator=(c);
		delete [] x;
		x = new char[strlen(c.x) + 1];
		if (!x)
		{
			cout << "Error while allocating memory for x!\n";
			exit(1);
		}
		strcpy(x, c.x);
	}

	return *this;
}

C::~C()
{
	cout << "~C()\n";
	delete [] x;
}

void C::print() const
{
	A::print();
	cout << "C::x " << x << endl;
}

class E : public A
{
private:
	char* x;

public:
	E(char* = "", char* = "");
	E(const E&);
	E& operator=(const E&);
	~E();

	void print() const;
};

E::E(char* a, char* e) : A(a)
{
	x = new char[strlen(e) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, e);
}

E::E(const E& e) : A(e)
{
	x = new char[strlen(e.x) + 1];
	if (!x)
	{
		cout << "Error while allocating memory for x!\n";
		exit(1);
	}
	strcpy(x, e.x);
}

E& E::operator=(const E& e)
{
	if (this != &e)
	{
		A::operator=(e);
		delete [] x;
		x = new char[strlen(e.x) + 1];
		if (!x)
		{
			cout << "Error while allocating memory for x!\n";
			exit(1);
		}
		strcpy(x, e.x);
	}

	return *this;
}

E::~E()
{
	cout << "~E()\n";
	delete [] x;
}

void E::print() const
{
	A::print();
	cout << "E::x " << x << endl;
}

class D : public B, public C, public E
{
private:
	char* x;

public:
	D(char* a = "", char* b = "", char* c = "", char* d = "", char* e = "") : A(a), B(a, b), C(a, c), E(a, e)
	{
		x = new char[strlen(d) + 1];
		if (!x)
		{
			cout << "Error while allocating memory for x!\n";
			exit(1);
		}
		strcpy(x, d);
	}

	D(const D& d) : A((const B&)d), B(d), C(d), E(d)
	{
		x = new char[strlen(d.x) + 1];
		if (!x)
		{
			cout << "Error while allocating memory for x!\n";
			exit(1);
		}
		strcpy(x, d.x);
	}

	D& operator=(const D& d)
	{
		if (this != &d)
		{
			B::operator=(d);
			C::operator=(d);
			E::operator=(d);
			delete [] x;

			x = new char[strlen(d.x) + 1];
			if (!x)
			{
				cout << "Error while allocating memory for x!\n";
				exit(1);
			}
			strcpy(x, d.x);
		}

		return *this;
	}

	~D()
	{
		cout << "~D()\n";
		delete [] x;
	}

	void print() const;
};

void D::print() const
{
	B::print();
	C::print();
	E::print();
	cout << "D::x " << x << endl;
}

int main()
{
	D d("111", "222", "333", "444", "555");
	D d1, d2;
	cout << "\n===========================================\n";
	d.print();
	cout << "\n===========================================\n";
	
	cout << "\n===========================================\n";
	d1.print();
	cout << "\n===========================================\n";

	cout << "\n===========================================\n";
	d2.print();
	cout << "\n===========================================\n";

	return 0;
}