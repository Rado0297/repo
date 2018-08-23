#include "libs.hpp"

#ifndef PERSON_HPP
#define PERSON_HPP

template <typename T>
class Person
{
protected: //protected because of inheritance!!!
    char* name;
    T exp;

public:
    Person();
    Person(char*, T);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    //Setters
    void levelUpEXP(T);
    void setName(char*);
    void setExp(T);

    //Getters
    const char* getName() const;
    const T getExp() const;

    const void print() const;
};

template <typename T>
Person<T>::Person()
{
    name = new char[6];
    assert(name != nullptr);
    strcpy(name, "human");
    exp = 0;
}

template <typename T>
Person<T>::Person(char* _name, T _exp)
{
    name = new char[strlen(_name) + 1];
    assert(name != nullptr);
    strcpy(name, _name);

    exp = _exp;
}

template <typename T>
Person<T>::Person(const Person& p1)
{
    name = new char[strlen(p1.name) + 1];
    assert(name != nullptr);
    strcpy(name, p1.name);
    exp = p1.exp;
}

template <typename T>
Person<T>& Person<T>::operator=(const Person& p1)
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

template <typename T>
Person<T>::~Person()
{
    delete name;
}

//Setters
template <typename T>
void Person<T>::levelUpEXP(T _exp)
{
    exp += _exp;
}

template <typename T>
void Person<T>::setName(char* newName)
{
    delete name;
    name = new char[strlen(newName) + 1];
    assert(name != nullptr);
    strcpy(name, newName);
}

template <typename T>
void Person<T>::setExp(T newExpVal)
{
    exp = newExpVal;
}

//Getters
template <typename T>
const char* Person<T>::getName() const
{
    return name;
}

template <typename T>
const T Person<T>::getExp() const
{
    return exp;
}

template <typename T>
const void Person<T>::print() const
{
    cout << name << " " << exp << endl;
}

#endif
