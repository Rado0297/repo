#include <iostream>
#include <string.h>

using namespace std;

class Date
{
private:
	int theDay;
	int theMonth;
	int theYear;
public:
	//Constructor
	Date(int = 1, int = 1, int = 1);
	
	//Getters
	int Day() const;
	int Month() const;
	int Year() const;

	//Setters
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

class Patient
{
private:
	char name[32];
	Date DOB;
	int Visits;

public:
	Patient();
	Patient(char *, const Date&, int);
	const char* getName() const;
	Date getDOB() const;
	int getVisits() const;
	void print() const;
};

Patient::Patient()
{
	Visits = 0;
}

Patient::Patient(char *n, const Date& date, int visits)
{
	strcpy(name, n);
	DOB = date;
	Visits = visits;
}

const char* Patient::getName() const
{
	return name;
}

Date Patient::getDOB() const
{
	return DOB;
}

int Patient::getVisits() const
{
	return Visits;
}

void Patient::print() const
{
	cout << "Name: " << name << endl
	<< "Date: ";
	DOB.print();
	cout << "Count of visits: " << Visits << endl;
}

class Doctor
{
private:
	char Name[32];
	Patient PatientsList[200];
	int PatientsRegistered;

public:
	Doctor(char *);
	const char* getName() const;
	void registerPatient(const Patient&);
	double average() const;
	void printUpper(int) const;
};

Doctor::Doctor(char *n)
{
	strcpy(Name, n);
	PatientsRegistered = 0;
}

const char* Doctor::getName() const
{
	return Name;
}

void Doctor::registerPatient(const Patient& P)
{
	PatientsList[PatientsRegistered] = P;
	PatientsRegistered++;
}

double Doctor::average() const
{
	int totalVisits = 0;

	for (int i = 0; i < PatientsRegistered; ++i)
	{
		totalVisits++;
	}

	if(PatientsRegistered != 0)
	{
		return double(totalVisits)/PatientsRegistered;
	}
	else
	{
		return 0;
	}
}

void Doctor::printUpper(int lim) const
{
	cout << "Patients with visits over the limit!\n";
	for (int i = 0; i < PatientsRegistered; ++i)
	{
		if(PatientsList[i].getVisits() > lim)
		{
			PatientsList[i].print();
		}
	}
}

int main()
{
	Doctor d1("Petrov");

	int n;
	do
	{
		cout << "Count of patients: ";
		cin >> n;
	} while (n < 0 || n > 200);

	for (int i = 0; i < n; ++i)
	{
		cin.ignore();
		cout << "Name of patients: ";
		char NamePatient[32];
		cin.getline(NamePatient, 33);
		
		int d, m, y;
		cout << "Day: "; cin >> d;
		cout << "Month: "; cin >> m;
		cout << "Year: "; cin >> y;
		Date dat(d, m, y);

		int vis;
		cout << "Count of visits: "; cin >> vis;

		Patient P(NamePatient, dat, vis);
		d1.registerPatient(P);
	}

	cout << "Average amount of visits: " << d1.average() << endl;

	if(n > 0) d1.printUpper(3);

	return 0;
}