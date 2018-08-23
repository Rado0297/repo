#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include "libs.hpp"
#include "user.hpp"

class Course
{
private:
    char* lector;
    char* subject;
    char period[10];
    Student* students;
    double marks[200];
    int size;

    void copy(const Course& c1)
    {
        lector = new char[strlen(c1.lector) + 1];
        assert(lector != nullptr);
        strcpy(lector, c1.lector);

        subject = new char[strlen(c1.subject) + 1];
        assert(subject != nullptr);
        strcpy(subject, c1.subject);

        strcpy(period, c1.period);

        size = c1.size;
        students = new Student[size];

        for (size_t i = 0; i < size; i++) {
            students[i] = c1.students[i];
            marks[i] = c1.marks[i];
        }
    }

public:
    //Big 4
    Course()
    {
        lector = new char[7];
        assert(lector != nullptr);
        strcpy(lector, "Lector");

        subject = new char[8];
        assert(subject != nullptr);
        strcpy(subject, "Subject");

        strcpy(period, "2017/2018");

        size = 3;
        students = new Student[size];

        Student temp[3];
        for (size_t i = 0; i < size; i++) {
            students[i] = temp[i];
            marks[i] = 6;
        }
    }
    //l = lectro, s = subject, p = period, sts = students, m = marks, sz = size
    Course(const char* l, const char* s, const char* p, Student* sts, double* m, int sz)
    {
        lector = new char[strlen(l) + 1];
        assert(lector != nullptr);
        strcpy(lector, l);

        subject = new char[strlen(s) + 1];
        assert(subject != nullptr);
        strcpy(subject, s);

        strcpy(period, p);

        size = sz;
        students = new Student[size];

        for (size_t i = 0; i < size; i++) {
            students[i] = sts[i];
            marks[i] = m[i];
        }
    }

    Course(const Course& c1)
    {
        copy(c1);
    }

    Course& operator=(const Course& c1)
    {
        if (this != &c1) {
            copy(c1);
        }

        return *this;
    }

    ~Course()
    {
        delete lector;
        delete subject;
        delete students;
    }

    //Setters
    void setMark()
    {

    }

    //Getters
    const int getSize() const
    {
        return size;
    }

    const char* getSubject() const
    {
        return subject;
    }

    const void listMarks() const
    {
        for (size_t i = 0; i < size; i++) {
            cout << marks[i] << endl;
        }
    }

    //Functions
    friend ostream& operator<<(ostream& out, const Course& c1);
};

ostream& operator<<(ostream& out, const Course& c1)
{
    out << "------- Course: " << c1.subject << " -------\n"
        << "Lector: " << c1.lector << endl
        << "Year of happenning: " << c1.period << endl;

    for (size_t i = 0; i < c1.size; i++) {
        out << "Student " << i << ": " << c1.students[i].getFN() << endl
            << "Mark: " << c1.marks[i] << endl;
    }

    return out;
}

#endif
