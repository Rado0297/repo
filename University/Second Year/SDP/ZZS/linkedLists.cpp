#include <iostream>

template <typename T>
struct box
{
	T value;
	box* pointer;

	box(): value(0), pointer(nullptr) {};
	box(T _value, box* _pointer): value(_value), pointer(_pointer) {};
};

//find count of elements
template <typename T>
int size(box<T>* first)
{
	int size = 0;

	box<T>* temp = first;
	
	while (temp != nullptr)
	{
		size++;
		temp = temp->pointer;
	}

	return size;
}

//print whole list
template <typename T>
void print(box<T>* first)
{
	while (first != nullptr)
	{
		std::cout << first->value << " ";
		first = first->pointer;
	}

	std::cout << std::endl;
}

//push at the beginning
template <typename T>
void push(box<T>* &first, T val)
{
	box<T>* newBox = new box<T> ();
	newBox->value = val;
	newBox->pointer = first;
	first = newBox;
}

//push at the end
template <typename T>
void pushBack(box<T>* &first, T val)
{
	if (first == nullptr)
	{
		push(first, val);
		return;
	}

	box<T>* current = first;

	while (current->pointer != nullptr)
	{
		current = current->pointer;
	}

	box<T>* newBox = new box<T> (val, nullptr);
	current->pointer = newBox;
}


//push at the position
template <typename T>
void pushAtPosition(box<T>* &first, int position, T val)
{
	if (position > size(first) || position <= 0)
	{
		return;
	}

	if (position == 1)
	{
		push(first, val);
		return;
	}

	if (position == size(first))
	{
		pushBack(first, val);
		return;
	}

	box<T>* current = first;

	while (position > 1 && current->pointer != nullptr)
	{
		current = current->pointer;
		position--;
	}

	box<T>* newBox = new box<T> (val, current->pointer);
	current->pointer = newBox;
}

//pop first
template <typename T>
void pop(box<T>* &first)
{
	if (first != nullptr)
	{
		box<T>* current = first;
		first = first->pointer;
		delete current;
	}
}

//pop last element
template <typename T>
void popBack(box<T>* &first)
{
	if (first != nullptr)
	{
		box<T>* current = first;
		box<T>* remove = first;

		while (remove->pointer != nullptr)
		{
			current = remove;
			remove = remove->pointer;
		}

		current->pointer = nullptr;
		delete remove;
	}
}

//pop from position
template <typename T>
void popFromPosition(box<T>* &first, int position)
{
	if (position > size(first) || position <= 0)
	{
		return;
	}

	if (position == 1)
	{
		pop(first);
		return;
	}

	if (position == size(first))
	{
		popBack(first);
		return;
	}

	box<T>* current = first;
	box<T>* destroyer = first;

	while (position > 1 && current->pointer != nullptr)
	{
		current = destroyer;
		destroyer = destroyer->pointer;
		position--;
	}

	current->pointer = destroyer->pointer;
	delete destroyer;
}

//count X
template <typename T>
int countOfX(box<T>* first, T valueX)
{
	int count = 0;
	while (first != nullptr)
	{
		if (first->value == valueX)
		{
			count++;
		}
		first = first->pointer;
	}

	return count;
}

//range
template <typename T>
box<T>* range(T x, T y)
{
	if (x <= y)
	{

	}
}

//remove all X
template <typename T>
void removeAll(box<T>* &first, T valueX)
{
	box<T>* current = first;

	while (current->pointer != nullptr)
	{
		if (current->value == valueX)
		{
			box<T>* save = current;
			current = current->pointer;
			delete save;
		}
		current = current->pointer;
	}
}

//append - to first list append second so first list = elements from first list + elements of second list
template <typename T>
void append(box<T>* first, box<T>* second)
{
	if(first == NULL && second == NULL)
	{
		return;
	}

	if(first == NULL)
	{
		first = second;
	}

	else if(second == NULL)
	{
		return;
	}
	
	box<T>* crr = first;

	while (crr->next != NULL)
	{
		crr = crr->next;
	}

	crr->next = second;
}

//concat - newList = first lits's elements + second list's elements
template <typename T>
box<T>* concat(box<T>* first, box<T>* second)
{
	if (first == nullptr && second == nullptr)
	{
		return nullptr;
	}

	box<T>* result = new box<T> ();
	box<T>* current = result;

	if (first != nullptr)
	{
		result->value = first->value;
		result->pointer = first->pointer;

		first = first->pointer;
	}

	/*
		.
		.
		.
		.
		.
		.
	*/
}

//map - for exmaple every element of the list will be multiplied by 7

//reverse

//duplicate

//removeDuuplicate

//isSorted

//Tests

int main()
{
	box<int>* first = new box<int> (1, 
						new box<int> (2, 
							new box<int> (3, 
								new box<int> (4, 
									new box<int> (5, nullptr)))));

	box<int>* first = new box<int> (7, 
						new box<int> (8, 
							new box<int> (9, 
								new box<int> (10, 
									new box<int> (11, nullptr)))));

	print(first);

	popFromPosition(first, 3);
	
	print(first);																																																																					

	push(first, 13);
	pushAtPosition(first, 3, 3);
	pushAtPosition(first, 1, 3);
	pushAtPosition(first, 5, 3);
	pushBack(first, 11);
	print(first);

	std::cout << countOfX(first, 3) << std::endl;

	removeAll(first, 3);
	print(first);

	return 0;
}