#include "libs.hpp"

#ifndef JAIL_HPP
#define JAIL_HPP

class Jail{
private:


public:
    bool cells[4][20];


private:
    bool cells[4][20];
    int number_guards, number_prisoners;
    Guard** guards;
    Prisoner** prisoners;
    void copyPrison(const Prison&);
public:
    Prison();
    ~Prison();
    Prison(const Prison&);
    Prison& operator=(const Prison&);
    void hire_guard(Guard&);
    void accept_prisoner(Prisoner&);
    void hire_guard();
    void accept_prisoner();
    void iterate_days(int)const;
    void prison_break(const Prisoner&);
};

#endif
