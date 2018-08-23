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
};

#endif
