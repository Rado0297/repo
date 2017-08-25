#include <iostream>

using namespace std;

class Imperial
{
private:
	int theYards, theFeet, theInches;

public:
	Imperial(int aYard = 0, int aFoot = 0, int anInch = 0);
	void add(const Imperial&);
	void mult(int);

	int yards() const;
	int feet() const;
	int inches() const;

	void print();
};

Imperial::Imperial(int aYard, int aFoot, int anInch)
{
	theYards = aYard;
	theFeet = aFoot;
	theInches = anInch;
}

void Imperial::add(const Imperial& obj)
{
	//3 feet == 1 yard, 12 inches == 1 foot
	theFeet += theYards * 3;
	theYards = 0;

	theInches += theFeet * 12;
	theFeet = 0;

	Imperial temp;

	temp.theFeet += obj.theYards * 3;
	temp.theYards = 0;

	temp.theInches += obj.theFeet *12;
	temp.theFeet = 0;

	theInches += obj.theInches;

	theFeet = theInches / 12;
	theInches = theInches % 12;
	theYards = theFeet / 3;
	theFeet = theFeet % 3;
}

void Imperial::mult(int number)
{
	//3 feet == 1 yard, 12 inches == 1 foot
	if (theYards == 0)
	{
		if (theFeet == 0)
		{
			theInches *= number;
		}

		else if (theFeet != 0)
		{
			theInches += theFeet * 12;
			theFeet = 0;
			theInches *= number;
		}
	}

	else if (theYards != 0)
	{
		theFeet += theYards * 3;
		theYards = 0;

		theInches += theFeet * 12;
		theFeet = 0;

		theInches *= number;
	}

	theFeet = theInches / 12;
	theInches = theInches % 12;
	theYards = theFeet / 3;
	theFeet = theFeet % 3;
}

int Imperial::yards() const
{
	return theYards;
}

int Imperial::feet() const
{
	return theFeet;
}

int Imperial::inches() const
{
	return theInches;
}

void Imperial::print()
{
	cout << theYards << " " << theFeet << " " << theInches << endl;
}

int main()
{
	Imperial len1(1, 1, 1), len2(0, 0, 0), len3(7, 6, 11), len4(0, 1, 0), len5(0, 0, 8);


	len4.add(len5);
	len4.print();

	len1.add(len2);

	len1.print();

	len1.add(len2);
	len1.print();

	len1.mult(1);
	len1.print();

	len1.add(len3);
	len1.print();

	len1.mult(3);
	len1.print();

	len3.mult(1);
	len3.print();

	return 0;
}