#include <iostream>

using namespace std;

int nam = 0;
int accnam = 0;

int lengthOf(const char *name)
{
	int i = 0;
	while(name[i] != '\0')
	{
		i++;
	}

	return i;
}

class BankAccount
{
private:
	char name[24];
	char accNumber[16];
	double balance;

public:
	//create acc
	BankAccount(char *n, char *an, double bal);
	//print acc
	void print() const;
	//money in
	void putIn(double cash);
	//money out
	void putOut(double cash);
};

BankAccount::BankAccount(char *n, char *an, double bal)
{
	for (int i = 0; i < 24; ++i)
	{
		name[i] = '-';
	}
	for (int i = 0; i < 15; ++i)
	{
		accNumber[i] = '+';
	}

	for (int i = 0; i < lengthOf(n); ++i)
	{
		name[i] = n[i];
		nam++;
	}

	for (int i = 0; i < lengthOf(an); ++i)
	{
		accNumber[i] = an[i];
		accnam++;
	}

	balance = bal;
}

void BankAccount::print() const
{
	cout << "======================================================================================\n";
	for (int i = 0; i < nam; ++i)
	{
		cout << name[i];
	}
	cout << endl;

	for (int i = 0; i < accnam; ++i)
	{
		cout << accNumber[i];
	}
	cout << endl;
	cout << balance << endl;
	cout << "======================================================================================\n";
}

void BankAccount::putIn(double cash)
{
	balance += cash;
}

void BankAccount::putOut(double cash)
{
	balance -= cash;
}

int main()
{
	char n[24];
	char an[16];
	double bal;

	cin >> n;
	cin >> an;
	cin >> bal;

	BankAccount acc(n, an, bal);

	acc.print();

	int choise;
	cout << "Choose operation:\n"
	<< "Enter 1 to put in money\n" << "Enter 2 for put out money\n";
	cin >> choise;

	double cash;

	switch(choise)
	{
		case 1: cout << "Enter amount of money that you want to put in: "; cin >> cash; acc.putIn(cash); break;
		case 2: cout << "Enter amount of money that you want to put out: "; cin >> cash; acc.putOut(cash); break;
		default: cout << "Error! Transaction failed!\n";
	}

	acc.print();

	return 0;
}