#include <iostream>
#include <stdlib.h>

using namespace std;

class Indexed
{
private:
	int* array;
	int size;

public:
	Indexed(int = 1);
	Indexed(const Indexed&);
	Indexed& operator=(const Indexed&);
	~Indexed();

	double& operator[](int);
	int getSize() const;

	void addBefore(int, int);
	void addAfter(int, int);
	void remove(int);

	Indexed section();
	Indexed unification();
	Indexed difference();
};

Indexed::Indexed(int s)
{
	if (s < 0)
	{
		cout << "Invalid vector size!\n";
		exit(1);
	}

	size = s;
	array = new int[size];
	if (!array)
	{
		cout << "Error while allocating memory for array!\n";
		exit(1);
	}
}

Indexed::Indexed(const Indexed& a)
{
	size = a.size;
	array = new int[size];
	if (!array)
	{
		cout << "Error while allocating memory for array!\n";
		exit(1);
	}

	for (int i = 0; i < size; ++i)
	{
		array[i] = a.array[i];
	}
}

Indexed& Indexed::operator=(const Indexed& a)
{
	if (this != &a)
	{
		delete [] array;
		size = a.size;
		array = new int[size];
		if (!array)
		{
			cout << "Error while allocating memory for array!\n";
			exit(1);
		}

		for (int i = 0; i < size; ++i)
		{
			array[i] = a.array[i];
		}
	}

	return *this;
}

Indexed::~Indexed()
{
	delete [] array;
}

double& Indexed::operator[](int i)
{
	if (i < 0 || i > size - 1)
	{
		cout << "Incorrect index!\n";
		exit(1);
	}
	return array[i];
}

int Indexed::getSize() const
{
	return size;
}

void Indexed::addBefore(int val, int i)
{
	if (i = 0 || i < size-1)
	{
		size++;
		for (int j = size-1; j > i; j--)
		{
			array[j] = array[j-1];
		}
		array[i] = val;
	}

	else if (i = size - 1)
	{
		size++;
		array[size-1] = array[size-2];
		array[size-2] = val;
	}

	else
	{
		cout << "Incorrect index has been entered!\n";
		exit(1);
	}
}

void Indexed::addAfter(int val, int i)
{
	if (i >= 0)
	{
		size++;
		for (int j = size-1; j > i; ++j)
		{
			array[j] = array[j-1];
		}
	}

	else
	{
		cout << "Incorrect index!\n";
		exit(1);
	}
}

void Indexed::remove(int i)
{

}

//	Indexed section();
//	Indexed unification();
//	Indexed difference();

class Sorted : public Indexed
{
private:


public:

};

int main()
{
	Indexed ind(6);	

	double var = 1.5;

	for (int i = 0; i < 6; ++i)
	{
		ind[i] = var;
		var++;
	}

	ind.addBefore(10, 2);

	for (int i = 0; i < 7; ++i)
	{
		cout << ind[i] << " ";
	}
	cout << endl;


	return 0;
}

/*


class DoubleVector : public DoubleVec
{
public:
	DoubleVector(int, int);
	double& operator[](int);
};

DoubleVector::DoubleVector(int low, int upp) : DoubleVec(upp - low + 1)
{
	lower = low;
	upper = upp;
}

double& DoubleVector::operator[](int i)
{
	return DoubleVec::operator[](i - lower);
}

int main()
{
	DoubleVec u(4);
	int i;
	for (i = u.lowerbound(); i < u.upperbound(); ++i)
	{
		cout << "> ";
		cin >> u[i];
	}

	for (i = u.lowerbound(); i <= u.upperbound(); ++i)
	{
		cout << u[i] << " ";
	}
	cout << endl;

	DoubleVector v(26, 35);
	for (i = v.lowerbound(); i <= v.upperbound(); ++i)
	{
		cout << "> ";
		cin >> v[i];
	}

	for (i = v.lowerbound(); i <= v.upperbound(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
*/