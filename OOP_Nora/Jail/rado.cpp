#include <iostream>
#include <cstring>
#include <cmath>
#include <assert.h>

using namespace std;

template <typename T>
class Person
{
protected:                /***/
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

class Guard : public Person<int>
{
private:
    char* guardName;
    int guardExp;

public:
    Guard(char*, int);
};

Guard::Guard(char* _name, int _exp) : Person(_name, _exp){}

class Prisoner : public Person<double>
{
private:
    //char* prisonerName;//name
    double verdict;//verdict - double number
    //double prisonerExp;//exp
    char band[30];//band name

public:
    Prisoner();
    Prisoner(char*, double, double, char*);
    //~Prisoner();

    //Setters

    //Getters

    const void print() const;
};

Prisoner::Prisoner():Person("prisoner", 2.3)            /****/
{
    // prisonerName = new char[9];
    // assert(prisonerName != nullptr);
    // strcpy(prisonerName, "prisoner");
    // prisonerExp = 2.3;

    verdict = 20.2;
    strcpy(band, "Riders");
}

Prisoner::Prisoner(char* _name, double _ver, double _exp, char* _band):Person(_name, _exp)      /****/
{
    // prisonerName = new char[strlen(_name) + 1];
    // assert(prisonerName != nullptr);
    // strcpy(prisonerName, _name);
    //
    // prisonerExp = _exp;
    verdict = _ver;
    strcpy(band, _band);
}

// Prisoner::~Prisoner()
// {
//     delete prisonerName;
// }

const void Prisoner::print() const
{
    cout << "Print Prisoner:\n";
    cout << " " << exp << verdict << " " << band << endl;       /***/
    cout << "---------------\n";
}

class Jail
{

};

int main() {
    //Initialize some list with gangsta bands in the jail
    //and count of members in each band
    char** bands = new char*[6];
    assert(bands != nullptr);
    for (size_t i = 0; i < 6; i++) {
        bands[i] = new char[10];
    }
    strcpy(bands[0], "Riders");
    strcpy(bands[1], "Anarchists");
    strcpy(bands[2], "Demolishers");
    strcpy(bands[3], "Rapists");
    strcpy(bands[4], "Assassins");

    int countOfMembersOfBands[5] = {0, 0, 0, 0, 0};
    //edn of init

    // Person<int> a1("Jake", 20);
    // a1.print();
    //
    // Person<int> a2;
    // a2 = a1;
    // a2.print();
    //
    // Guard g1("Will Smith", 10);
    // g1.levelUpEXP(20);
    // cout << "From getters: " << g1.getExp() << " " << g1.getName() << endl;
    // g1.print();

    //Prisoner p1("John Cena", 12.3, 10, "Anarchists");
    //p1.print();
    // Prisoner p2("YOur mother", 123.9, 100, "Rapists");
    // p1.print();
    // p2.print();
    // p2 = p1;
    // p2.print();
    // cout << p1.getExp() << " " << p1.getName() << endl;


    Guard g1("Jake", 20);
    g1.print();
    g1.setExp(400);
    cout << g1.getExp() << endl;
    g1.setName("James Bond");
    cout << g1.getName() << endl;
    g1.print();

    g1.levelUpEXP(20);
    g1.print();

    cout<<"!!!!";
    Prisoner p1;
    p1.print();

    for (size_t i = 0; i < 6; i++) {
        delete bands[i];
    }
    delete bands;

    return 0;
}
