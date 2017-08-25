#include <iostream>

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
	void setValues(int arr[]);
	~IntArray();	
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
	this->array = new int[p.num];
	if (!this->array)
	{
		cout << "Error while allocate memmory!\n";
		exit(1);
	}

	for (int i = 0; i < p.num; ++i)
	{
		this->array[i] = p.array[i];
	}

	this->num = p.num;
}

void IntArray::setValues(int arr[])
{
	for (int i = 0; i < 6; ++i)
	{
		array[i] = arr[i];
	}
}

IntArray::~IntArray()
{
	delete [] array;
}

int main()
{
	IntArray arr1(6), arr2(6);	

	arr1

	return 0;
}