#include <iostream>
#include <string.h>

using namespace std;

class PersonalData
{
private:
	char* name;
	int birthYear;
	void copy(const PersonalData&);

public:
	PersonalData();
	PersonalData(const PersonalData&);
	PersonalData& operator=(const PersonalData&);
	~PersonalData();

	void read();
	void print() const;
};

PersonalData::PersonalData() : name(NULL), birthYear(0)
{}

PersonalData::PersonalData(const PersonalData& p) : name(NULL)
{
	copy(p);
}

PersonalData& PersonalData::operator=(const PersonalData& p)
{
	if (this != &p)
	{
		copy(p);
	}

	return *this;
}

PersonalData::~PersonalData()
{
	if (name != NULL)
	{
		delete [] name;
	}
}

void PersonalData::read()
{
	char nameTmp[255];
	cout << "Personal Name: ";
	cin >> nameTmp;

	if (name != NULL)
	{
		delete [] name;
	}

	name = new char[strlen(nameTmp) + 1];
	strcpy(name, nameTmp);
	cout << "Birth year: ";
	cin >> birthYear;
}

void PersonalData::print() const
{
	cout << "Name: " << name << endl
		<< "Birth year: " << birthYear << endl;
}

void PersonalData::copy(const PersonalData& p)
{
	if (name != NULL)
	{
		delete [] name;
	}

	name = NULL;
	if (p.name != NULL)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}

	birthYear = p.birthYear;
}

class Class
{
private:
	int year;
	int childrenCount;
	int classId;

public:
	Class();

	void read();
	void print() const;
};

Class::Class() : year(0), childrenCount(0), classId(0)
{}

void Class::read()
{
	cout << "Enter class: ";
	cin >> year;
	cout << "Enter count of children: ";
	cin >> childrenCount;
	cout << "Enter class id: ";
	cin >> classId;
}

void Class::print() const
{
	cout << "Class: " << year << endl
		<< "Count of children: " << childrenCount << endl
		<<	"Class id: " << classId << endl;
}

class Car
{
private:
	char* model;
	char registration[10];
	void copy(const Car&);

public:
	Car();
	Car(const Car&);
	Car& operator=(const Car&);
	~Car();

	void read();
	void print() const;
};

Car::Car() : model(NULL)
{}

Car::Car(const Car& c) : model(NULL)
{
	copy(c);
}

Car& Car::operator=(const Car& c)
{
	if (this != &c)
	{
		copy(c);
	}

	return *this;
}

Car::~Car()
{
	delete [] model;
}

void Car::read()
{
	char modelTmp[255];
	cout << "Enter model: ";
	cin >> modelTmp;
	if (model != NULL)
	{
		delete [] model;
	}

	model = new char[strlen(modelTmp) + 1];
	strcpy(model, modelTmp);
	cout << "Enter registration number: ";
	cin >> registration;
}

void Car::print() const
{
	cout << "Model: " << model << endl
		<< "Registration number: " << registration << endl;
}

void Car::copy(const Car& c)
{
	if (model != NULL)
	{
		delete [] model;
	}
	model = NULL;
	if (c.model != NULL)
	{
		model = new char[strlen(c.model) + 1];
		strcpy(model, c.model);
	}

	strcpy(registration, c.registration);
}

class Teacher : public PersonalData, public Class
{
public:
	void read();
	void print() const;
};

void Teacher::read()
{
	PersonalData::read();
	Class::read();
}

void Teacher::print() const
{
	PersonalData::print();
	Class::print();
}

class CarOwner : public PersonalData, public Car
{
public:
	void read();
	void print() const;
};

void CarOwner::read()
{
	PersonalData::read();
	Car::read();
}

void CarOwner::print() const
{
	PersonalData::print();
	Car::print();
}

int main()
{
	Teacher t;
	CarOwner co;

	t.read();
	co.read();

	cout << "\n===============================\n";
	t.print();
	cout << "\n===============================\n";
	co.print();
	
	return 0;
}