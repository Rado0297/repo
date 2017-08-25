#include <iostream>
#include <stdlib.h>

using namespace std;

class DoubleVec
{
private:
	double* vector;
	int size;

protected:
	int lower;
	int upper;

public:
	DoubleVec(int = 1);
	DoubleVec(const DoubleVec&);
	DoubleVec& operator=(const DoubleVec&);
	~DoubleVec();

	double& operator[](int);
	int lowerbound() const;
	int upperbound() const;
};

DoubleVec::DoubleVec(int s)
{
	if (s < 0)
	{
		cout << "Invalid vector size!\n";
		exit(1);
	}

	lower = 0;
	upper = s-1;
	size = s;
	vector = new double[s];
	if (!vector)
	{
		cout << "Error while allocating memory for vector!\n";
		exit(1);
	}
}

DoubleVec::DoubleVec(const DoubleVec& v)
{
	size = v.size;
	vector = new double[size];
	if (!vector)
	{
		cout << "Error while allocating memory for vector!\n";
		exit(1);
	}

	for (int i = 0; i < size; ++i)
	{
		vector[i] = v.vector[i];
	}

	lower = v.lower;
	upper = v.upper;
}

DoubleVec& DoubleVec::operator=(const DoubleVec& v)
{
	if (this != &v)
	{
		delete[] vector;

		size = v.size;
		vector = new double[size];
		if (!vector)
		{
			cout << "Error while allocating memory for vector!\n";
			exit(1);
		}

		lower = v.lower;
		upper = v.upper;

		for (int i = 0; i < size; ++i)
		{
			vector[i] = v.vector[i];
		}
	}

	return *this;
}

DoubleVec::~DoubleVec()
{
	delete [] vector;
}


double& DoubleVec::operator[](int i)
{
	if (i < 0 || i > upper - lower)
	{
		cout << "Incorrect index!\n";
		exit(1);
	}

	return vector[i];
}


int DoubleVec::lowerbound() const
{
	return lower;
}

int DoubleVec::upperbound() const
{
	return upper;
}

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