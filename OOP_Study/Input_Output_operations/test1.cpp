#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char data[100];

	ofstream outfile;
	outfile.open("afile.dat");

	cout << "Write to the file\n";
	cout << "Enter your name: ";
	cin.getline(data, 100);

	outfile << data << endl;

	cout << "Enter your age: ";
	cin >> data;
	cin.ignore();

	outfile << data << endl;
	outfile.close();

	ifstream infile;
	infile.open("afile.dat");

	cout << "Reading from the file\n";
	infile >> data;

	cout << data << endl;

	infile >> data;
	cout << data << endl;

	infile.close();

	return 0;
}