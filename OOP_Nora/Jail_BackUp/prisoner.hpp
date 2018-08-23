#include "libs.hpp"
#include "gang.hpp"

#ifndef PRISONER_HPP
#define PRISONER_HPP

class Prisoner : public Person<double>, public Gang
{
protected:
    //name
    //exp
    double verdict;//verdict - double number
    //gang name
    //gang count of members

public:
    Prisoner();
    Prisoner(char*, double, char*);

    Prisoner& operator+=(Prisoner&);

    //Setters
    void setVerdict(double);

    //Getters
    const double getVerdict() const;

    const void print() const;

    friend ostream& operator<<(ostream& out, const Prisoner& p1);
    friend istream& operator>>(istream& in, Prisoner& p1);
};

Prisoner::Prisoner() : Person("prisoner", 0)
{
    verdict = 20.2;
}

Prisoner::Prisoner(char* _name, double _ver, char* _gangName) : Person(_name, 0), Gang(_gangName), verdict(_ver)
{
    exp = pow(2, (countOfMembers / 2)); //double is rounded to int, after 0.5 it takes 0
}

Prisoner& Prisoner::operator+=(Prisoner& p1)
{
    if (strcmp(gangName, p1.gangName) != 0) {
        delete gangName;
        gangName = new char[strlen(p1.gangName) + 1];
        assert(gangName != nullptr);
        strcpy(gangName, p1.gangName);
        p1.countOfMembers++;
        countOfMembers = p1.countOfMembers;
        exp = pow(2, (countOfMembers / 2));
    }
    else {
        p1.countOfMembers++;
        countOfMembers = p1.countOfMembers;
    }

    return *this;
}

void Prisoner::setVerdict(double _ver)
{
    verdict = _ver;
}

const double Prisoner::getVerdict() const
{
    return verdict;
}

const void Prisoner::print() const
{
    cout << "Print Prisoner:\n";
    Person::print();
    cout << verdict << " " << endl;
    Gang::print();
    cout << "---------------\n";
}

// //Frined funcitons
ostream& operator<<(ostream& out, const Prisoner& p1)
{
    out << "Prisoner name: " << p1.getName() << endl
        << "Prisoner experience: " << p1.getExp() << endl
        << "Prisoner verdict: " << p1.getVerdict() << endl
        << "Prisoner gang: " << p1.getGangName() << endl
        << "Prisoner gang's count of members: " << p1.getMembersCount() << endl;

    return out;
}

istream& operator>>(istream& in, Prisoner& p1)
{
    //enter length of name, name, verdict and band name only
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

    in >> size;
    in.get();

    nm = new char[size + 1];
    assert(nm != nullptr);

    for (size_t i = 0; i < size; i++) {
        nm[i] = in.get();
    }
    nm[size] = 0;

    //if gang exist get it's count

    p1.changeGangName(nm);

    p1.changeCountOfMembers(1);

    p1.exp = pow(2, (p1.getMembersCount() / 2));

    delete nm;

    // in >> size;
    // in.get();
    //
    // nm = new char[size + 1];
    // assert(nm != nullptr);
    //
    // for (size_t i = 0; i < size; i++) {
    //     nm[i] = in.get();
    // }
    // nm[size] = 0;
    //
    // cout << nm << endl;
    //
    // p1.setBandName(nm);
    //
    // delete nm;

    return in;
}

#endif
