#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Person
{
	string firstName;
	string lastName;
};

Person init_person(string fname, string lname)
{
	Person p;
	p.firstName = fname;
	p.lastName = lname;
	return p;
}

void print_person(Person& p)
{
	cout << setw(20) << "First name: ";
	cout << setw(20) << p.firstName;
	cout << endl;

	cout << setw(20) << "Last name: ";
	cout << setw(20) << p.lastName;
	cout << endl << endl;
}

struct Client
{
	Person client;
	double amount;
};

Client init_client(Person& p, double amount)
{
	Client c;
	c.client.firstName = p.firstName;
	c.client.lastName = p.lastName;
	c.amount = amount;
	return c;
}

void print_client(Client& c)
{
	cout << setw(20) << "Client: ";
	cout << setw(20) << c.client.firstName << " " << c.client.lastName;
	cout << endl;

	cout << setw(20) << "Amount: ";
	cout << setw(20) << c.amount;
	cout << endl << endl;
}

int main()
{
	/*
	Person p = init_person("Rado", "Rado");

	print_person(p);

	Client c = init_client(p, 6969);

	print_client(c);

	string fname;

	getline(cin, fname);

	cout << fname << endl;
	*/

	int numberOfClients;

	cout << "Enter number between 1 and 20, which is number of clients that you want to enter: ";
	cin >> numberOfClients;

	Client clients[20];

	for (int i = 0; i < numberOfClients; ++i)
	{
		string firstName, lastName;

		cout << "Enter first name and last name: ";
		getline(cin, firstName);
		getline(cin, lastName);

		double amount;
		cout << "Enter amount: ";
		cin >> amount;

		clients[i].client = init_person(firstName, lastName);
		clients[i].amount = amount;
	}

	for (int i = 0; i < numberOfClients; ++i)
	{
		print_client(clients[i]);
	}


	double S = 0;
	for (int i = 0; i < numberOfClients; ++i)
	{
		if(clients[i].amount < 0) S += clients[i].amount;
	}

	cout << "Sum of obligations is: " << S << endl;

	return 0;
}