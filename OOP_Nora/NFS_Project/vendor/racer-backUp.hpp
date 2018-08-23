#include "libs.hpp"

#ifndef RACER_HPP
#define RACER_HPP

class Racer
{
private:
    char* racerType;
    int xp;
    int money;
    int countOfRaces;
    Car** cars;
    int carsSize;



    //
    // char racerType[9]; //type: human or computer
    // int xp; //experience points
    // int money; //computer doesn't need them
    // int countOfRaces; //countOfRaces is number of races that every racer was tooks part in
    // //Car car; //object car, owned by the racer. It can be a list of cars as in real nfs

public:
    //The Big Four
    Racer()
    {
        racerType = new char[9];
        assert(racerType != nullptr);
        strcpy(racerType, "Computer");
        xp = 1;
        money = 0;
        countOfRaces = 0;
        carsSize = 1;
        cars = new Car*[1];
        assert(cars != nullptr);
        cars[0];
    }
    Racer(char*, int, int, int);
    Racer(const Racer&);
    Racer& operator=(const Racer&);
    ~Racer()
    {
        delete racerType;
    }

    //Getters
    const char* getRacerType() const;
    const int getXP() const;
    const int getMoney() const;
    const int getCountOfRaces() const;

    //Setters
    void setRacerType(char*);
    void setXP(int);
    void setMoney(int);
    void setCountOfRaces(int);

    //Functionalities
    const void print() const
    {
        cout << "Racer type: " <<  racerType << endl
            << "Racer experience (xp): " << xp << endl
            << "Racer money: " << money << endl
            << "Racer count of races: " << countOfRaces << endl
            << "Racer count of cars: " << carsSize << endl;

    }

    //Friend functions
    friend std::ostream& operator<<(std::ostream& out, const Racer& r1);
    friend std::istream& operator>>(std::istream& in, Racer& r1);
};


///!!!! Hierarchy
class ComputerRacer
{
private:
    char racerType[9]; //type: human or computer
    int xp; //experience points
    int countOfRaces; //countOfRaces is number of races that every racer was tooks part in
    //Car car; //object car, owned by the racer. It can be a list of cars as in real nfs

public:
    //The Big Four
    ComputerRacer();
    ComputerRacer(char*, int, int, int);
    ComputerRacer(const Racer&);
    ComputerRacer& operator=(const Racer&);
    //~Racer();

    //Getters
    const char* getRacerType() const;
    const int getXP() const;
    const int getCountOfRaces() const;

    //Setters
    void setXP(int);
    void setCountOfRaces(int);

    //Functionalities
    const void print() const;

    //Friend functions
    friend std::ostream& operator<<(std::ostream& out, const Racer& r1);
    friend std::istream& operator>>(std::istream& in, Racer& r1);
};

class Human : public ComputerRacer
{
//...
};

// class Human : public Racer
// {
// private:
//
//
// public:
//
// };

// class Computer : public Racer
// {
//
// };

#endif
