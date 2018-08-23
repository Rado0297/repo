#include <iostream>
#include <cstring>
#include <cmath>
#include <assert.h>

using namespace std;

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

class Guard : public Person<int>
{
public:
    Guard() : Person("Guard", 10){};
    Guard(char*, int);

    //Friend functions
    friend ostream& operator<<(ostream& out, const Guard& g1);
    friend istream& operator>>(istream& in, Guard& g1);
};

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

Guard::Guard(char* _name, int _exp) : Person(_name, _exp){}

class Gang
{
protected:
    char* gangName;
    int countOfMembers;

public:
    Gang()
    {
        gangName = new char[17];
        assert(gangName != nullptr);

        strcpy(gangName, "Gang_Default_Val");

        countOfMembers = 0;
    }

    Gang(char* _name)
    {
        gangName = new char[strlen(_name) + 1];
        assert(gangName != nullptr);

        strcpy(gangName, _name);

        countOfMembers = 0;
    }

    Gang(const Gang& gg)
    {
        gangName = new char[strlen(gg.gangName) + 1];
        assert(gangName != nullptr);
        strcpy(gangName, gg.gangName);

        countOfMembers = gg.countOfMembers;
    }

    Gang& operator=(const Gang& gg)
    {
        if (this != &gg) {
            delete gangName;
            gangName = new char[strlen(gg.gangName) + 1];
            assert(gangName != nullptr);
            strcpy(gangName, gg.gangName);

            countOfMembers = gg.countOfMembers;
        }

        return *this;
    }

    ~Gang()
    {
        delete gangName;
    }

    void changeGangName(char* newName)
    {
        delete gangName;
        gangName = new char[strlen(newName) + 1];

        strcpy(gangName, newName);
    }

    void changeCountOfMembers(int newCount)
    {
        countOfMembers = newCount;
    }

    const char* getGangName() const
    {
        return gangName;
    }

    const int getMembersCount() const
    {
        return countOfMembers;
    }

    const void print() const
    {
        cout << gangName << " " << countOfMembers << endl;
    }

    friend ostream& operator<<(ostream& out, const Gang& gg);
    friend istream& operator>>(istream& in, Gang& gg);
};

ostream& operator<<(ostream& out, const Gang& gg)
{
    out << "Gang name: " << gg.gangName << endl
        << "Gang's cout of members: " << gg.countOfMembers << endl;

    return out;
}

istream& operator>>(istream& in, Gang& gg)
{
    int size;
    in >> size;

    in.get(); //because of space between size and name

    gg.gangName = new char[size + 1];
    assert(gg.gangName != nullptr);

    for (size_t i = 0; i < size; i++) {
        gg.gangName[i] = in.get();
    }
    gg.gangName[size] = 0;

    gg.countOfMembers = 0;

    return in;
}

class Prisoner : public Person<double>, public Gang
{
protected:
    double verdict;//verdict - double number
    Gang band;//band name

public:
    Prisoner();
    Prisoner(char*, double);

    Prisoner& operator+=(Prisoner&);
    //Setters
    void setGang(Gang&);

    //Getters
    Gang* getGang();
    const double getVerdict() const;

    const void print() const;

    friend ostream& operator<<(ostream& out, const Prisoner& p1);
    friend istream& operator>>(istream& in, Prisoner& p1);
};

Prisoner::Prisoner() : Person("prisoner", 0)
{
    verdict = 20.2;
}

Prisoner::Prisoner(char* _name, double _ver) : Person(_name, 0)
{
    verdict = _ver;
    //when prisoner doesn't belong to any gang
    //he will belongs to Gang_Default_Val and members in this gang will be zero
}

Prisoner& Prisoner::operator+=(Prisoner& p1)
{
    int temp = p1.band.getMembersCount();
    temp++;
    p1.band.changeCountOfMembers(temp);
    band = p1.band;
    exp = pow(2, band.getMembersCount());
}

// void Prisoner::setBandName(char* _name)
// {
//     if (strlen(_name) < 30) {
//         strcpy(band, _name);
//     }
//     else
//     {
//         cout << "Error: Band name must be shorter than 29 symbols!\n";
//     }
// }
//

void Prisoner::setGang(Gang& gg)
{
    char temp = new char[strlen(gg.getGangName()) + 1];
    assert(temp != nullptr);
    strcpy(temp, gg.getGangName());

    band.changeGangName(temp);
    band.changeCountOfMembers(gg.getMembersCount());
}

Gang* Prisoner::getGang()
{
    return &band;
}

