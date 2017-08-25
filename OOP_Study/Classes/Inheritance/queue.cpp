#include <iostream>

using namespace std;

const int MaxStack = 100;
const int FullStack = MaxStack;
const int EmptyStack = -1;
const char EmptyFlag = '\0';

class Stack
{
private:
	char items[MaxStack];
	int top;

public:
	Stack();
	Stack(const Stack&);
	void push(char);
	char pop();
	bool empty() const;
	bool full() const;
	void print();
};

Stack::Stack()
{
	top = EmptyStack;
}

Stack::Stack(const Stack& s1)
{
	top = s1.top;
	for (int i = 0; i <= top; ++i)
	{
		items[i] = s1.items[i];
	}
}

void Stack::push(char c)
{
	if (full())
	{
		cout << "Overloading!\n";
		return;
	}

	items[++top] = c;
}

char Stack::pop()
{
	if (empty())
	{
		cout << "There no elements!\n";
		return EmptyFlag;
	}

	return items[top--];
}

bool Stack::empty() const
{
	return top == EmptyStack;
}

bool Stack::full() const
{
	return top == FullStack - 1;
}

void Stack::print()
{
	for (int i = top; i >= 0; i--)
	{
		cout << pop() << endl;
	}
}

class Queue : private Stack
{
public:
	Queue();
	void add(const char&);
	void remove();
	char front();
	bool empty() const;
	bool full() const;
	int length();
	void print();
};

Queue::Queue()
{}

void Queue::add(const char& c)
{
	Stack s;
	while(!empty())
		s.push(pop());

	push(c);

	while(!s.empty())
		push(s.pop());
}

void Queue::remove()
{
	pop();
}

char Queue::front()
{
	char h = pop();
	push(h);
	return h;
}

bool Queue::empty() const
{
	return Stack::empty();
}

bool Queue::full() const
{
	return Stack::full();
}

int Queue::length()
{
	Stack s = *this;

	int n = 0;
	while(s.pop())
		n++;

	return n;
}

void Queue::print()
{
	Stack::print();
}

int main()
{
	Queue q1;

	cout << "Enter symbol row!\n" << "For end enter #.\n";

	while(!q1.full())
	{
		char ch;
		cout << "> ";
		cin >> ch;
		if(ch != '#')
		{
			q1.add(ch);
		}

		else
			break;
	}

	Queue q2 = q1;
	q1.print();

	while(!q2.empty())
	{
		cout << q2.front() << endl;
		q2.remove();
	}

	return 0;
}