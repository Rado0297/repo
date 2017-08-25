#include <iostream>
#include <stdlib.h>

using namespace std;

class Monotone
{
private:
	int* array;
	int size;

public:
	Monotone(int*, int = 0);
	~Monotone();

	bool isMonotoneDesc() const;

	void print();
};

Monotone::Monotone(int* arr, int _size)
{
	size = _size;

	array = new int[size];
	if (!array)
	{
		cout << "Error whille allocating memomry!\n";
		exit(1);
	}

	for (int i = 0; i < size; ++i)
	{
		array[i] = arr[i];
	}
}

Monotone::~Monotone()
{
	delete [] array;
}

bool Monotone::isMonotoneDesc() const
{
	int check = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		if(array[i] >= array[i+1])
			check++;
	}

	if (check == size - 1)
	{
		return true;
	}

	return false;
}

void Monotone::print()
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[100];

	cout << "Enter number of elements: ";
	int elements;
	cin >> elements;

	for (int i = 0; i < elements; ++i)
	{
		cout << "Enter value of arr[" << i << "] = ";
		cin >> arr[i];
	}

	Monotone obj(arr, elements);

	cout << obj.isMonotoneDesc() << endl;

	obj.print();

	return 0;
}