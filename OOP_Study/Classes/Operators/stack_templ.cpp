#include <iostream>

using namespace std;

const int MaxStack = 100;
const int FullStack = MaxStack;
const int EmptyStack = -1;

template<class T>
class Stack
{
private:
	T items[MaxStack];
	int top;

public:
	Stack();
	Stack(const Stack&);

	void push(T c);
	T pop();

	bool empty() const;
	bool full() const;

	void print();
};

template<class T>
Stack<T>::Stack()
{
	top = EmptyStack;
}

template<class T>
Stack<T>::Stack(const Stack<T>& s)
{
	top = s.top;
	for (int i = 0; i <= top; ++i)
	{
		items[i] = s.items[i];
	}
}

template<class T>
void Stack<T>::push(T c)
{
	if (full())
	{
		cout << "Stack is full!\n";
		return;
	}

	items[++top] = c;
}

template<class T>
T Stack<T>::pop()
{
	if (empty())
	{
		cout << "Stack is empty!\n";
		return 0;
	}

	return items[top--];
}

template<class T>
bool Stack<T>::empty() const
{
	return top == EmptyStack;
}

template<class T>
bool Stack<T>::full() const
{
	return top == FullStack - 1;
}

template<class T>
void Stack<T>::print()
{
	for (int i = top; i >= 0; --i)
	{
		cout << pop() << endl;
	}
}

int main()
{
	Stack<char> s;

	s.push('a');
	s.push('b');
	s.push('c');

	Stack<char> t = s;
	s.print();

	if (!t.empty())
	{
		cout << t.pop() << endl;
	}

	t.print();

	return 0;
}