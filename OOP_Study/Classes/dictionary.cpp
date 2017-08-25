#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

const int MaxLenWord1 = 15;
const int MaxLenWord2 = 15;
const int MaxPairs = 300;

int printVariable = 0;

class Pair
{
private:
	char wordLan1[MaxLenWord1+1];
	char wordLan2[MaxLenWord2+1];

public:
	Pair();
	void print() const;
	void insert(const char*, const char*);
	bool equal(const char* k) const;
	bool reverseEqual(const char* k) const;
};

Pair::Pair()
{
	strcpy(wordLan1, "");
	strcpy(wordLan2, "");
}

void Pair::insert(const char* c1, const char* c2)
{
	strcpy(wordLan1, c1);
	strcpy(wordLan2, c2);
}

bool Pair::equal(const char* k) const
{
	printVariable = 1;
	return strcmp(wordLan1, k) == 0;
}

bool Pair::reverseEqual(const char* k) const
{
	printVariable = 2;
	return strcmp(wordLan2, k) == 0;
}

void Pair::print() const
{
	if (printVariable == 1)
	{
		cout << "1) "<< wordLan1 << " - " << wordLan2 << endl;
	}

	if (printVariable == 2)
	{
		cout << "2) "<< wordLan2 << " - " << wordLan1 << endl;
	}

	else
	{
		cout << "3) " << wordLan1 << " - " << wordLan2 << endl;
	}
}


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

void Dictionary::insert(const char* w1, const char* w2)
{
	if (count < MaxPairs)
	{
		pairs[count++].insert(w1, w2);
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
		if (pairs[i].reverseEqual(w))
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


int main()
{
	Dictionary d;
	d.insert("pixel", "пиксел");
	d.insert("diode", "диод");
	d.insert("recursion", "рекурсия");
	d.insert("computer", "компютър");
	d.insert("monitor", "монитор");

	d.print();
	cout << endl;

	cout << "Use of operator []\n";
	d["diode"];
	d["monitor"];

	cout << "============= Reverse Equal ===================\n";

	cout << "Error: 3) shouldn't be shown"

	d["монитор"];

	return 0;
}