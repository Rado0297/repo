#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

class Album
{
protected:
    char* name;
    int year;

    void copy(const Album& a1)
    {
        name = new char[strlen(a1.name) + 1];
        assert(name != nullptr);
        strcpy(name, a1.name);

        year = a1.year;
    }

public:
    Album()
    {
        name = new char[5];
        assert(name != nullptr);
        strcpy(name, "NULL");

        year = 0;
    }

    Album(const char* _name, const int _year)
    {
        name = new char(strlen(_name) + 1);
        assert(name != nullptr);
        strcpy(name, _name);
        year = _year;
    }

    Album(const Album& a1)
    {
        copy(a1);
    }

    Album& operator=(const Album& a1)
    {
        if (this != &a1) {
            copy(a1);
        }

        return *this;
    }

    ~Album()
    {
        delete name;
    }

    const char* getName() const
    {
        return name;
    }

    const int getYear() const
    {
        return year;
    }

    friend ostream& operator<<(ostream& out, const Album& a1);
};

ostream& operator<<(ostream& out, const Album& a1)
{
    out << "Album: " << a1.name << endl
        << "Year: " << a1.year << endl;

    return out;
}

class ChoirAlbum : public Album
{
protected:
    int countChoirers;

public:
    ChoirAlbum() : Album(), countChoirers(0){}

    ChoirAlbum(const char* _name, const int _year, const int _count) : Album(_name, _year), countChoirers(_count){}

    ChoirAlbum(const ChoirAlbum& ca1) : Album(ca1), countChoirers(ca1.countChoirers){}

    ChoirAlbum& operator=(const ChoirAlbum& ca1)
    {
        if (this != nullptr) {
            Album::operator=(ca1);

            countChoirers = ca1.countChoirers;
        }

        return *this;
    }

    const int getChoirersCount() const
    {
        return countChoirers;
    }

    friend ostream& operator<<(ostream& out, const ChoirAlbum& ca1);
};

ostream& operator<<(ostream& out, const ChoirAlbum& ca1)
{
    out << "Choir album: " << ca1.name << endl
        << "Year: " << ca1.year << endl
        << "Count of choirers: " << ca1.countChoirers << endl;

    return out;
}

class ClassicAlbum : public Album
{
protected:
    char* leader;

public:
    ClassicAlbum() : Album()
    {
        leader = new char[5];
        assert(leader != nullptr);
        strcpy(leader, "NuLl");
    }

    ClassicAlbum(const char* _name, const int _year, const char* _leader) : Album(_name, _year)
    {
        leader = new char[strlen(_leader) + 1];
        assert(leader != nullptr);
        strcpy(leader, _leader);
    }

    ClassicAlbum(const ClassicAlbum& ca1) : Album(ca1)
    {
        leader = new char[strlen(ca1.leader) + 1];
        assert(leader != nullptr);
        strcpy(leader, ca1.leader);
    }

    ClassicAlbum& operator=(const ClassicAlbum& ca1)
    {
        if (this != &ca1) {
            Album::operator=(ca1);

            leader = new char[strlen(ca1.leader) + 1];
            assert(leader != nullptr);
            strcpy(leader, ca1.leader);
        }

        return *this;
    }

    ~ClassicAlbum()
    {
        delete leader;
    }

    const char* getLeader() const
    {
        return leader;
    }

    friend ostream& operator<<(ostream& out, const ClassicAlbum& ca1);
};

ostream& operator<<(ostream& out, const ClassicAlbum& ca1)
{
    out << "Classic album: " << ca1.name << endl
        << "Year: " << ca1.year << endl
        << "Leader: " << ca1.leader << endl;

    return out;
}

class OperaAlbum : public ChoirAlbum, public ClassicAlbum
{
public:
    OperaAlbum() : ChoirAlbum(), ClassicAlbum(){}

    OperaAlbum(const char* _name, const int _year, const int _count, const char* _leader)
        : ChoirAlbum(_name, _year, _count), ClassicAlbum(_name, _year, _leader){}

    OperaAlbum(const OperaAlbum& oa1) : ChoirAlbum(oa1), ClassicAlbum(oa1){}

    OperaAlbum& operator=(const OperaAlbum& oa1)
    {
        if (this != nullptr) {
            ChoirAlbum::operator=(oa1);
            ClassicAlbum::operator=(oa1);
        }

        return *this;
    }

    friend ostream& operator<<(ostream&, const OperaAlbum& ca1);
};

ostream& operator<<(ostream& out, const OperaAlbum& ca1)
{
    out << "Classic album: " << ca1.ClassicAlbum::getName() << endl
        << "Year: " << ca1.ClassicAlbum::getYear() << endl
        << "Choirers count: " << ca1.ChoirAlbum::getChoirersCount() << endl
        << "Leader: " << ca1.ClassicAlbum::getLeader() << endl;

    return out;
}

int main() {
    Album a1;
    Album a2("Rosenrot", 1997);
    Album a3("OOP", 2016);
    Album a4(a2);
    Album a5;
    a5 = a3;

    cout << a1 << endl << a2 << endl << a3 << endl << a4 << endl << a5 << endl;


    return 0;
}
