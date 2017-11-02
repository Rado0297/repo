// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*

Да се напише фунцкия bool palindrom (box *l), която проверява дали редицата от елементи на даден списък обрзува палиндром 
(т.е.дали се чете еднакво както отляво надясно така и отдяно наляво).

*/

#include<iostream>

template <typename T>
struct Box
{
	T value;
	Box * pointer;

	Box() : value(0), pointer(nullptr) {};
	Box(T _value, Box * _pointer) : value(_value), pointer(_pointer) {};
};

template <typename T>
int size(Box<T> * first)
{
	int size = 0;

	while (first != nullptr)
	{
		size++;
		first = first->pointer;
	}

	return size;
}

template <typename T>
void print(Box<T> * first)
{
	while (first != nullptr)
	{
		std::cout << first->value << " ";
		first = first->pointer;
	}
	std::cout << std::endl;
}

template <typename T>
void push(Box<T> * & first, T _value)
{
	Box<T> * newBox = new Box<T>;
	newBox->value = _value;
	newBox->pointer = first;
	first = newBox;
	
	//first = new Box<T>(_value, first);
}

template <typename T>
void pushBack(Box<T> * & first, T _value)
{
	if (first == nullptr)
	{
		push(first,_value);
		return;
	}

	Box<T> * current = first;

	while (current->pointer != nullptr)
	{
		current = current->pointer;
	}

	Box<T> * newBox = new Box<T>(_value, nullptr);
	current->pointer = newBox;
}

template <typename T>
void pushPosition(Box<T> * & first, int position, T _value)
{
	if (position > size(first) || position <= 0)
	{
		return;
	}

	if (position == 1)
	{
		push(first, _value);
		return;
	}

	if (position == size(first))
	{
		pushBack(first, _value);
		return;
	}

	Box<T> * current = first;

	while (position - 2 > 0)
	{
		current = current->pointer;
		position--;
	}

	Box<T> * newBox = new Box<T>(_value, current->pointer);

	current->pointer = newBox;
	
}

template <typename T>
void pop(Box<T> * & first)
{
	if (first != nullptr)
	{
		Box<T> * current = first;
		first = first->pointer;
		delete current;
	}
}

template <typename T>
void popBack(Box<T> * & first)
{
	if (first != nullptr)
	{
		Box<T> * current = first;
		Box<T> * remuve = first;

		while (remuve->pointer != nullptr)
		{
			current = remuve;
			remuve = remuve->pointer;
		}

		current->pointer = nullptr;
		delete remuve;
	}
}

template <typename T>
void popPosition(Box<T> * & first, int position)
{
	if (position > size(first) || position <= 0)
	{
		return;
	}

	if (position == 1)
	{
		pop(first);
	}

	if (position == size(first))
	{
		popBack(first);
	}

	Box<T> * current = first;

	while (position - 2 > 0)
	{
		current = current->pointer;
		position--;
	}

	Box<T> *remove = current->pointer;

	current->pointer = remove->pointer;

	delete remove;
}

template <typename T>
int countIteration(Box<T> * first, T element)
{
	int counter = 0;

	while (first != nullptr)
	{
		if (first->value == element)
		{
			counter++;
		}

		first = first->pointer;
	}

	return counter;
}

template <typename T>
Box<T> * range(Box<T> * first, int x, int y)
{
	if (x <= y)
	{
		int counter = y - x + 1;

		while (x > 1)
		{
			first = first->pointer;
			x--;
		}

		Box<T> * result = new Box<T>(first->value, nullptr);
		Box<T> * currentNewPointer = result;

		first = first->pointer;

		while (counter > 1)
		{
			Box<T> * newBoxToAdd = new Box<T>(first->value, nullptr);
			currentNewPointer->pointer = newBoxToAdd;
			currentNewPointer = currentNewPointer->pointer;
			first = first->pointer;
			counter--;
		}

		return result;
	}
}

template <typename T>
void removeAll(Box<T> * & first, int x)
{
	if (first == nullptr)
	{
		return;
	}

	if (first->pointer == nullptr && first->value == x)
	{
		delete first;
		first = nullptr;
		return;
	}

	while (first->value == x)
	{
		pop(first);
	}

	Box<T> * current1 = first;
	Box<T> * current2 = first->pointer;

	while (current2 != nullptr)
	{
		if (current2->value == x)
		{
			current1->pointer = current2->pointer;
			delete current2;
			current2 = current1->pointer;
		}
		else
		{
			current1 = current2;
			current2 = current2->pointer;
		}
	}
}

