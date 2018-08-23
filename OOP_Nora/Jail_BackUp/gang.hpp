#include "libs.hpp"

#ifndef GANG_HPP
#define GANG_HPP

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

        countOfMembers = 1;
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

#endif
