#include "libs.hpp"

#ifndef PERSON_HPP
#define PERSON_HPP

class Person
{
protected: //protected because of inheritance!!!
    char* name;
    int exp;

public:
    Person();
    Person(char*, int);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    //Setters
    void levelUpEXP(int);
    void setName(char*);
    void setExp(int);

    //Getters
    const char* getName() const;
    const int getExp() const;

    const void print() const;
};

Person::Person()
{
    name = new char[6];
    assert(name != nullptr);
    strcpy(name, "human");
    exp = 0;
}

Person::Person(char* _name, int _exp)
{
    name = new char[strlen(_name) + 1];
    assert(name != nullptr);
    strcpy(name, _name);

    exp = _exp;
}

Person::Person(const Person& p1)
{
    name = new char[strlen(p1.name) + 1];
    assert(name != nullptr);
    strcpy(name, p1.name);
    exp = p1.exp;
}

Person& Person::operator=(const Person& p1)
{
    if (this != &p1) {
        delete name;
        name = new char[strlen(p1.name) + 1];
        assert(name != nullptr);
        strcpy(name, p1.name);
        exp = p1.exp;
    }

    return *this;
}

Person::~Person()
{
    delete name;
}

//Setters
void Person::levelUpEXP(int _exp)
{
    exp += _exp;
}

void Person::setName(char* newName)
{
    delete name;
    name = new char[strlen(newName) + 1];
    assert(name != nullptr);
    strcpy(name, newName);
}

void Person::setExp(int newExpVal)
{
    exp = newExpVal;
}

//Getters
const char* Person::getName() const
{
    return name;
}

const int Person::getExp() const
{
    return exp;
}

const void Person::print() const
{
    cout << name << " " << exp << endl;
}

#endif
