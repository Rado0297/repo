#include "libs.hpp"
#include "gang.hpp"

#ifndef PRISONER_HPP
#define PRISONER_HPP

class Prisoner : public Person
{
protected:
    double verdict;
    Gang* band;

public:
    Prisoner(char*, double);
    Prisoner(const Prisoner&);
    Prisoner& operator=(const Prisoner&);

    Prisoner& operator+=(Prisoner&);

    //Setters
    void setVerdict(double);
    void setGang(Gang*);

    //Getters
    const double getVerdict() const;
    Gang* getGang() const;

    friend ostream& operator<<(ostream& out, const Prisoner& p1);
    friend istream& operator>>(istream& in, Prisoner& p1);
    friend void joinGang(Prisoner&, const Prisoner&);
};

Prisoner::Prisoner(char* _name, double _ver) : Person(_name, 0)
{
    verdict = _ver;
    band = nullptr;
}

Prisoner::Prisoner(const Prisoner& p1)
{
    name = new char[strlen(p1.name) + 1];
    assert(name != nullptr);
    strcpy(name, p1.name);
    verdict = p1.verdict;
    p1.band->changeCountOfMembers(p1.band->getMembersCount() + 1);
    band = p1.band;
    exp = pow(2, (band->getMembersCount() / 2));
}

Prisoner& Prisoner::operator=(const Prisoner& p1)
{
    if (this != &p1) {
        delete name;
        name = new char[strlen(p1.name) + 1];
        assert(name != nullptr);
        strcpy(name, p1.name);
        verdict = p1.verdict;
        p1.band->changeCountOfMembers(p1.band->getMembersCount() + 1);
        band = p1.band;
        exp = pow(2, (band->getMembersCount() / 2));
    }
}

Prisoner& Prisoner::operator+=(Prisoner& p1)
{
    band = p1.band;
    band->changeCountOfMembers(band->getMembersCount() + 1);
    exp = pow(2, band->getMembersCount() / 2);

    return *this;
}

void Prisoner::setVerdict(double _ver)
{
    verdict = _ver;
}

void Prisoner::setGang(Gang* gg)
{
    band = gg;
    exp = pow(2, band->getMembersCount() / 2);
}

const double Prisoner::getVerdict() const
{
    return verdict;
}

Gang* Prisoner::getGang() const
{
    return band;
}


void joinGang(Prisoner& pris1, const Prisoner& pris2)
{
    pris1.setGang(pris2.band);
}

// //Frined funcitons
ostream& operator<<(ostream& out, const Prisoner& p1)
{
    out << "Prisoner name: " << p1.getName() << endl
        << "Prisoner experience: " << p1.getExp() << endl
        << "Prisoner verdict: " << p1.getVerdict() << endl;

        if (p1.band != nullptr) {
            out << "Prisoner band name: " << p1.band->getGangName() << endl
            << "Prisoner band count of members: " << p1.band->getMembersCount() << endl;
        }
        else
        {
            out << "Prisoner band name: NULL" << endl
            << "Prisoner band count of members: 0" << endl;
        }

    return out;
}

istream& operator>>(istream& in, Prisoner& p1)
{
    //enter length of name, name, verdict
    int size;
    in >> size;
    in.get();

    char* nm = new char[size + 1];
    assert(nm != nullptr);

    for (size_t i = 0; i < size; i++) {
        nm[i] = in.get();
    }
    nm[size] = 0;

    p1.setName(nm);

    in >> p1.verdict;

    delete nm;

    return in;
}

#endif
