#include "libs.hpp"

#ifndef RACER_HPP
#define RACER_HPP

class ComputerRacer
{
private:
    char racerType[9]; //type: human or computer
    int xp; //experience points
    int coef; //coefficient of chance
    int countOfRaces; //countOfRaces is number of races that every racer was tooks part in
    int carsCount;
    Car** cars;
    //NormalCar** normalCars; //object car, owned by the racer. It can be a list of cars as in real nfs
    //NitroCar** nitroCars;

public:
    //The Big Four
    ComputerRacer()
    {
        strcpy(racerType, "Computer");
        xp = 10;
        coef = xp * (10/100); //some random formula
        carsCount = 1;
        //cars = new Car*[carsCount];
        countOfRaces = 0;
        cars = new Car*[1];
        Car temp;
        //cout << "Temp : " << temp.getAcceleration() << endl;
        cars[carsCount - 1] = &temp;
        cars[carsCount - 1]->print();
        //cout << "Cars[0]: " << cars[0]->getAcceleration() << endl;
    }

    //ComputerRacer(char*, int, int, int);
    //ComputerRacer(const ComputerRacer&);
    //ComputerRacer& operator=(const ComputerRacer&);
    //~Racer();

    //Getters
    const char* getRacerType() const;
    const int getXP() const;
    const int getCountOfRaces() const;

    //Setters
    void setXP(int);
    void setCountOfRaces(int);

    //Functionalities
    const void printRacer() const
    {
        for (size_t i = 0; i < carsCount; i++) {
            cout << cars[0]->getAcceleration() << "SDF " << endl;
        }

        cout << "Racer type: " << racerType << endl
            << "Racer expirience: " << xp << endl
            << "Racer coef: " << coef << endl
            << "Racer count of races: " << countOfRaces << endl;


    }

    //Friend functions
    friend std::ostream& operator<<(std::ostream& out, const ComputerRacer& r1);
    friend std::istream& operator>>(std::istream& in, ComputerRacer& r1);
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