const double Prisoner::getVerdict() const
{
    return verdict;
}

const void Prisoner::print() const
{
    cout << "Print Prisoner:\n";
    Person::print();
    cout << verdict << " " << band << endl;
    cout << "---------------\n";
}

// //Frined funcitons
ostream& operator<<(ostream& out, const Prisoner& p1)
{
    out << "Prisoner name: " << p1.getName() << endl
        << "Prisoner experience: " << p1.getExp() << endl
        << "Prisoner verdict: " << p1.getVerdict() << endl
        << "Prisoner band:\n" << p1.band << endl;

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

class Jail
{
private:
    Guard guards[20];
    Prisoner prisoners[4][20];
    Gang gangs[7] = {"Riders", "Anarchist", "Demolishers", "Rapists", "Assassins", "Robbers", "Kidnappers"};

public:
    Jail();

    void hireGuard(const Guard&);

    void acceptPrisoner(const Prisoner&);

    void joinGang(const char*, const char*);

    const void print() const;
};

Jail::Jail()
{
    //on every floor there will be a member of each gang and every other prisoners can join to one of seven gangs
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 20; j++) {
            cin >> prisoners[i][j];
            if (j % 2 == 0 && j < 7) {
                prisoners[i][j].setGang(gangs[i]);
                // int temp = prisoners[i][j].band.getMembersCount();
                // temp++;
                // prisoners[i][j].band.changeCountOfMembers(temp);
            }

            else if (j % 2 != 0 && j < 7) {
                //prisoners[i][j].band = gangs[j];
            }
        }
    }
}

void Jail::hireGuard(const Guard& arr)
{
    for (size_t i = 0; i < 20; i++) {
        if (strcmp(guards[i].getName(), "Guard") == 0) {
            guards[i] = arr;
            break;
        }
    }
}

void Jail::acceptPrisoner(const Prisoner& pr)
{
    for (size_t i = 0; i < 4; i++) {
        int check = 0;

        for (size_t j = 0; j < 20; j++) {
            if (strcmp(prisoners[i][j].getName(), "prisoner") == 0) {
                prisoners[i][j] = pr;
                check++; //breaks outter for loop
                break;
            }
        }

        if (check != 0) {
            break;
        }
    }
}

void Jail::joinGang(const char* name1, const char* name2)
{
    bool pris1 = false;
    bool pris2 = false;

    int pris1Floor;
    int pris1Cage;

    int pris2Floor;
    int pris2Cage;

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 20; j++) {
            if (strcmp(prisoners[i][j].getName(), name1) == 0) {
                pris1 = true;
                pris1Floor = i;
                pris1Cage = j;
            }
            if (strcmp(prisoners[i][j].getName(), name2) == 0) {
                pris2 = true;
                pris2Floor = i;
                pris2Cage = j;
            }
        }
    }

    if(pris1 && pris2)
    {
        prisoners[pris1Floor][pris1Cage] += prisoners[pris2Floor][pris2Cage];
    }
    else
    {
        cout << "Error: Name1 or Name2 is incorrect name!\n";
    }
}

const void Jail::print() const
{
    //some test
    for (size_t i = 0; i < 20; i++) {
        if (strcmp(guards[i].getName(), "Guard") != 0) {
            cout << "------------\n";
            cout << guards[i];
            cout << "------------\n";
        }
    }

    for (size_t i = 0; i < 4; i++) {
        cout << i + 1 << " Floor cells (only not empty cells):\n";
        for (size_t j = 0; j < 20; j++) {
            if (strcmp(prisoners[i][j].getName(), "prisoner") != 0) {
                cout << "------------\n";
                cout << prisoners[i][j];
                cout << "------------\n";
            }
        }
    }

    for (size_t i = 0; i < 7; i++) {
        cout << gangs[i];
    }
}

int main() {



    Guard g;
    cin >> g;


    Gang gangs[5];

    for (size_t i = 0; i < 5; i++) {
        cin >> gangs[i];
    }

    for (size_t i = 0; i < 5; i++) {
        cout << gangs[i];
    }



    Prisoner p2("Freddy Cruger", 123.3);
    cout << p2;

    Prisoner p3("John Snow", 13.2);
    cout << p3;
    p3 += p2;
    cout << p3;

    Jail j1;
    j1.hireGuard(g);
    j1.acceptPrisoner(p2);
    j1.acceptPrisoner(p3);
    j1.joinGang(p2.getName(), p3.getName());
    j1.print();


    Gang gg("Dis");
    cout << gg;

    cin >> gg;

    cout << gg;

    return 0;
}
