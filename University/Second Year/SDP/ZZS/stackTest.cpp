#include <iostream>
#include <stack>

using namespace std;

/*iterative
void printRec(int k)
{
	int temp = k;
	while (k != 0)
	{
		cout << '*';
		for (int i = 0; i < k; ++i)
		{
			cout << ' ';
		}
		cout << '*';
		k--;
		cout << endl;
	}
	cout << "**" << endl;

	while (k != temp)
	{
		cout << '*';
		for (int i = 0; i <= k; ++i)
		{
			cout << ' ';
		}
		cout << '*';
		k++;
		cout << endl;
	}
}
*/

//recursive
void printRec(int k)
{
	if (k == 0)
	{
		cout << "**\n";
		return;
	}
	cout << '*';
	for (int i = 0; i < k; ++i)
	{
		cout << ' ';
	}
	cout << '*';
	cout << endl;

	printRec(k-1);

	cout << '*';
	for (int i = 0; i < k; ++i)
	{
		cout << ' ';
	}
	cout << '*';
	cout << endl;
}

//recursive
void printDiamond(int k, int temp)
{
	if (k == 0)
	{
		for (int i = 0; i < 2*k - 1; ++i)
		{
			cout << '*';
		}

		return;
	}

	int i = 0;
	for (; i < k - 1; ++i)
	{
		cout << ' ';
		
	}

	for (int j = temp - i - 1; j >= 0; --j)
	{
		cout << '*';
	}

	cout << endl;

	printDiamond(k-1, temp+1);

	//cout << endl;
	//cout << "ALERT TEMP " << temp << endl;
	for (i = k - 1; i >= 0; --i)
	{
		cout << ' ';
	}

	for (int j = temp - k - 2; j >= 0; --j)
	{
		cout << '*';
	}
	
	cout << endl;

}

int main()
{
	printDiamond(10, 10);

	/*
	int num;
	cin >> num;

	int temp;
	stack<int> st;


	while (num != 0)
	{
		temp = num % 10;		

		st.push(temp);

		num = num / 10;
	}

	while (!st.empty())
	{
		cout << st.top();
		cout << " ";
		st.pop();
	}

	cout << endl;
	*/


	return 0;
}