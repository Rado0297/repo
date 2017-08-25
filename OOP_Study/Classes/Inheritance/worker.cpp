#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 50;

class Worker
{
private:
	char* name;
	double salary;

public:
	Worker(const char* = "", double = 0.0);
	Worker(const Worker&);
	Worker& operator=(const Worker&);
	~Worker();

	void print() const;
	double get_salary() const;
};

Worker::Worker(const char* c, double sal)
{
	name = new char[strlen(c) + 1];
	if (!name)
	{
		cout << "Error while allocating memory for name!\n";
		exit(1);
	}

	strcpy(name, c);
	salary = sal;
}

Worker::Worker(const Worker& w1)
{
	name = new char[strlen(w1.name) + 1];
	if (!name)
	{
		cout << "Error while allocating memory for name!\n";
		exit(1);
	}

	strcpy(name, w1.name);
	salary = w1.salary;	
}

Worker& Worker::operator=(const Worker& w)
{
	if (this != &w)
	{
		delete [] name;
		name = new char[strlen(w.name) + 1];
		if (!name)
		{
			cout << "Error while allocating memory for name!\n";
			exit(1);
		}

		strcpy(name, w.name);
	}

	return *this;
}

Worker::~Worker()
{
	delete [] name;
}

void Worker::print() const
{
	cout << setw(20) << name << setw(18) << salary;
}

double Worker::get_salary() const
{
	return salary;
}

class HourlyWorker : public Worker
{
private:
	char* work;
	int hours;

public:
	HourlyWorker(const char* = "", double = 0.0, const char* wk = "", int h = 0);
	HourlyWorker(const HourlyWorker&);
	HourlyWorker& operator=(const HourlyWorker&);
	~HourlyWorker();

	double WeekSalary() const;
	void print() const; 
};

HourlyWorker::HourlyWorker(const char* n, double sal, const char* wk, int h) : Worker(n, sal)
{
	work = new char[strlen(wk) + 1];
	if (!work)
	{
		cout << "Error while allocating memory for work kind!\n";
		exit(1);
	}

	strcpy(work, wk);
	hours = h;
}

HourlyWorker::HourlyWorker(const HourlyWorker& w)
{
	work = new char[strlen(w.work) + 1];
	if (!work)
	{
		cout << "Error while allocating memory for work kind!\n";
		exit(1);
	}
	strcpy(work, w.work);
	hours = w.hours;
}

HourlyWorker& HourlyWorker::operator=(const HourlyWorker& w)
{
	if (this != &w)
	{
		Worker::operator=(w);

		delete [] work;
		work = new char[strlen(w.work) + 1];
		if (!work)
		{
			cout << "Error while allocating memory for work kind!\n";
			exit(1);
		}

		strcpy(work, w.work);
		hours = w.hours;
	}

	return *this;
}

HourlyWorker::~HourlyWorker()
{
	delete [] work;
}

double HourlyWorker::WeekSalary() const
{
	double x, y = get_salary();
	if (hours <= 40 )
	{
		x = hours * y;
	}
	else
	{
		if (hours <= 60)
		{
			x = 40 * y + (hours-40)*1.5*y;
		}
		else
		{
			x = 40*y + 20*1.5*y + (hours-60)*2*y;
		}
	}

	return x;
}

void HourlyWorker::print() const
{
	Worker::print();
	cout << setw(10) << hours << setw(20) << work << setw(10) << WeekSalary() << endl;
}

class SalariedWorker : public Worker
{
private:
	char* work;
	int hours;

public:
	SalariedWorker(const char* = "", double = 0.0, const char* = "", int = 0);
	SalariedWorker(const SalariedWorker&);
	SalariedWorker& operator=(const SalariedWorker&);
	~SalariedWorker();

	double WeekSalary() const;
	void print() const;
};

SalariedWorker::SalariedWorker(const char* n, double sal, const char* wk, int h) : Worker(n, sal)
{
	work = new char[strlen(wk) + 1];
	if (!work)
	{
		cout << "Error while allocating memory for work kind!\n";
		exit(1);
	}
	strcpy(work, wk);
	hours = h;
}

SalariedWorker::SalariedWorker(const SalariedWorker& w)
{
	work = new char[strlen(w.work) + 1];
	if (!work)
	{
		cout << "Error while allocating memory for work kind!\n";
		exit(1);
	}

	strcpy(work, w.work);
	hours = w.hours;
}

SalariedWorker& SalariedWorker::operator=(const SalariedWorker& w)
{
	if (this != &w)
	{
		Worker::operator=(w);
		delete [] work;
		work = new char[strlen(w.work) + 1];
		if (!work)
		{
			cout << "Error while allocating memory for work kind!\n";
			exit(1);
		}
		strcpy(work, w.work);
		hours = w.hours;
	}

	return *this;
}

SalariedWorker::~SalariedWorker()
{
	delete [] work;
}

double SalariedWorker::WeekSalary() const
{
	return 40 * get_salary();
}

void SalariedWorker::print() const
{
	cout << setw(10) << hours << setw(20) << work << setw(10) << WeekSalary() << endl;
}

