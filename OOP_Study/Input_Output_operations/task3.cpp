#include <iostream>
#include <fstream>

using namespace std;

void checkstatus(ifstream& f)
{
	int stat = f.rdstate();

	if (stat & ios::eofbit)
	{
		cout << "EOF is active!\n";
	}
	else if (stat & ios::failbit)
	{
		cout << "I/O error!\n";
	}
	else if (stat & ios::badbit)
	{
		cout << "Fatal I/O errror!\n";
	}
}

int main()
{
	ifstream f("numbers.txt", ios::in);

	if (!f)
	{
		cerr << "File can't be opened!\n";
		return 1;
	}

	char ch;
	while(f.get(ch))
	{
		cout << ch;
		checkstatus(f);
	}

	checkstatus(f);



	return 0;
}