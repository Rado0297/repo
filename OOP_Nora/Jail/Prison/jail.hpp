#include "libs.hpp"

#ifndef JAIL_HPP
#define JAIL_HPP

class Jail{
private:
    bool cells[4][20];
    int countOfGuards;
    int countOfPrisoners;
    Guard** guards;
    Prisoner** prisoners;
    void copyJail(const Jail&);

public:
    Jail();
    Jail(const Jail&);
    Jail& operator=(const Jail&);
    ~Jail();

    void hireGuard(Guard&);
    void acceptPrisoner(Prisoner&);
    void iterateDays(int) const;
    void prisonBreak(Prisoner&);

    const void print() const;
};

void Jail::copyJail(const Jail& j1)
{
    countOfGuards = j1.countOfGuards;
    countOfPrisoners = j1.countOfPrisoners;

    guards = new Guard*[countOfGuards];
    for (size_t i = 0; i < countOfGuards; i++) {
        guards[i] = j1.guards[i];
    }

    prisoners = new Prisoner*[countOfPrisoners];
    for (size_t i = 0; i < countOfPrisoners; i++) {
        prisoners[i] = j1.prisoners[i];
    }

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 20; j++) {
            cells[i][j] = j1.cells[i][j];
        }
    }
}

Jail::Jail()
{
    countOfGuards = 0;
    countOfPrisoners = 0;
    guards = new Guard*[0];
    prisoners = new Prisoner*[0];
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 20; j++) {
            cells[i][j] = 0;
        }
    }
}

Jail::Jail(const Jail& j1)
{
    copyJail(j1);
}

Jail& Jail::operator=(const Jail& j1)
{
    if (this != &j1) {
        delete[] guards;
        delete[] prisoners;
        copyJail(j1);
    }

    return *this;
}

Jail::~Jail()
{
    delete guards;
    delete prisoners;
}

void Jail::hireGuard(Guard& guard)
{
    Guard** temp = new Guard*[countOfGuards + 1];
    for (size_t i = 0; i < countOfGuards; i++) {
        temp[i] = guards[i];
    }

    delete guards;

    guards = temp;
    guards[countOfGuards] = &guard;

    countOfGuards++;
}

void Jail::acceptPrisoner(Prisoner& prisoner)
{
    int i = 0;
    int j = 0;
    while (cells[i][j] == 1){
        j++;
        if (j == 20){
            j = 0;
            i++;
            if (i == 4){
                cout << "Error: Not enought space!\n";
                return;
            }
        }
    }
    cells[i][j] = 1;

    Prisoner** temp = new Prisoner*[countOfPrisoners + 1];
    for (int i = 0; i < countOfPrisoners; i++){
        temp[i] = prisoners[i];
    }

    delete prisoners;

    prisoners = temp;

    prisoners[countOfPrisoners] = &prisoner;
    countOfPrisoners++;
}

void Jail::iterateDays(int days) const
{
    int experience = days / 4;

    for (size_t i = 0; i < countOfGuards; i++) {
        guards[i]->levelUpEXP(experience);
    }
}

void Jail::prisonBreak(Prisoner& prisoner)
{
    int index = (prisoner.getGang()->getMembersCount() * 7) % countOfGuards;
    Guard* guard = guards[index];

    prisoner.levelUpEXP(pow(2, prisoner.getGang()->getMembersCount() / 2));

    if (prisoner.getExp() > guard->getExp()) {
        bool flag = 0;

        for (size_t i = 0; i < countOfPrisoners; i++) {
            if (flag) {
                prisoners[i - 1] = prisoners[i];
            }

            if (prisoners[i] == &prisoner) {
                flag = 1;
            }
        }

        countOfPrisoners--;

        srand(0);

        for (size_t i = 0; i < 2; i++) {
            Prisoner* p;
            do {
                p = prisoners[rand() % countOfPrisoners];
            } while(p->getGang() != prisoner.getGang());

            prisonBreak(*p);
        }
    }
    else
    {
        guard->catchPrisoner();
    }
}

#endif
