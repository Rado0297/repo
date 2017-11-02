#include <iostream>
#include <assert.h>

template <typename T = int>
struct list
{
	T value;
	list<T>* pointer;	
};

template <typename T>
class LList
{
private:
	list<T>* start, *end, *current;

	void copyList(const LList&);
	void deleteList();

public:
	LList();
	LList(const LList&);
	LList& operator=(const LList&);
	~LList();

	bool empty();
	void iterStart(list<T>*);
	list<T>* iter();
	void toEnd(const T&);
	void insertAfter(list<T>*, const T&);
	void insertBefore(list<T>*, const T&);
	void deleteAfter(list<T>*, T&);
	void deleteBefore(list<T>*, T&);
	void deleteElem(list<T>*, T&);
	void print() const;
	int length() const;
	void concat(const list<T>&);
	void reverse();
};

//Big fourth
template <typename T>
LList<T>::LList()
{
	start = end = nullptr;
}

template <typename T>
LList<T>::LList(const LList<T>& r)
{
	copyList(r);
}

template <typename T>
LList<T>& LList<T>::operator=(const LList<T>& r)
{
	if (this != r)
	{
		deleteList();
		copyList(r);
	}

	return *this;
}

template <typename T>
LList<T>::~LList()
{
	deleteList();
}
//

//Private functions
template <typename T>
void LList<T>::copyList(const LList<T>& r)
{
	list<T> *newStart = r.start, *newEnd;
	if (r.start != nullptr)
	{
		start = new list<T>;
		assert(start != NULL);
		end = start;
		while (newStart != nullptr)
		{
			end->value = newStart->value;
			end->pointer = nullptr;
			newStart = newStart->pointer;
			if (newStart != nullptr)
			{
				newEnd = end;
				end = new list<T>;
				assert(end != nullptr);
				newEnd->pointer = end;
			}
		}
	}

	else
	{
		start = end = nullptr;
	}
}

template <typename T>
void LList<T>::deleteList()
{
	list<T> *p;
	while (start != nullptr)
	{
		p = start;
		start = start->pointer;
		delete p;
	}

	end = nullptr;
}

//Other functions

//initialize iterator of list
template <typename T>
void LList<T>::iterStart(list<T>* p)
{
	if (p != nullptr)
	{
		current = p;
	}

	else
	{
		current = start;
	}
}

//return current and go to next position
template <typename T>
list<T>* LList<T>::iter()
{
	list<T> *p = current;
	if (current != nullptr)
	{
		current = current->pointer;
	}

	return p;
}

//add element to the end of the list
template <typename T>
void LList<T>::toEnd(const T& x)
{
	list<T> *p = end;
	end = new list<T>;
	assert(end != nullptr);
	end->value = x;
	end->pointer = nullptr;
	if (p != nullptr)
	{
		p->pointer = end;
	}

	else start = end;
}

//insert element after the given. for examle 1 2 3, insert element 11 after 2. Result: 1 2 11 3
template <typename T>
void LList<T>::insertAfter(list<T> *p, const T& x)
{
	list<T> *q = new list<T>;
	assert(q != nullptr);
	q->value = x;
	q->pointer = p->pointer;
	if (p == end)
	{
		end = q;
	}

	p->pointer = q;
}

//insert element before the given. for examle 1 2 3, insert element 11 before 2. Result: 1 11 2 3
template <typename T>
void LList<T>::insertBefore(list<T> *p, const T& x)
{
	list<T> *q = new list<T>;
	assert(q != nullptr);
	*q = *p;
	if (p == end)
	{
		end = p;
	}
}

//delete after given position
template <typename T>
void LList<T>::deleteAfter(list<T> *p, T& x)
{
	if (p->pointer != nullptr)
	{
		list<T> *q = p->pointer;
		x = q->value;
		p->pointer = q->pointer
		if (q == end)
		{
			end = p;
		}
		delete q;
	}

	else
	{
		std::cout << "There is not element after p.\n";
		exit(1);
	}
}

//delete given position
template <typename T>
void LList<T>::deleteElem(list<T> *p, T& x)
{
	if (p == start)
	{
		x = p->value;
		if (start == end)
		{
			start = end = nullptr;
		}
		else
		{
			start = start->pointer;
		}
		delete p;
	}

	else
	{
		list<T> *q = start;
		while (q->pointer != p)
		{
			q = q->pointer;
		}

		deleteAfter(q, x);
	}
}

//delete before given position
template <typename T>
void LList<T>::deleteBefore(list<T> *p, T& x)
{
	if (p != start)
	{
		list<T> *q = start;
		while (q->pointer != p)
		{
			q = q->pointer;
		}

		deleteElem(q, x);
	}

	else
	{
		std::cout << "There is not an element before p.\n";
		exit(1);
	}
}

template <typename T>
bool LList<T>::empty() const
{
	return start == nullptr;
}

template <typename T>
void LList<T>::print() const
{
	list<T> *p = start;
	while (p != nullptr)
	{
		std::cout << p->value << " ";
		p = p->pointer;
	}

	std::cout << std::endl;
}

template <typename T>
int LList<T>::length() const
{
	int len = 0;
	list<T> *p = start;

	while(p != nullptr)
	{
		len++;
		p = p->pointer;
	}

	return len;
}

template <typename T>
void LList<T>::concat(const list<T>& r)
{
	list<T> *p = r.start;
	while (p != nullptr)
	{
		toEnd(p->value);
		p = p->pointer;
	}
}

template <typename T>
void LList<T>::reverse()
{
	list<T> *p, *q, *temp;
	p = start;
	if (p != nullptr)
	{
		q = nullptr;
		temp = start;
		start = end;
		end = temp;
	}

	while (p != start)
	{
		temp = p->pointer;
		q = p;
		p = temp;
	}

	p->pointer = q;
}

int main()
{


	return 0;
}