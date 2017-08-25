#include <iostream>
#include <string.h>
#include <stdlib.h>

const int MAX = 100;

using namespace std;

class BankAccount
{
private:
	char* name;
	char* accountnum;
	double balance;

public:
	//Constructor
	BankAccount(const char* = "", const char* = "", double = 0.0);

	//Assembler constructor - Конструктор за присвояване
	BankAccount(const BankAccount&);

	//Destructor
	~BankAccount();

	void print() const;
	void put_in(double);
	void draw(double);
};

BankAccount::BankAccount(const char* n, const char* an, double b)
{
	name = new char[strlen(n)+1];
	if(!name)
	{
		cout << "Error: Memory for name has not allocated!\n";
		exit(1);
	}
	strcpy(name, n);
	
	accountnum = new char[strlen(an)+1];
	if(!accountnum)
	{
		cout << "Error: Memory for accountnum has not allocated!\n";
		exit(1);
	}
	strcpy(accountnum, an);

	balance = b;
}

BankAccount::BankAccount(const BankAccount& b)
{
	name = new char[strlen(b.name)+1];
	if(!name)
	{
		cout << "Error: Memory for name has not allocated!\n";
		exit(1);
	}
	strcpy(name, b.name);
	
	accountnum = new char[strlen(b.accountnum)+1];
	if(!accountnum)
	{
		cout << "Error: Memory for accountnum has not allocated!\n";
		exit(1);
	}
	strcpy(accountnum, b.accountnum);

	balance = b.balance;
}

BankAccount::~BankAccount()
{
	delete [] name;
	delete [] accountnum;
}

void BankAccount::print() const
{
	cout << "Name: " << name << endl
	<< "Account number: " << accountnum << endl
	<< "Balance: " << balance << endl;
}

void BankAccount::put_in(double cash)
{
	if (cash >= 0)
	{
		balance += cash;
	}
	else
	{
		cout << "Incorrect operation: when you put in money you should enter number bigger than 0!\n";
	}
}

void BankAccount::draw(double cash)
{
	if (cash < 0)
	{
		cout << "Incorrect try for draw of money!\n";
	}
	else
	{
		if (cash <= balance)
		{
			balance -= cash;
		}
		else
		{
			cout << "Incorrect operation: Not enought balance for this transaction!\n";
		}
	}
}

int main()
{
	cout << "Name: ";
	char n1[MAX]; cin.getline(n1, MAX);

	cout << "Account number: ";
	char an1[MAX]; cin.getline(an1, MAX);

	cout << "Balance: ";
	double b1; cin >> b1;

	cin.ignore();

	BankAccount x(n1, an1, b1);
	x.print();
	x.put_in(200);
	x.print();

	cout << "Name: ";
	char n2[MAX]; cin.getline(n2, MAX);

	cout << "Account number: ";
	char an2[MAX]; cin.getline(an2, MAX);

	cout << "Balance: ";
	double b2; cin >> b2;

	cin.ignore();

	BankAccount y(n2, an2, b2);
	y.print();
	y.draw(250);
	y.print();

	return 0;
}