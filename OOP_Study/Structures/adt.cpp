#include <iostream>
#include <math.h>

using namespace std;

const int MAX_SIZE = 20;

struct Triangle
{
	private:
	double a, b, c;

	public:
	void init_tr(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}

	void print_tr()
	{
		cout << "Triangle (" << a << ", " << b << ", " << c << ")\n";
	}

	double get_a() const
	{
		return a;
	}

	double get_b() const
	{
		return b;
	}

	double get_c() const
	{
		return c;
	}

	double perimeter() const
	{
		return a + b + c;	
	}

	double surface() const
	{
		double p = (a + b + c)/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}

	Triangle mult_k(int k)
	{
		Triangle t;
		t.init_tr(a*k, b*k, c*k);
		return t;
	}

	Triangle minSurface(int n, Triangle T[])
	{
		int k = 0;
		double Min = T[0].surface();
		for (int i = 1; i < n; ++i)
		{
			if (T[i].surface() < Min)
			{
				Min = T[i].surface();
				k = i;
			}
		}

		return T[k];
	}

	Triangle MaxPerimeter(int n, Triangle T[])
	{
		int k = 0;
		double Max = T[0].perimeter();
		for (int i = 1; i < n; ++i)
		{
			if (T[i].perimeter() > Max)
			{
				Max = T[i].perimeter();
				k = i;
			}
		}

		return T[k];
	}

	void newSequence(int n, Triangle *T, Triangle *NewT)
	{
		for (int i = 0; i < n; ++i)
		{
			NewT[i] = T[i].mult_k(i+1);
		}
	}
};

int main()
{
	int n;

	do
	{
		cout << "n = ";
		cin >> n;
	} while (n < 1 || n > MAX_SIZE);

	Triangle T[MAX_SIZE];

	for (int i = 0; i < n; ++i)
	{
		double x, y, z;
		bool tri;

		do
		{
			cout << "x, y, z (tr's sides): ";
			cin >> x >> y >> z;
			tri = (x > 0) && (y > 0) && (z > 0) && (x + y > z) && (x + z > y) && (y + z > x);
		} while (!tri);

		T[i].init_tr(x, y, z);
	}

	cout << "Sequence of Triangles:\n";
	for (int i = 0; i < n; ++i)
	{
		T[i].print_tr();
	}

	cout << "Smallest surface of tr:\n";
	minSurface(n, T).print_tr();

	cout << "Biggest perimeter of tr:\n";
	maxPerimeter(n, T).print_tr();

	Triangle NT[MAX_SIZE];
	cout << "New sequence:\n";
	newSequence(n, T, NT);

	for (int i = 0; i < n; ++i)
	{
		NT[i].print_tr();
	}

	return 0;
}