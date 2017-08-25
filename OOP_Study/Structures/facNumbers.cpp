#include <iostream>
#include <iomanip>

using namespace std;

int count_of_grades;

struct Student
{
	int facNum;
	char lastName[12];
	double grades[10];
};

void init_student(Student& s)
{
	do
	{
		cout << "Enter facNum: "; cin >> s.facNum;
		cout << "Enter Last Name: "; cin >> s.lastName;

		for (int i = 0; i < count_of_grades; ++i)
		{
			cout << "Enter grade: ";
			cin >> s.grades[i];
		}
	} while(s.facNum <= 0 || s.facNum > 99999);
}

double average_grade(Student& s)
{
	double sum;
	for (int i = 0; i < count_of_grades; ++i)
	{
		sum += s.grades[i];
	}

	sum = sum/count_of_grades;

	return sum;
}

void print_student(Student& s)
{
	cout << setw(5) << s.facNum << setw(13) << s.lastName;

	for (int i = 0; i < count_of_grades; ++i)
	{
		cout << setw(15) << s.grades[i];
	}

	cout << setw(15) << average_grade(s);
	cout << endl;
}

void create_group_of_students(int students_number, Student *s)
{
	cout << "-----------Enter data for each student-----------\n";

	for (int i = 0; i < students_number; ++i)
	{
		init_student(s[i]);
	}
}

void print_table()
{
	for (int i = 0; i < 5 + 12 + 2 + 5*(count_of_grades + 1) + 1; ++i)
	{
		cout << "=";
	}

	cout << endl;

	cout << setw(5) << "Fac. Num." << setw(13) << "Last Name";

	for (int i = 0; i < count_of_grades; ++i)
	{
		cout << setw(15) << "Discipline " << i + 1;
	}

	cout << setw(15) << "Average grade" << endl;

	for (int i = 0; i < 5 + 12 + 2 + 5*(count_of_grades + 1) + 1; ++i)
	{
		cout << "=";
	}

	cout << endl;
}

void print_group(int students_number, Student *s)
{
	print_table();

	double temp[10] = {0, };

	for (int i = 0; i < count_of_grades; ++i)
	{
		for (int j = 0; j < students_number; ++j)
		{
			temp[i] = temp[i] + s[j].grades[i];
		}

		temp[i] = temp[i]/students_number;
	}

	double sum = 0;

	for (int i = 0; i < students_number; ++i)
	{
		print_student(s[i]);
	}

	cout << endl;

	for (int i = 0; i < 5 + 12 + 2 + 5*(count_of_grades + 1) + 1; ++i)
	{
		cout << "=";
	}

	cout << endl << setw(5 + 12 + 2 + 5) << temp[0];

	for (int i = 0; i < count_of_grades; ++i)
	{
		cout << setw(5) << temp[i];
	}

	cout << setw(6) << sum/students_number << endl;
}

void sort_group(int students_number, Student **s)
{
	for (int i = 0; i < students_number - 1; ++i)
	{
		int k = i;

		double max = average_grade(*s[k]);

		for (int j = 0; j < students_number; ++j)
		{
			double d = average_grade(*s[j]);
			if(d > max)
			{
				max = d;
				k = j;
			}
		}

		Student *x;
		x = s[i];
		s[i] = s[k];
		s[k] = x;
	}
}

void print_sorted_group(int students_number, Student **s)
{
	print_table();

	for (int i = 0; i < students_number; ++i)
	{
		print_student(*s[i]);
	}
}

int main()
{
	int students_number;

	do
	{
		cout << "Enter number of students: ";
		cin >> students_number;
	} while (students_number < 1 || students_number > 25);

	do
	{
		cout << "Enter number of grades for the student: ";
		cin >> count_of_grades;
	} while (count_of_grades < 1 || count_of_grades > 10);

	Student students[25];

	Student *stud[25];

	create_group_of_students(students_number, students);

	print_group(students_number, students);

	for (int i = 0; i < students_number; ++i)
	{
		stud[i] = &students[i];
	}

	sort_group(students_number, stud);

	cout << endl;

	print_sorted_group(students_number, stud);

	return 0;
}