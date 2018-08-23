#include "libs.hpp"

#ifndef GUARD_HPP
#define GUARD_HPP

class Guard : public Person
{
public:
    Guard() : Person("Guard", 10){};
    Guard(char*, int);

    void catchPrisoner();

    //Friend functions
    friend ostream& operator<<(ostream& out, const Guard& g1);
    friend istream& operator>>(istream& in, Guard& g1);
};

Guard::Guard(char* _name, int _exp) : Person(_name, _exp){}

void Guard::catchPrisoner()
{
    exp += 20;
}

//Frined funcitons
ostream& operator<<(ostream& out, const Guard& g1)
{
    out << "Guard name: " << g1.getName() << endl
        << "Guard experience: " << g1.getExp() << endl;

    return out;
}

istream& operator>>(istream& in, Guard& g1)
{
    int size;
    in >> size;
    in.get();

    char* nm = new char[size + 1];
    assert(nm != nullptr);

    for (size_t i = 0; i < size; i++) {
        nm[i] = in.get();
    }
    nm[size] = 0;

    g1.setName(nm);

    g1.setExp(10);

    delete nm;

    return in;
}

#endif
