#include <iostream>
#include <fstream>

using namespace std;

const int MAX_PATH_SIZE = 256;

int main()
{
	char file_name[MAX_PATH_SIZE];

	ifstream file;
	cout << "Enter name of the file: ";
	cin.getline(file_name, MAX_PATH_SIZE);

	file.open(file_name, ios::in);
	if (file.fail())
	{
		cout << "File " << file_name << " does not exist!\n";
	}
	else
	{
		cout << "File " << file_name << " exist!\n";
	}

	file.close();

	return 0;
}