#include <iostream>

using namespace std;

class fact
{
private:
	int x;

public:
	fact(int a)
	{
		x = a;
	}

	unsigned int value() const
	{
		int y = 1;

		for (int i = 1; i <= x; ++i)
		{
			y *= i;
		}

		return y;
	}
};

int main()
{
	int a;
	do
	{
		cout << "a = ";
		cin >> a;
	} while (a <= 0);

	fact t(a);

	cout << t.value() << endl;

	return 0;
}