template <typename T>
void append(Box<T> * & first1, Box<T> * first2)
{
	if (first2 == nullptr)
	{
		return;
	}

	Box<T> * current = first1;
	
	while (current->pointer != nullptr)
	{
		current = current->pointer;
	}

	while (first2 != nullptr)
	{
		Box<T> *newBox = new Box<T>(first2->value, nullptr);
		current->pointer = newBox;
		current = current->pointer;
		first2 = first2->pointer;
	}
}

template <typename T>
Box<T> * concat(Box<T> * first1, Box<T> * first2)
{
	if (first1 == nullptr && first2 == nullptr)
	{
		return nullptr;
	}

	Box<T> * result = new Box<T>;
	Box<T> * current = result;

	if (first1 != nullptr)
	{
		result->value = first1->value;
		result->pointer = first1->pointer;

		first1 = first1->pointer;

		while (first1->pointer != nullptr)
		{
			Box<T> * newBox = new Box<T>(first1->value, first1->pointer);
			current->pointer = newBox;
			current = newBox;
			first1 = first1->pointer;
		}

		if (first2 != nullptr)
		{
			if (first2->pointer == nullptr)
			{
				Box<T> * newBox = new Box<T>(first2->value, first2->pointer);
				current->pointer = newBox;
				current = newBox;
			}

			while (first2->pointer != nullptr)
			{
				Box<T> * newBox = new Box<T>(first2->value, first2->pointer);
				current->pointer = newBox;
				current = newBox;
				first2 = first2->pointer;
			}
		}

		return result;
	}
	else
	{
		result->value = first2->value;
		result->pointer = first2->pointer;

		while (first2->pointer != nullptr)
		{
			Box<T> * newBox = new Box<T>(first2->value, first2->pointer);
			current->pointer = newBox;
			current = current->pointer;
			first2 = first2->pointer;
		}

		return result;
	}
}

int function(int & x)
{
	return 2 * x;
}

template <typename T>
void map(Box<T> * & first)
{
	Box<T> * current = first;

	while (current != nullptr)
	{
		current->value = function(current->value);
		current = current->pointer;
	}
}

template <typename T>
void reverse(Box<T> * & first)
{
	if (first == nullptr)
	{
		return;
	}

	Box<T> * current = first;
	Box<T> * save = first->pointer;

	first = save->pointer;
	current->pointer = nullptr;

	while (first != nullptr)
	{
		save->pointer = current;
		
		current = save;
		save = first;
		first = first->pointer;
	}

	save->pointer = current;
	first = save;
}

template <typename T>
bool duplicate(Box<T> * first)
{
	Box<T> * current;

	while (first->pointer != nullptr)
	{
		current = first->pointer;

		while (current != nullptr)
		{
			if (first->value == current->value)
			{
				return true;
			}
			current = current->pointer;
		}

		first = first->pointer;
	}

	return false;
}

template <typename T>
void remuveDuplicate(Box<T> * & first)
{
	Box<T> * current1 = first;
	Box<T> * current2;
	Box<T> * remuve;

	while (current1->pointer != nullptr)
	{
		current2 = current1;
		remuve = current2->pointer;

		while (current2->pointer != nullptr)
		{
			while (current1->value == remuve->value)
			{
				current2->pointer = remuve->pointer;
				delete remuve;
				remuve = current2->pointer;
			}

			current2 = current2->pointer;
			remuve = remuve->pointer;
		}

		current1 = current1->pointer;
	}
}

template <typename T>
bool issorted(Box<T> * first)
{
	Box<T> * current = first->pointer;

	while (current != nullptr)
	{
		if (first->value <= current->value)
		{
			current = current->pointer;
			first = first->pointer;
		}
		else
		{
			return false;
		}
	}

	return true;
}

/*
template <typename T>
bool palindrom(Box<T> * linkedList1)
{
	Box<T> * current1 = linkedList1;
	Box<T> * linkedList2 = nullptr;

	while (current1 != nullptr)
	{
		push(linkedList2, current1->value);
		current1 = current1->pointer;
	}

	print(linkedList2);

	return true;
}
*/