void Create_HourlyWorker_arr(int m, HourlyWorker**& arr)
{
	cout << "Create array with data about hourly workers\n";

	arr = new HourlyWorker*[m];
	if (!arr)
	{
		cout << "Error while allocating memory for hourly workers array with data!\n";
		exit(1);
	}

	for (int i = 0; i < m; ++i)
	{
		char n[MAX_SIZE];
		cout << "Name: ";
		cin.getline(n, MAX_SIZE);

		double s;
		cout << "Enter salary per hour: ";
		cin >> s;

		cin.ignore();
		char w[MAX_SIZE];
		cout << "Work kind: ";
		cin.getline(w, MAX_SIZE);

		int h;
		cout << "Enter count of hours: ";
		cin >> h;

		cin.ignore();

		arr[i] = new HourlyWorker(n, s, w, h);
		if (!arr)
		{
			cout << "Error while allocating memory for array with data about hourly workers!\n";
			exit(1);
		}
	}
}

void Print_HourlyWorker_arr(int n, HourlyWorker** arr)
{
	cout << "List with hourly workers:\n";
	cout << setw(20) << "Name"
		<< setw(12) << "Salary per hour"
		<< setw(10) << "Hours"
		<< setw(20) << "Work kind"
		<< setw(10) << "Salary\n";

	for (int i = 0; i < n; ++i)
	{
		arr[i]->print();
	}
}

void Sort_HourlyWorker_arr(int n, HourlyWorker** arr)
{
	for (int i = 0; i < n-1; ++i)
	{
		int k = i;
		double max = arr[i]->WeekSalary();
		for (int j = i+1; j < n; j++)
		{
			if (arr[i]->WeekSalary() > max)
			{
				max = arr[i]->WeekSalary();
				k = j;
			}
		}

		HourlyWorker* ptr = arr[i];
		arr[i] = arr[k];
		arr[k] = ptr;
	}
}

void Delete_HourlyWorker_arr(int n, HourlyWorker** arr)
{
	for (int i = 0; i < n; ++i)
	{
		delete arr[i];
	}

	delete [] arr;
}

void Create_SalariedWorker_arr(int m, SalariedWorker**& arr)
{
	cout << "Create salaried worker list:\n";
	arr = new SalariedWorker*[m];
	if (!arr)
	{
		cout << "Error while allocating memory for salaried workers list!\n";
		exit(1);
	}

	for (int i = 0; i < m; ++i)
	{
		char n[MAX_SIZE];
		cout << "Enter name: ";
		cin.getline(n, MAX_SIZE);

		double s;
		cout << "Salary per hour: ";
		cin.ignore();
		char w[MAX_SIZE];
		cout << "Enter work kind: ";
		cin.getline(w, MAX_SIZE);

		int h;
		cin >> h;
		cin.ignore();
		arr[i] = new SalariedWorker(n, s, w, h);
		if (!arr)
		{
			cout << "Error while allocating memory for salaried work object!\n";
			exit(1);
		}
	}
}

void Print_SalariedWorker_arr(int m, SalariedWorker** arr)
{
	cout << "List of salaried workers:\n";
	cout << setw(10) << "Name"
		<< setw(12) << "Salary per hour"
		<< setw(10) << "Hours"
		<< setw(20) << "Work kind"
		<< setw(10) << "Salary\n";

	for (int i = 0; i < m; ++i)
	{
		arr[i]->print();
	}
}

void Sort_SalariedWorker_arr(int n, SalariedWorker** arr)
{
	for (int i = 0; i < n-1; ++i)
	{
		int k = 0;
		double max = arr[i]->WeekSalary();
		for (int j = i+1; j < n; j++)
		{
			if (arr[i]->WeekSalary() > max)
			{
				max = arr[i]->WeekSalary();
				k = j;
			}

			SalariedWorker* ptr = arr[i];
			arr[i] = arr[k];
			arr[k] = ptr;
		}
	}
}

void Delete_SalariedWorker_arr(int n, SalariedWorker** arr)
{
	for (int i = 0; i < n; ++i)
	{
		delete arr[i];
	}

	delete [] arr;
}

int main()
{
	int n;
	cout << "Count of hourly workers: ";
	cin >> n;

	cin.ignore();

	HourlyWorker** hourly_arr = NULL;
	Create_HourlyWorker_arr(n, hourly_arr);
	Print_HourlyWorker_arr(n, hourly_arr);

	int m;
	cout << "Count of salaried workers: ";
	cin >> m;

	cin.ignore();

	SalariedWorker** salaried_arr = NULL;
	Create_SalariedWorker_arr(m, salaried_arr);
	cout << endl;

	Print_SalariedWorker_arr(m, salaried_arr);
	
	Sort_HourlyWorker_arr(n, hourly_arr);
	Print_HourlyWorker_arr(n, hourly_arr);

	Sort_SalariedWorker_arr(m, salaried_arr);
	Print_SalariedWorker_arr(m, salaried_arr);

	Delete_HourlyWorker_arr(n, hourly_arr);
	Delete_SalariedWorker_arr(m, salaried_arr);

	return 0;
}