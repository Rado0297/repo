#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream f("numbers.txt", ios::in);

	if (!f)
	{
		cerr << "File cannot be open!\n";
		return 1;
	}

	char ch;
	while(!f.eof())
	{
		f.get(ch);
		if (!f.good() && !f.eof())
		{
			cout << "I/O error! Process has been intrrupted!\n";
			return 1;
		}

		cout << ch;
	}

	return 0;
}