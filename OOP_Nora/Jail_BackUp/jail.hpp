#include "libs.hpp"

#ifndef JAIL_HPP
#define JAIL_HPP

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
                //prisoners[i][j].setGang(gangs[i]);
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
        //prisoners[pris1Floor][pris1Cage] += prisoners[pris2Floor][pris2Cage];
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

#endif
