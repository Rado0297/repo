#include <iostream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

class Queue
{
private:
	char* Data;           //The actual data array
	const int MAX_NUM;    //The actual space will be one more than this
	int Beginning,        //Location of the start
		End;			  //Location of the end
	int ElemCount;

public:
	Queue(int MaxSize = 500);
	Queue(const Queue& OtherQueue);
	~Queue(void);

	void Enqueue(const char& Item); //Add item to queue end
	char Dequeue(void);             //Returns item from queue
	inline int ElemNum(void);       //Return number of elements
};

Queue::Queue(int MaxSize):MAX_NUM(MaxSize)
{
	Data = new char[MAX_NUM + 1];
	if (!Data)
	{
		cout << "Error while allocating memory about Data!\n";
		exit(1);
	}
	Beginning = 0;
	End = 0;
	ElemCount = 0;
}

Queue::Queue(const Queue& OtherQueue):MAX_NUM(OtherQueue.MAX_NUM)
{
	Beginning = OtherQueue.Beginning;
	End = OtherQueue.End;
	ElemCount = OtherQueue.ElemCount;

	Data = new char[MAX_NUM+1];
	if (!Data)
	{
		cout << "Error while allocating memory about Data!\n";
		exit(1);
	}

	for (int i = 0; i < MAX_NUM; ++i)
	{
		Data[i] = OtherQueue.Data[i];
	}
}

Queue::~Queue(void)
{
	delete [] Data;
}

void Queue::Enqueue(const char& Item)
{
	assert(ElemCount < MAX_NUM);

	Data[End++] = Item;
	++ElemCount;

	if (End > MAX_NUM)
	{
		End -= (MAX_NUM + 1);
	}
}

char Queue::Dequeue(void)
{
	assert(ElemCount > 0);

	char ReturnValue = Data[Beginning++];

	--ElemCount;

	if (Beginning > MAX_NUM)
	{
		Beginning -= (MAX_NUM + 1);
	}

	return ReturnValue;
}

inline int Queue::ElemNum(void)
{
	return ElemCount;
}

int main()
{
	Queue q1(10), q2(10), q3(10);

	for (int i = 0; i < 10; ++i)
	{
		q1.Enqueue(i+65);
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << q1.Dequeue() << endl;
	}

	return 0;
}