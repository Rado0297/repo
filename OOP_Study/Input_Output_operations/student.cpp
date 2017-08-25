#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Student
{
private:
	char* name;
	int fn;
	double grade;

public:
	Student()
	{
		name = new char[1];
		name[0] = '\0';
		fn = 0;
		grade = 0;
	}

	Student(const Student& s)
	{
		name = new char[strlen(s.name) + 1];
		if (!name)
		{
			cout << "Error while allocating memory for name!\n";
			exit(1);
		}
		strcpy(name, s.name);
		fn = s.fn;
		grade = s.grade;
	}
	
	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			delete [] name;
			name = new char[strlen(s.name) + 1];
			if (!name)
			{
				cout << "Error while allocating memory for name!\n";
				exit(1);
			}
			strcpy(name, s.name);
			fn = s.fn;
			grade = s.grade;
		}

		return *this;
	}
	
	~Student()
	{
		delete [] name;
	}

	int getFn() const
	{
		return fn;
	}

	double getGrade() const
	{
		return grade;
	}

	char* getName() const
	{
		return name;
	}

	void setFn(int num)
	{
		if (num >= 10000 && num <= 99999)
		{
			fn = num;
		}
	}

	void setGrade(double gr)
	{
		grade = gr;
	}

	void setName(const char* n)
	{
		delete [] name;
		name = new char[strlen(n) + 1];
		if (!name)
		{
			cout << "Error while allocating memory for name!\n";
			exit(1);
		}
		strcpy(name, n);
	}

	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);
};

istream& operator>>(istream& in, Student& s)
{
	int capacity = 4;
	char* helper = new char[capacity + 1];
	int i = 0;

	while(in.peek() != ' ' && in.peek() != '\n' && !in.eof())
	{
		if (i == capacity)
		{
			helper[i] = '\0';
			capacity *= 2;
			char* temp = new char[capacity + 1];
			strcpy(temp, helper);
			delete [] helper;
			helper = temp;
		}
		helper[i] = in.get();
		i++;

		in >> s.fn >> s.grade;
		in.get();
		return in;
	}
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << s.getName() << "\n" << s.getFn() << "\n" << s.getGrade();
	return out;
}

int main()
{
	Student s1,s2;

	s1.setName("Radoslav");
	s1.setFn(81533);
	s1.setGrade(6);

	s2.setName("Krasi");
	s2.setFn(12345);
	s2.setGrade(5.5);

	cout << s1 << endl << s2 << endl;
	


	return 0;
}