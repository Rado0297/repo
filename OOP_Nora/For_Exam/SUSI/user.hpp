#ifndef __USER_HPP__
#define __USER_HPP__

#include "libs.hpp"
#include "course.hpp"

class Course;

class User
{
protected:
    char* username;
    char password[32];

public:
    User()
    {
        username = new char[7];
        assert(username != nullptr);
        strcpy(username, "user01");

        strcpy(password, "*******");
    }

    User(const char* usr, const char* pwd)
    {
        username = new char[strlen(usr) + 1];
        assert(username != nullptr);
        strcpy(username, usr);

        strcpy(password, pwd);
    }

    ~User()
    {
        delete username;
    }

    const void printGrades() const;
    const void changeGrade(double newGrade) const;
};

class Student : public User
{
private:
    int fnumber;
    int acYear;
    char* specialty;

public:
    Student() : User()
    {
        fnumber = 111111;
        acYear = 1;

        specialty = new char[17];
        assert(specialty != nullptr);
        strcpy(specialty, "Computer science");
    }

    Student(const char* usr, const char* pwd, int fn, int ay, const char* spec) : User(usr, pwd)
    {
        fnumber = fn;
        acYear = ay;

        specialty = new char[strlen(spec) + 1];
        assert(specialty != nullptr);
        strcpy(specialty, spec);
    }

    ~Student()
    {
        delete specialty;
    }

    //Setters

    //Getters
    const int getFN() const
    {
        return fnumber;
    }

    //Functions
    const void printGrades(const Course& c1) const
    {
        for (size_t i = 0; i < c1.getSize(); i++) {
            /* code */
        }
    }

    const void changeGrade(double newGrade) const
    {

    }
};

#endif
