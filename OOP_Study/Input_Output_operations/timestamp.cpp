#include <iostream>

using namespace std;

class Timestamp
{
private:
	unsigned long int m_Seconds;

public:
	Timestamp(unsigned long seconds = 0) : m_Seconds(seconds)
	{}

	unsigned long GetValue() const
	{
		return m_Seconds;
	}

	unsigned long SetValue(unsigned long int seconds)
	{
		m_Seconds = seconds;
	}

	Timestamp& operator+=(const Timestamp& ts)
	{
		SetValue(GetValue() + ts.GetValue());
		return *this;
	}

	Timestamp operator+(const Timestamp& ts) const
	{
		return Timestamp(GetValue() + ts.GetValue());
	}
};

ostream& operator<<(ostream& ostr, const Timestamp& ts)
{
	return ostr << ts.GetValue();
}

istream& operator>>(istream& istr, Timestamp& ts)
{
	unsigned long seconds;
	istr >> seconds;
	ts.SetValue(seconds);
	return istr;
}

int main()
{
	Timestamp t1(10), t2(20), t3(30);

	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;

	cin >> t1;
	cin >> t2;
	cin >> t3;

	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;

	t2 += t1;
	cout << t2 << endl;

	t2 += (t2 + t3);

	cout << t2 << endl;

	cout << (t2 + 11) << endl;

	return 0;
}