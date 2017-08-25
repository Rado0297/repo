#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MaxLengthName = 30;
const int PATIENTS = 100;

class Date
{
private:
	int theDay, theMonth, theYear;

public:
	Date(int = 1, int = 1, int = 2000);
	int Day() const;
	int Month() const;
	int Year() const;

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	void print() const;
};

Date::Date(int d, int m, int y)
{
	theDay = d;
	theMonth = m;
	theYear = y;
}

int Date::Day() const
{
	return theDay;
}

int Date::Month() const
{
	return theMonth;
}

int Date::Year() const
{
	return theYear;
}

void Date::setDay(int d)
{
	theDay = d;
}

void Date::setMonth(int m)
{
	theMonth = m;
}

void Date::setYear(int y)
{
	theYear = y;
}

void Date::print() const
{
	cout << theDay << "." << theMonth << "." << theYear << endl;
}

const Date DATE(1, 1, 1990);

class Person
{
private:
	char* name;
	Date DOB;

public:
	Person(const char* = "", const Date& = DATE);
	Person(const Person&);
	Person& operator=(const Person&);
	~Person();

	const char* getName() const;
	Date getDOB() const;
	void print() const;
};

Person::Person(const char* n, const Date& d)
{
	name = new char[strlen(n) + 1];
	if (!name)
	{
		cout << "Error while allocating memory for name of the person!\n";
		exit(1);
	}
	strcpy(name, n);
	DOB = d;
}

Person::Person(const Person& p)
{
	name = new char[strlen(p.name) + 1];
	if (!name)
	{
		cout << "Error while allocating memory for name of the person!\n";
		exit(1);
	}
	strcpy(name, p.name);
	DOB = p.DOB;
}

Person& Person::operator=(const Person& p)
{
	if (this != &p)
	{
		delete [] name;
		name = new char[strlen(p.name) + 1];
		if (!name)
		{
			cout << "Error while allocating memory for name of the person!\n";
			exit(1);
		}
		strcpy(name, p.name);
		DOB = p.DOB;
	}

	return *this;
}

Person::~Person()
{
	delete [] name;
}

const char* Person::getName() const
{
	return name;
}

Date Person::getDOB() const
{
	return DOB;
}

void Person::print() const
{
	cout << name << " ";
	DOB.print();
}

class Patient : public Person
{
private:
	int visits;

public:
	Patient(char* n = "", Date = DATE, int = 0);
	int getVisits() const;
	void print() const;
};

Patient::Patient(char* n, Date d, int v) : Person(n, d)
{
	visits = v;
}

int Patient::getVisits() const
{
	return visits;
}

void Patient::print() const
{
	Person::print();
	cout << "Visits: " << visits << endl;
}

class Doctor : public Person
{
private:
	Patient* PatientsList;
	int PatientsRegistered;
	static int Registered;

public:
	Doctor(char* = "", const Date& = DATE, int = 0);
	Doctor(const Doctor&);
	Doctor& operator=(const Doctor&);
	~Doctor();

	void registerPatient(const Patient&);
	double average() const;
	void printUpper(int) const;

};

int Doctor::Registered = 0;

Doctor::Doctor(char* n, const Date& d, int reg) : Person(n, d)
{
	PatientsRegistered = reg;
	PatientsList = new Patient[PatientsRegistered];
	if (!PatientsList)
	{
		cout << "Error while allocating memory for PatientsList!\n";
		exit(1);
	}	
}

Doctor::Doctor(const Doctor& d1)
{
	PatientsRegistered = d1.PatientsRegistered;
	PatientsList = new Patient[PatientsRegistered];
	if (!PatientsList)
	{
		cout << "Error while allocating memory for PatientsList!\n";
		exit(1);
	}

	for (int i = 0; i < PatientsRegistered; ++i)
	{
		PatientsList[i] = d1.PatientsList[i];
	}
}

Doctor& Doctor::operator=(const Doctor& d1)
{
	if (this != &d1)
	{
		Person::operator=(d1);
		PatientsRegistered = d1.PatientsRegistered;
		delete [] PatientsList;
		PatientsList = new Patient[PatientsRegistered];
		if (!PatientsList)
		{
			cout << "Error while allocating memory for PatientsList!\n";
			exit(1);
		}

		for (int i = 0; i < PatientsRegistered; ++i)
		{
			PatientsList[i] = d1.PatientsList[i];
		}	
	}

	return *this;
}

Doctor::~Doctor()
{
	delete [] PatientsList;
}

void Doctor::registerPatient(const Patient& p1)
{
	PatientsList[Registered] = p1;
	Registered++;
}

double Doctor::average() const
{
	double sum = 0.0;

	for (int i = 0; i < PatientsRegistered; ++i)
	{
		sum += PatientsList[i].getVisits();
	}

	if (PatientsRegistered != 0)
		return sum/PatientsRegistered;

	else
		return 0;
}
	
void Doctor::printUpper(int n) const
{
	cout << "Patients with visits that are over the limit!\n";
	for (int i = 0; i < PatientsRegistered; ++i)
	{
		if (PatientsList[i].getVisits() > n)
		{
			PatientsList[i].print();
		}
	}
}

int main()
{
	int n;

	do
	{
		cout << "Count of patients: ";
		cin >> n;
	} while(n < 0 || n > PATIENTS);

	Date DOB_Petrov(5, 10, 1975);

	Doctor d1("Petrov", DOB_Petrov, n);

	for (int i = 0; i < n; ++i)
	{
		cin.ignore();
		cout << "Name of patient: ";
		char NamePatient[MaxLengthName];
		cin.getline(NamePatient, MaxLengthName+1);
		int d, m, y;
		cout << "day: ";
		cin >> d;
		cout << "month: ";
		cin >> m;
		cout << "year: ";
		cin >> y;
		Date dat(d, m, y);
		int vis;
		cout << "Enter count of visits: ";
		cin >> vis;
		Patient P(NamePatient, dat, vis);
		d1.registerPatient(P);
	}

	cout << "Average visits per month: " << d1.average() << endl;

	if (n > 0)
	{
		d1.printUpper(3);
	}

	return 0;
}