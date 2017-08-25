#include <iostream>

using namespace std;

const int MAX = 20;

class differ
{
private:
	int n;
	int a[MAX];

public:
	differ(int m)
	{
		n = m;

		for (int i = 0; i < m; ++i)
		{
			cin >> a[i];
		}
	}

	bool diff() const
	{
		if(n == 1) return true;

		int i = -1;

		bool b;
		int j;

		do
		{
			i++;
			j = i;
			do
			{
				j++;
				b = a[i] != a[j];
			} while (b && j < n - 1);
		} while (b && i < n - 2);

		return b;
	}
};

int main()
{
	int n;

	do
	{
		cout << "n = ";
		cin >> n;
	} while (n < 1);

	differ t(n);

	cout << "Row's elements " << (t.diff() ? "are different.\n" : "are not different.\n");

	return 0;
}