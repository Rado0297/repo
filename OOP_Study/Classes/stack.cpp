#include <iostream>

using namespace std;

const int MaxStack = 100;
const int FullStack = 100;
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
	void push(char c);
	char pop();
	bool empty() const;
	bool full() const;
	void print();
};

Stack::Stack()
{
	top = EmptyStack;
}

Stack::Stack(const Stack& s)
{
	top = s.top;
	for (int i = 0; i <= top; ++i)
	{
		items[i] = s.items[i];
	}
}

void Stack::push(char c)
{
	if(full())
	{
		cout << "Stack is full!\n";
		return;
	}
	items[++top] = c;
}

char Stack::pop()
{
	if(empty())
	{
		cout << "Stack is empty!\n";
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

int main()
{
	Stack s;
	s.push('a');
	s.push('b');
	s.push('c');

	Stack t = s;
		
	cout << "Stack s output:\n";
	s.print();

	if(!t.empty())
	{
		cout << t.pop() << endl;
	}

	cout << "Stack t output:\n";
	t.print();

	return 0;
}