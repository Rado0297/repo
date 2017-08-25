#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	void simplify();

public:
	Time();
	Time(int, int = 0);
	Time(const Time&);

	//Setters
	void reset(int = 0, int = 0);

	void addMin(int);
	void addHours(int);
	operator int() const;
	void print() const;
	Time operator+(const Time&) const;
	Time operator-(const Time&) const;
	Time operator*(const Time&) const;
	friend Time operator*(int m, const Time& t)
	{
		return t * m;
	}
};

void Time::simplify()
{
	if (minutes >= 60)
	{
		hours += minutes / 60;
		minutes = minutes % 60;
	}
}

Time::Time()
{
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m)
{
	reset(h, m);
}

Time::Time(const Time& r)
{
	hours = r.hours;
	minutes = r.minutes;
}

void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
	simplify();
}

void Time::addMin(int m)
{
	minutes = minutes + m;
	simplify();
}

void Time::addHours(int h)
{
	hours = hours + h;
}

void Time::print() const
{
	cout << hours << " hours, " << minutes << " minutes\n";
}

Time::operator int() const
{
	return hours*60 + minutes;
}

Time Time::operator+(const Time& t) const
{
	Time new_t;
	new_t.minutes = minutes + t.minutes;
	new_t.hours = hours + t.hours;
	new_t.simplify();
	return new_t;
}

Time Time::operator-(const Time& t) const
{
	Time new_t;
	int m1, m2;
	m1 = t.hours*60 + t.minutes;
	m2 = hours*60 + minutes;
	new_t.minutes = (m2 - m1) % 60;
	new_t.hours = (m2 - m1) / 60;
	return new_t;
}

Time Time::operator*(int mult) const 
{
	Time new_t;
	int m = (hours*60 + minutes) * mult;
	new_t.hours = m / 60;
	new_t.minutes = m % 60;
	return new_t;
}

int main()
{
	Time t1, t2(12);
	t1.print();
	t2.print();

	Time t3 = t2;
	t3.print();

	t3.addMin(105);	
	t3.print();
	
	t2.addHours(6);
	t2.print();
	
	t1 = t2 + t3;

	t1.print();

	t1 = t2 - t3;
	t1.print();

	t1 = t1 * 2;
	t1.print();

	(6 * t1).print();

	cout << t1 << endl;

	return 0;
}