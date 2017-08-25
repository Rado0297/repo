#include <iostream>
#include <stdlib.h>

const int MAX_SIZE = 20;

using namespace std;

class IntArray
{
private:
	int *array;
	int num;
	bool isValid(int);

public:
	IntArray(int);
	IntArray(const IntArray&);
	~IntArray();

	bool set(int, int);
	bool get(int, int&);

	int linearSearch(int);
	int binarySearch(int);
	void selectionSort();
	void bubbleSort();

};

IntArray::IntArray(int size)
{
	if (size > MAX_SIZE)
	{
		cout << size << " is bigger than " << MAX_SIZE << "!\n";
		exit(1);
	}

	if (size <= 0)
	{
		cout << "Incorrect amount!\n";
		exit(1);
	}

	array = new int[size];
	if (!array)
	{
		cout << "Error while allocate memmory!\n";
		exit(1);
	}

	num = size;

	for (int i = 0; i < size; ++i)
	{
		array[i] = 0;
	}
}

IntArray::IntArray(const IntArray& p)
{
	array = new int[p.num];
	if (!array)
	{
		cout << "Error while allocate memmory!\n";
		exit(1);
	}

	for (int i = 0; i < p.num; ++i)
	{
		array[i] = p.array[i];
	}

	num = p.num;
}

IntArray::~IntArray()
{
	delete [] array;
}

bool IntArray::isValid(int elem)
{
	return elem >= 0 && elem < num;
}

bool IntArray::set(int elem, int value)
{
	if (isValid(elem))
	{
		array[elem] = value;
		return true;
	}

	return false;
}

bool IntArray::get(int elem, int& value)
{
	if (isValid(elem))
	{
		value = array[elem];
		return true;
	}
	return false;
}

int IntArray::linearSearch(int x)
{
	int i = 0;
	while(i < num-1 && x != array[i])
		i++;

	if (x == array[i])
	{
		return i;
	}
	else
	{
		return num;
	}
}

int IntArray::binarySearch(int x)
{
	int middle, left = 0, right = num - 1;
	if (x < array[left])
	{
		return -1;
	}
	if (x == array[left])
	{
		return 0;
	}
	if (x > array[left])
	{
		return num;
	}
	while(right-left > 1)
	{
		middle = (left + right)/2;
		if (x <= array[middle])
		{
			right = middle;
		}
		else
		{
			left = middle;
		}
	}
	return right;
}

void IntArray::selectionSort()
{
	int i, j, k;
	int min;
	for (i = 0; i < num-1; ++i)
	{
		k = i;
		min = array[k];
		for (j = i+1; j < num; ++j)
		{
			if (array[j] < min)
			{
				k = j;
				min = array[j];
			}
		}
		array[k] = array[i];
		array[i] = min;
	}
}

void IntArray::bubbleSort()
{
	int i, k, right = num-1;
	while(right > 0)
	{
		k = 0;
		int swap;
		for (i = 0; i < right; ++i)
		{
			if (array[i+1] < array[i])
			{
				swap = array[i];
				array[i] = array[i+1];
				array[i] = swap;
				k = i;
			}
		}
		right = k;
	}
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	IntArray a(n);
	int val, i;

	for (i = 0; i < n; ++i)
	{
		cout << "Element? ";
		cin >> val;
		if (!a.set(i, val))
		{
			cout << "Error in initialization of an array!\n";
		}
	}

	cout << endl;

	for (i = 0; i < n; ++i)
	{
		if (a.get(i, val))
		{
			cout << val << endl;
		}
		else
		{
			cout << "Error while getting element of array!\n";
		}
	}

	cout << endl;

	if (a.set(n, MAX_SIZE+1))
	{
		cout << "Element " << MAX_SIZE+1 << " has been written succssesful!\n";
	}
	else
	{
		cout << "Error in process of writing of element " << MAX_SIZE+1 << ".\n";
	}

	cout << "Element? ";
	cin >> val;

	if(a.get(a.linearSearch(val), val))
	{
		cout << val << " is in the array!\n";
	}
	else
	{
		cout << val << " is not in the array!\n";
	}

	a.bubbleSort();
	cout << "Sorted array!\n";

	for (i = 0; i < n; ++i)
	{
		if (a.get(i, val))
		{
			cout << val << " ";
		}
		else
		{
			cout << "Error in getting element!\n";
		}
	}

	cout << endl;

	cout << "Element? ";
	cin >> val;

	cout << "Position of " << val << " in array is: " << a.binarySearch(val) << endl;

	return 0;
}