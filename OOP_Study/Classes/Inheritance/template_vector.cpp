#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class TVec
{
private:
	T* vector;
	int size;

protected:
	int lower;
	int upper;

public:
	TVec(int = 1);
	TVec(const TVec&);
	TVec& operator=(const TVec&);
	~TVec();

	T& operator[](int);
	int lowerbound() const;
	int upperbound() const;
};

template<class T>
TVec<T>::TVec(int s)
{
	if (s <= 0)
	{
		cout << "Incorrect size!\n";
		exit(1);
	}
	lower = 0;
	upper = s - 1;
	size = s;
	vector = new T[s];
	if (!vector)
	{
		cout << "Error while allocating memory for vector!\n";
		exit(1);
	}
}

template<class T>
TVec<T>::TVec(const TVec<T>& tv)
{
	size = tv.size;
	vector = new T[size];
	if (!vector)
	{
		cout << "Error while allocating memory for vector!\n";
		exit(1);
	}

	for (int i = 0; i < size; ++i)
	{
		vector[i] = tv.vector[i];
	}
	lower = tv.lower;
	upper = tv.upper;
}

template<class T>
TVec<T>& TVec<T>::operator=(const TVec<T>& tv)
{
	if (this != &tv)
	{
		delete [] vector;
		size = tv.size;
		vector = new T[size];
		if (!vector)
		{
			cout << "Error while allocating memory for vector!\n";
			exit(1);
		}

		for (int i = 0; i < size; ++i)
		{
			vector[i] = tv.vector[i];
		}
		lower = tv.lower;
		upper = tv.upper;
	}

	return *this;
}

template<class T>
TVec<T>::~TVec()
{
	delete [] vector;
}

template<class T>
T& TVec<T>::operator[](int i)
{
	if (i < 0 || i > upper - lower)
	{
		cout << "Incorrect index!\n";
		exit(1);
	}

	return vector[i];
}

template<class T>
int TVec<T>::lowerbound() const
{
	return lower;
}

template<class T>
int TVec<T>::upperbound() const
{
	return upper;
}

template<class T>
class TVector : public TVec<T>
{
public:
	TVector(int, int);
	T& operator[](int);
};

template<class T>
TVector<T>::TVector(int low, int upp) : TVec<T>(upp - low + 1)
{
	lower = low;
	upper = upp;
}

template<class T>
T& TVector<T>::operator[](int i)
{
	return TVec<T>::operator[](i - lower);
}

int main()
{
	TVec<int> u(4);
	int i;
	for (i = u.lowerbound(); i <= u.upperbound(); ++i)
	{
		cout << "> ";
		cin >> u[i];
	}

	for (i = u.lowerbound(); i <= u.upperbound(); ++i)
	{
		cout << u[i] << " ";
	}
	cout << endl;

	TVector<double> v(-4, 5);
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