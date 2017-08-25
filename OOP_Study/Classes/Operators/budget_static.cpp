#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 5;

class Budget
{
private:
	static double universityBudget;
	double facultyBudget;

public:
	Budget();
	double getFacultyBudget() const;
	double getUniversityBudget() const;
	void addBudget(double);
	static void administration(double);
};

double Budget::universityBudget = 0;

Budget::Budget()
{
	facultyBudget = 0;
}

double Budget::getUniversityBudget() const
{
	return universityBudget;
}

double Budget::getFacultyBudget() const
{
	return facultyBudget;
}

void Budget::addBudget(double bud)
{
	facultyBudget = bud;
	universityBudget += facultyBudget;
}

void Budget::administration(double bud)
{
	universityBudget += bud;
}

int main()
{
	const int numFaculty = MAX_SIZE;

	cout << "Enter administration budget: ";
	double adminBudget;
	cin >> adminBudget;
	Budget::administration(adminBudget);

	int i;

	double budgetAmount;

	Budget fac[numFaculty];

	for (int i = 0; i < numFaculty; ++i)
	{
		cout << "Enter budget of the " << i + 1 << "-th faculty: ";
		cin >> budgetAmount;
		fac[i].addBudget(budgetAmount);
	}

	cout << setiosflags(ios::fixed) << setprecision(2);

	cout << "\tAdministration's budget is:\t";
	cout << adminBudget << endl;

	for (int i = 0; i < numFaculty; ++i)
	{
		cout << "\t Faculty " << i + 1 << ":\t";
		cout << fac[i].getFacultyBudget() << endl;
	}

	cout << "\t Budget of the university:\t";
	cout << fac[0].getUniversityBudget() << endl;

	return 0;
}