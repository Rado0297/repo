#include <iostream>
#include <iomanip>

using namespace std;

enum color {brown, green, orange, red, yellow};
enum yn {yes, no};

struct Fruit
{
	char name[32];
	color cl;
	yn annual;
	yn perennial;
	yn tropical;
};

void create_fruit(Fruit& f)
{
	cout << "Enter fruit name: ";
	cin >> f.name;

	cout << "Enter fruit color:\n";
	cout << "0 - brown\n";
	cout << "1 - green\n";
	cout << "2 - orange\n";
	cout << "3 - red\n";
	cout << "4 - yellow\n";
	int col;
	cin >> col;

	switch(col)
	{
		case 0: f.cl = color::brown; break;
		case 1: f.cl = color::green; break;
		case 2: f.cl = color::orange; break;
		case 3: f.cl = color::red; break;
		case 4: f.cl = color::yellow; break;
		default: cout << "Error occured!\n"; break; 
	}

	int an;
	cout << "Is this annual fruit?:\n";
	cout << "0 - no\n";
	cout << "1 - yes\n";
	cin >> an;
	switch(an)
	{
		case 0: f.annual = yn::no; break;
		case 1: f.annual = yn::yes; break;
		default: cout << "Error occured!\n"; break; 
	}

	int pre;
	cout << "Is this perennial fruit?:\n";
	cout << "0 - no\n";
	cout << "1 - yes\n";
	cin >> pre;
	switch(pre)
	{
		case 0: f.perennial = yn::no; break;
		case 1: f.perennial = yn::yes; break;
		default: cout << "Error occured!\n"; break; 
	}
	
	int tr;
	cout << "Is this tropical fruit?:\n";
	cout << "0 - no\n";
	cout << "1 - yes\n";
	cin >> tr;
	switch(tr)
	{
		case 0: f.tropical = yn::no; break;
		case 1: f.tropical = yn::yes; break;
		default: cout << "Error occured!\n"; break; 
	}
}

void print_fruit(const Fruit& f)
{
	if(f.cl == 0 && f.annual == 0 && f.perennial == 0 && f.tropical == 0)
	{		
		cout << f.name << ":\n"
				<< "color: brown" << endl
				<< "is it annual: no" << endl
				<< "is it perennial: no" << endl
				<< "is it tropical: no" << endl;

		...
	}
	else
	{
		cout << "Smth whet wrong!\n";
	}
/*

	cout << f.name << endl
	<< f.cl << endl
	<< f.annual << endl
	<< f.perennial << endl
	<< f.tropical << endl;*/
}

int main()
{
	Fruit f;

	create_fruit(f);
	print_fruit(f);


	return 0;
}