#include <iostream>
#include <iomanip>

using namespace std;

struct Rectangular
{
	int length;
	int width;
};

void print_rect(Rectangular r)
{
	cout << setw(10) << "Length";
	cout << setw(10) << "Width" << endl;

	cout << setw(10) << r.length;
	cout << setw(10) << r.width << endl;
}

void init_rect(Rectangular& r)
{
	do
	{
		cout << "length: ";
		cin >> r.length;

		cout << "width: ";
		cin >> r.width;
	}
	while(r.length <=0 || r.width <=0);
}

Rectangular init_rect()
{
	Rectangular r;

	do
	{
		cout << "length: ";
		cin >> r.length;

		cout << "width: ";
		cin >> r.width;
	}
	while(r.length <=0 || r.width <=0);

	return r;
}

int main()
{
	Rectangular r = {10, 6};

	print_rect(r);

	init_rect(r);

	print_rect(r);

	print_rect(init_rect());

	return 0;
}