template <typename T>
void testMakeLinkedList(Box<T> * & first)
{
	pushBack(first, 1);
	pushBack(first, 2);
	pushBack(first, 3);
	pushBack(first, 4);
	pushBack(first, 5);
	pushBack(first, 6);

	print(first);
}

template <typename T>
void testIterationOfTheElements(Box<T> * & first)
{
	std::cout << countIteration(first, 2) << std::endl;
}

 template <typename T>
 void testRange(Box<T> * & first)
 {
	 print(range(first, 3, 6));
 }

 void testRemuveAll()
 {
	 Box<int> * linkedListToRemove;
	 linkedListToRemove = nullptr;

	 push(linkedListToRemove, 1);
	 push(linkedListToRemove, 1);
	 push(linkedListToRemove, 1);
	 push(linkedListToRemove, 2);
	 push(linkedListToRemove, 1);
	 push(linkedListToRemove, 1);
	 push(linkedListToRemove, 3);
	 push(linkedListToRemove, 4);
	 push(linkedListToRemove, 5);
	 push(linkedListToRemove, 1);
	 push(linkedListToRemove, 1);
	 push(linkedListToRemove, 1);

	 print(linkedListToRemove);

	 removeAll(linkedListToRemove, 1);

	 print(linkedListToRemove);
 }

 void testApend()
 {
	 Box<int> * linkedList1;
	 linkedList1 = nullptr; 
	 Box<int> * linkedList2;
	 linkedList2 = nullptr;

	 testMakeLinkedList(linkedList1);
	 testMakeLinkedList(linkedList2);

	 append(linkedList1, linkedList2);

	 print(linkedList1);
 }

 void testConcat()
 {
	 Box<int> * linkedList1;
	 linkedList1 = nullptr;
	 Box<int> * linkedList2;
	 linkedList2 = nullptr;

	 testMakeLinkedList(linkedList1);
	
	 push(linkedList2, 20);
	 push(linkedList2, 30);
	 push(linkedList2, 40);

	 print(concat(linkedList1, linkedList2));
 }

 template <typename T>
 void testMap(Box<T> * & first)
 {
	 testMakeLinkedList(first);
	 map(first);
	 print(first);
 }

 template <typename T>
 void testReverse(Box<T> * & first)
 {
	 reverse(first);
	 print(first);
 }

 void testDublicate()
 {
	 Box<int> * linkedList;
	 linkedList = nullptr;

	 testMakeLinkedList(linkedList);

	 pushBack(linkedList, 1);
	 pushBack(linkedList, 2);
	 pushBack(linkedList, 20);
	 pushBack(linkedList, 30);

	 print(linkedList);

	 std::cout<<duplicate(linkedList)<<std::endl;
 }

 void testSorted()
 {
	 Box<int> * linkedList;
	 linkedList = nullptr;

	 testMakeLinkedList(linkedList);

	 pushBack(linkedList, 50);
	 pushBack(linkedList, 20);

	 print(linkedList);

	 std::cout << issorted(linkedList) << std::endl;
 }

 void testRemoveDoblicates()
 {
	 Box<int> * linkedList;
	 linkedList = nullptr;

	 pushBack(linkedList, 1);
	 pushBack(linkedList, 2); 
	 pushBack(linkedList, 3);
	 pushBack(linkedList, 2); 
	 pushBack(linkedList, 2);
	 pushBack(linkedList, 4); 
	 pushBack(linkedList, 5);
	 pushBack(linkedList, 2); 
	 pushBack(linkedList, 6);
	 pushBack(linkedList, 7);

	 print(linkedList);

	 remuveDuplicate(linkedList);

	 print(linkedList);
 }

int main()
{
	Box<int> * linkedList;
	linkedList = nullptr;

	//testMakeLinkedList(linkedList);
	//testIterationOfTheElements(linkedList);
	//testRange(linkedList);
	//testRemuveAll();
	//testApend();
	//testConcat();
	//testMap(linkedList);
	//testReverse(linkedList);
	//testDublicate();
	//testSorted();
	//testRemoveDoblicates();

	system("pause");
    return 0;
}

