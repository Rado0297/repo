#include <iostream>
#include <iomanip>

using namespace std;

int lengthOfName(const char *name)
{
	int i = 0;
	while(name[i] != '\0')
	{
		i++;
	}

	return i;
}

struct Name
{
	char first_name[20];
	char last_name[20];
};

struct Work
{
	int hours;
	int salary;
};

class Employee
{
	Name name;
	Work work;

public:
	void read(char *fn, char *ln, int h, int s);
	void print() const;
};

void Employee::read(char *fn, char *ln, int h, int s)
{
	for (int i = 0; i < 20; ++i)
	{
		name.first_name[i] = 0;
		name.last_name[i] = 0;
	}

	for (int i = 0; i < lengthOfName(fn); ++i)
	{
		name.first_name[i] = fn[i];
	}

	for (int i = 0; i < lengthOfName(ln); ++i)
	{
		name.last_name[i] = ln[i];
	}

	work.hours = h;
	work.salary = s;
}

void Employee::print() const
{
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << name.first_name << " " << name.last_name << " " << work.hours * work.salary << endl;
}

int main()
{
	Employee e;

	char fname[20] = {'R','a','d','o','s','l','a','v'};
	char lname[20] = {'R','a','d','k','o','v'};

	e.read(fname, lname, 8, 10);

	e.print();

	return 0;
}