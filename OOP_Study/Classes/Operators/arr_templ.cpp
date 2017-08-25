#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 100;

template<class T>
class Array
{
private:
	T* arr;
	int size;

public:
	//The Fourth!
	Array(int);
	Array(const Array&);
	Array& operator=(const Array&);
	~Array();

	int get_size() const;
	T& operator[](int);
};

template<class T>
Array<T>::Array(int n)
{
	if (n > MAX_SIZE)
	{
		cout << n << " is bigger than " << MAX_SIZE << ".\n";
		exit(1);
	}

	if (n <= 0)
	{
		cout << "Incorrect size!\n";
		exit(1);
	}

	size = n;
	arr = new T[n];
	if (!arr)
	{
		cout << "Ocurred error while alocating memory!\n";
		exit(1);
	}
}

template<class T>
Array<T>::Array(const Array<T>& p)
{
	size = p.size;
	arr = new T[size];
	if (!arr)
	{
		cout << "Ocurred error while alocating memory!\n";
		exit(1);
	}

	for (int i = 0; i < size; ++i)
	{
		arr[i] = p.arr[i];
	}
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& p)
{
	if (this != p)
	{
		delete [] arr;
		size = p.size;
		arr = new T[size];

		if (!arr)
		{
			cout << "Ocurred error while alocating memory!\n";
			exit(1);
		}

		for (int i = 0; i < size; ++i)
		{
			arr[i] = p.arr[i];
		}
	}
	return *this;
}

template<class T>
Array<T>::~Array()
{
	delete [] arr;
}

//Index operator
template<class T>
T& Array<T>::operator[](int sub)
{
	if (sub < 0 || sub >= size)
	{
		cout << "Error: Index is out of range!\n";
		exit(1);
	}

	return arr[sub];
}

//Number of elements in array
template<class T>
int Array<T>::get_size() const
{
	return size;
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	Array<int>	a(n);
	for (int i = 0; i < n; ++i)
	{
		a[i] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		a[i] = a[i] + 5;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		a[i]--;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	Array<char> c(n);

	for (int i = 0; i < n; ++i)
	{
		c[i] = (char)(i + 65);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		c[i] = (char)(c[i] + 5);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		c[i]--;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	return 0;
}