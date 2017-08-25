#include <iostream>
#include <cmath>

using namespace std;

const double DEG_TO_RAD = 3.14159265/180;

class angle
{
private:
	double degrees;

public:
	void init(double a)
	{
		degrees = a;
	}

	double getSin() const;
	double getCos() const;
	double getTan() const;
};

double angle::getSin() const
{
	return sin(DEG_TO_RAD * degrees);
}

double angle::getCos() const
{
	return cos(DEG_TO_RAD * degrees);
}

double angle::getTan() const
{
	return tan(DEG_TO_RAD * degrees);
}

int main()
{
	double deg;
	cin >> deg;

	angle a;

	a.init(deg);

	cout << "sin(" << deg << ") = " << a.getSin() << endl;
	cout << "cos(" << deg << ") = " << a.getCos() << endl;
	cout << "tan(" << deg << ") = " << a.getTan() << endl;

	return 0;
}