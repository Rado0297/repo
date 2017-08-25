#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

const int MaxLenWord = 15;
const int MaxLenInterpret = 100;
const int MaxPairs = 300;

class Pair
{
private:
	char word[MaxLenWord + 1];
	char interpret[MaxLenInterpret + 1];

public:
	Pair();
	void print() const;
	void insert(const char*, const char*);
	bool equal(const char* k) const;
};

Pair::Pair()
{
	strcpy(word, "");
	strcpy(interpret, "");
}

void Pair::print() const
{
	cout << word << " - " << interpret << endl;
}

void Pair::insert(const char* w, const char* d)
{
	strcpy(word, w);
	strcpy(interpret, d);
}

bool Pair::equal(const char* w) const
{
	return strcmp(w, word) == 0;
}

class DictIter;

class Dictionary
{
private:
	friend class DictIter;
	Pair pairs[MaxPairs + 1];
	int count;

public:
	Dictionary()
	{
		count = 0;
	}

	void print() const;
	void insert(const char*, const char*);
	void remove(const char* w);
	void operator[](const char* w) const;
};


void Dictionary::print() const
{
	for (int i = 0; i < count; ++i)
	{
		pairs[i].print();
	}
}

void Dictionary::insert(const char* w, const char* d)
{
	if (count < MaxPairs)
	{
		pairs[count++].insert(w, d);
	}

	else
	{
		cout << count << "is not lower than MaxPairs!\n";
	}
}

void Dictionary::remove(const char* w)
{
	int i = 0;

	while(i < count - 1 && !pairs[i].equal(w))
		i++;

	if (pairs[i].equal(w))
	{
		for (int j = i + 1; j < count; ++j)
		{
			pairs[j-1] = pairs[j];
		}

		count--;
	}

	else
	{
		cout << w << " is not in the dictionary!\n";
	}
}
	
void Dictionary::operator[](const char* w) const
{
	int i = 0;
	while(i < count)
	{
		if (pairs[i].equal(w))
		{
			pairs[i].print();
			break;
		}
		else
		{
			i++;
		}
	}

	if (i == count)
	{
		cout << w << " is not in the dictionary!\n";
	}
}

class DictIter
{
private:
	int current;
	Dictionary* dict;

public:
	DictIter(Dictionary& d)
	{
		dict = &d;
		current = 0;
	}

	Pair* operator()();
};

Pair* DictIter::operator()()
{
	if (current >= dict->count)
	{
		return NULL;
	}

	return &dict->pairs[current++];
}

int main()
{
	Dictionary d;
	d.insert("pixel", "A pixel is the smallest piece of information in an image.");
	d.insert("diode", "A diode is a two-terminal device.");
	d.insert("recursion", "Recursion is a method of defining functions in which the function being defined is applied within its own definition.");
	d.insert("computer", "A computer is a machine that manipulates data according to a list of instructions.");
	d.insert("monitor", "A computer monitor is an eletronic device that shows pictures.");

	d.print();
	cout << endl;

	cout << "Use of operator []\n";
	d["diode"];
	d["monitor"];

	cout << "Use of operator ()\n";
	
	DictIter dint(d);
	
	Pair* ptr = NULL;

	while(ptr = dint())
	{
		ptr->print();
	}
	cout << endl;

	d.remove("diode");
	d.remove("monitor");
	d.print();
	cout << endl;

	return 0;
}