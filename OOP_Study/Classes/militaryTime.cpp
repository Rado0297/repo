#include <iostream>
#include <cmath>

using namespace std;

class MilitaryTime
{
private:
	int theHours, theMinutes, theSeconds;

public:
	MilitaryTime(int aHour, int aMinute = 0, int aSecond = 0);
	MilitaryTime(int aSeconds);
	MilitaryTime(const MilitaryTime&);

	void add(const MilitaryTime&);
	void sub(const MilitaryTime&);
	bool different(const MilitaryTime&) const;
	int totalSeconds() const;
	int hours() const;
	int minutes() const;
	int seconds() const;
	void print();
};

MilitaryTime::MilitaryTime(int h, int m, int s)
{
	if (h > -1 && h < 24 && m > -1 && m < 60 && s > -1 && s < 60)
	{
		theHours = h;
		theMinutes = m;
		theSeconds = s;
	}

	else
	{
		cout << "Incorrect input!\n";
	}

}

MilitaryTime::MilitaryTime(int asec)
{
	if (asec > -1 && asec < 60)
	{
		theHours = 23;
		theMinutes = 59;
		theSeconds = asec;
	}

	else if (asec >= 60)
	{
		theHours = 23;
		theMinutes = 59;
		theSeconds = 59;

		int a, b, c;

		c = asec % 60;
		b = asec / 60;

		if (b > 59)
		{
			a = b / 60;
			b = b % 60;
		}
	}
}

MilitaryTime::MilitaryTime(const MilitaryTime& t)
{
	theHours = t.theHours;
	theMinutes = t.theMinutes;
	theSeconds = t.theSeconds;
}

void MilitaryTime::add(const MilitaryTime& t)
{
	int h = 0, m = 0, s = 0;

	s = theSeconds + t.theSeconds;

	if (s > 59)
	{
		m = s / 60;
		s = s % 60;
	}

	m += (theMinutes + t.theMinutes);

	if (m > 59)
	{
		h = m / 60;
		m = m % 60;
	}

	h += (theHours + t.theHours);

	if (h > 23)
	{
		h = h % 24;
	}

	theHours = h;
	theMinutes = m;
	theSeconds = s;
}

void MilitaryTime::sub(const MilitaryTime& t)
{
	int h, m, s;

	theMinutes += theHours * 60;
	theHours = 0;
	theSeconds += theMinutes * 60;
	theMinutes = 0;

	h = t.theHours;
	m = t.theMinutes;
	s = t.theSeconds;

	m += h * 60;
	h = 0;

	s += m * 60;
	m = 0;

	s = abs(theSeconds - s);
	m = s / 60;
	s = s % 60;

	h = m / 60;
	m = m % 60;

	theHours = h;
	theMinutes = m;
	theSeconds = s;
}

bool MilitaryTime::different(const MilitaryTime& t) const
{
	return (theHours == t.theHours && theMinutes == t.theMinutes && theSeconds == t.theSeconds);
}
	
int MilitaryTime::totalSeconds() const
{
	int m, s;

	m = theHours * 60 + theMinutes;
	s = m * 60 + theSeconds;

	return s;
}

int MilitaryTime::hours() const
{
	return theHours;
}

int MilitaryTime::minutes() const
{
	return theMinutes;
}

int MilitaryTime::seconds() const
{
	return theSeconds;
}

void MilitaryTime::print()
{
	cout << theHours << ":" << theMinutes << ":" << theSeconds << endl;
}

int main()
{
	MilitaryTime t1(10, 30, 30), t2(12, 30, 41);

	t1.print();
	t2.print();

	t1.add(t2);
	t1.print();

	t2.sub(t1);
	t2.print();

	return 0;
}