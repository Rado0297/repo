#include <iostream>
#include <iomanip>

using namespace std;

struct Destination
{
	char city[32];
	int kilometers;
	void init_destination(char *city, int length, int km);
	void print_dest() const;
};

void Destination::init_destination(char *name, int length, int km)
{
	for (int i = 0; i < 32; ++i)
	{
		city[i] = 0;
	}
	for (int i = 0; i < length; ++i)
	{
		city[i] = name[i];
	}
	kilometers = km;
}

void Destination::print_dest() const
{
	cout << setw(20) << city << setw(20) << kilometers << endl;
}

int lengthOfName(const char *name)
{
	int i = 0;
	while(name[i] != '\0')
	{
		i++;
	}

	return i;
}

int main()
{
	Destination d2[2];

	
	int length;

	for (int i = 0; i < 2; ++i)
	{
		char city[32];
		int kilometers;
		
		cout << "Enter name of the city: ";
		cin >> city;

		cout << "kilometers away from Sofia: ";
		cin >> kilometers;

		length = lengthOfName(city);
		d2[i].init_destination(city, length, kilometers);
	}
	cout << endl;

	cout << setw(20) << "Destination" << setw(20) << "Kilometers" << endl;
	for (int i = 0; i < 2; ++i)
	{
		d2[i].print_dest();
	}

	Destination destinations[30];
	char null[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	for (int i = 0; i < 30; ++i)
	{
		destinations[i].init_destination(null, 0, 0);
	}

	for (int i = 0; i < 5; ++i)
	{

		char city[32];
		int kilometers;
		
		cout << "Enter name of the city: ";
		cin >> city;

		cout << "kilometers away from Sofia: ";
		cin >> kilometers;

		length = lengthOfName(city);
		destinations[i].init_destination(city, length, kilometers);
	}

	cout << endl << setw(20) << "Destination" << setw(20) << "Kilometers" << endl;
	for (int i = 0; i < 5; ++i)
	{
		destinations[i].print_dest();
	}

	return 0;
}