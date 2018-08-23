#include "libs.hpp"

#ifndef RACER_HPP
#define RACER_HPP

class Racer
{
protected:
    //this will be in comp and human classes
    //char racerType[9];
    int xp;
    double coef;
    int countOfRaces;
    int countOfNormalCars;
    int countOfNitroCars;
    char* name;
    NormalCar* normalCars;
    NitroCar* nitroCars;

public:
    Racer()
    {
        xp = 0;
        coef = xp * (10 / 100); //coef chance = 10% from xp, bigger xp, bigger chance to win
        countOfRaces = 0;
        countOfNormalCars = 1;
        countOfNitroCars = 1;

        name = new char[strlen("Player1") + 1];
        assert(name != nullptr);
        strcpy(name, "Player1");

        normalCars = new NormalCar[countOfNormalCars];
        assert(normalCars != nullptr);
        NormalCar nc1;
        normalCars[0] = nc1;

        nitroCars = new NitroCar[countOfNitroCars];
        assert(nitroCars != nullptr);
        NitroCar nt1;
        nitroCars[0] = nt1;
    }

    //COR = countOfRaces
    //CON = countOfNormalCars
    //CONiC = countOfNitroCars
    Racer(const char* _name, int _xp, int COR, int CON, int CONiC, NormalCar* list1, NitroCar* list2)
    {
        xp = _xp;
        coef = xp * 0.1; //coef chance = 10% from xp, bigger xp, bigger chance to win
        countOfRaces = COR;
        countOfNormalCars = CON;
        countOfNitroCars = CONiC;

        name = new char[strlen(_name) + 1];
        assert(name != nullptr);
        strcpy(name, _name);

        normalCars = new NormalCar[countOfNormalCars];
        assert(normalCars != nullptr);

        for (size_t i = 0; i < countOfNormalCars; i++) {
            normalCars[i] = list1[i];
        }

        nitroCars = new NitroCar[countOfNitroCars];
        assert(nitroCars != nullptr);
        for (size_t i = 0; i < countOfNitroCars; i++) {
            nitroCars[i] = list2[i];
        }
    }

    Racer(const Racer& r1)
    {
        xp = r1.xp;
        coef = xp * 0.1; //coef chance = 10% from xp, bigger xp, bigger chance to win
        countOfRaces = r1.countOfRaces;
        countOfNormalCars = r1.countOfNormalCars;
        countOfNitroCars = r1.countOfNitroCars;

        name = new char[strlen(r1.name) + 1];
        assert(name != nullptr);
        strcpy(name, r1.name);

        normalCars = new NormalCar[countOfNormalCars];
        assert(normalCars != nullptr);

        for (size_t i = 0; i < countOfNormalCars; i++) {
            normalCars[i] = r1.normalCars[i];
        }

        nitroCars = new NitroCar[countOfNitroCars];
        assert(nitroCars != nullptr);
        for (size_t i = 0; i < countOfNitroCars; i++) {
            nitroCars[i] = r1.nitroCars[i];
        }
    }

    Racer& operator=(const Racer& r1)
    {
        if (this != &r1) {
            xp = r1.xp;
            coef = xp * 0.1; //coef chance = 10% from xp, bigger xp, bigger chance to win
            countOfRaces = r1.countOfRaces;
            countOfNormalCars = r1.countOfNormalCars;
            countOfNitroCars = r1.countOfNitroCars;

            name = new char[strlen(r1.name) + 1];
            assert(name != nullptr);
            strcpy(name, r1.name);

            normalCars = new NormalCar[countOfNormalCars];
            assert(normalCars != nullptr);

            for (size_t i = 0; i < countOfNormalCars; i++) {
                normalCars[i] = r1.normalCars[i];
            }

            nitroCars = new NitroCar[countOfNitroCars];
            assert(nitroCars != nullptr);
            for (size_t i = 0; i < countOfNitroCars; i++) {
                nitroCars[i] = r1.nitroCars[i];
            }
        }

        return *this;
    }

    ~Racer()
    {
        delete[] normalCars;
        delete[] nitroCars;
    }

    //Setters
    void earnXP(int newVal)
    {
        xp += newVal;
        coef = xp * 0.1;
    }

    void setCoef(double c)
    {
        coef = c;
    }

    void increaseRaces()
    {
        countOfRaces++;
    }

    void changeCountOfNormalCars(int newVal)
    {
        countOfNormalCars = newVal;
    }

    void changeCountOfNitroCars(int newVal)
    {
        countOfNitroCars = newVal;
    }

    void setNormalCarList(NormalCar* list, int size)
    {
        countOfNormalCars = size;
        delete[] normalCars;

        normalCars = new NormalCar[countOfNormalCars];
        for (size_t i = 0; i < countOfNormalCars; i++) {
            normalCars[i] = list[i];
        }
    }

    void setNitroCarList(NitroCar* list, int size)
    {
        countOfNitroCars = size;
        delete[] nitroCars;

        nitroCars = new NitroCar[countOfNitroCars];
        for (size_t i = 0; i < countOfNitroCars; i++) {
            nitroCars[i] = list[i];
        }
    }


    void buyNormalCar(NormalCar& newCar)
    {
        NormalCar* temp;
        temp = new NormalCar[countOfNormalCars];
        assert(normalCars != nullptr);

        for (size_t i = 0; i < countOfNormalCars; i++) {
            temp[i] = normalCars[i];
        }
        delete[] normalCars;

        countOfNormalCars++;
        normalCars = new NormalCar[countOfNormalCars];
        assert(normalCars != nullptr);

        for (size_t i = 0; i < countOfNormalCars - 1; i++) {
            normalCars[i] = temp[i];
        }
        normalCars[countOfNormalCars - 1] = newCar;

        delete[] temp;
    }

    void buyNitroCar(NitroCar& newCar)
    {
        NitroCar* temp;
        temp = new NitroCar[countOfNitroCars];
        assert(nitroCars != nullptr);

        for (size_t i = 0; i < countOfNitroCars; i++) {
            temp[i] = nitroCars[i];
        }

        delete[] nitroCars;

        countOfNitroCars++;
        nitroCars = new NitroCar[countOfNitroCars];
        assert(nitroCars != nullptr);

        for (size_t i = 0; i < countOfNitroCars - 1; i++) {
            nitroCars[i] = temp[i];
        }
        nitroCars[countOfNitroCars - 1] = newCar;

        delete[] temp;
    }

    //Getters
    const int getXP() const
    {
        return xp;
    }

    const int getCoef() const
    {
        return coef;
    }

    const int getCountOfRaces() const
    {
        return countOfRaces;
    }

    const int getCountOfNormalCars() const
    {
        return countOfNormalCars;
    }

    const int getCountOfNitroCars() const
    {
        return countOfNitroCars;
    }

    const char* getName() const
    {
        return name;
    }

    const NormalCar getNormalCar(int ind) const
    {
        return normalCars[ind];
    }

    const NitroCar getNitroCar(int ind) const
    {
        return nitroCars[ind];
    }

    const NormalCar* getNormalCars() const
    {
        return normalCars;
    }

    const NitroCar* getNitroCars() const
    {
        return nitroCars;
    }

    //Methods
    const void printRacer() const
    {
        cout << "Racer xp: " << xp << endl
            << "Racer coef: " << coef << endl
            << "Racer count of races: " << countOfRaces << endl
            << "Racer count of normal cars: " << countOfNormalCars << endl
            << "Racer count of nitro cars: " << countOfNitroCars << endl;

        cout << "Normal cars:\n";
        for (size_t i = 0; i < countOfNormalCars; i++) {
            normalCars[i].printCar();
        }
        cout << "--------------------------------\n";

        cout << "Nitro cars:\n";
        for (size_t i = 0; i < countOfNitroCars; i++) {
            nitroCars[i].printCar();
        }
        cout << "--------------------------------\n";
    }
};

class ComputerRacer : public Racer
{
private:
    char* racerType;

public:
    ComputerRacer() : Racer()
    {
        racerType = new char[9];
        assert(racerType != nullptr);
        strcpy(racerType, "Computer");
    }

    ComputerRacer(const char* _name, int _xp, int COR, int CON, int CONiC, NormalCar* list1, NitroCar* list2) : Racer(_name, _xp, COR, CON, CONiC, list1, list2)
    {
        racerType = new char[strlen("Computer") + 1];
        assert(racerType);
        strcpy(racerType, "Computer");
    }

    ComputerRacer& operator=(const ComputerRacer& pc1)
    {
        if (this != &pc1) {
            Racer::operator=(pc1);
            racerType = new char[strlen("Computer") + 1];
            assert(racerType);
            strcpy(racerType, "Computer");
        }

        return *this;
    }

    ~ComputerRacer()
    {
        delete racerType;
    }

    const char* getType() const
    {
        return racerType;
    }

    const void printPCRacer() const
    {
        cout << "Type: " << racerType << endl;
        Racer::printRacer();
    }
};

class HumanRacer : public Racer
{
private:
    int money;
    char* racerType;

public:
    HumanRacer() : Racer()
    {
        racerType = new char[6];
        assert(racerType != nullptr);
        strcpy(racerType, "Human");
    }

    HumanRacer(const char* _name, int _xp, int COR, int CON, int CONiC, NormalCar* list1, NitroCar* list2) : Racer(_name, _xp, COR, CON, CONiC, list1, list2)
    {
        money = 0;
        racerType = new char[strlen("Human") + 1];
        assert(racerType != nullptr);
        strcpy(racerType, "Human");
    }

    HumanRacer(const HumanRacer& hr1) : Racer(hr1)
    {
        money = hr1.money;
        racerType = new char[strlen(hr1.racerType) + 1];
        assert(racerType != nullptr);
        strcpy(racerType, hr1.racerType);
    }

    HumanRacer& operator=(const HumanRacer& hr1)
    {
        if (this != &hr1) {
            Racer::operator=(hr1);
            money = hr1.money;
            racerType = new char[strlen("Human") + 1];
            assert(racerType != nullptr);
            strcpy(racerType, "Human");
        }

        return *this;
    }

    ~HumanRacer()
    {
        delete racerType;
    }

    void buyNormalCar(const NormalCar& newCar)
    {
        NormalCar* temp;
        temp = new NormalCar[countOfNormalCars];
        assert(normalCars != nullptr);

        for (size_t i = 0; i < countOfNormalCars; i++) {
            temp[i] = normalCars[i];
        }
        delete[] normalCars;

        countOfNormalCars++;
        money -= newCar.getPrice();
        normalCars = new NormalCar[countOfNormalCars];
        assert(normalCars != nullptr);

        for (size_t i = 0; i < countOfNormalCars - 1; i++) {
            normalCars[i] = temp[i];
        }
        normalCars[countOfNormalCars - 1] = newCar;

        delete[] temp;
    }

    void buyNitroCar(const NitroCar& newCar)
    {
        NitroCar* temp;
        temp = new NitroCar[countOfNitroCars];
        assert(nitroCars != nullptr);

        for (size_t i = 0; i < countOfNitroCars; i++) {
            temp[i] = nitroCars[i];
        }

        delete[] nitroCars;

        countOfNitroCars++;
        money = money - newCar.getPrice();

        nitroCars = new NitroCar[countOfNitroCars];
        assert(nitroCars != nullptr);

        for (size_t i = 0; i < countOfNitroCars - 1; i++) {
            nitroCars[i] = temp[i];
        }
        nitroCars[countOfNitroCars - 1] = newCar;

        delete[] temp;
    }

    void upgradeNormalCar(int ind, int cost)
    {
        money -= cost;
        normalCars[ind].upgradeCar();
    }

    void upgradeNitroCar(int ind, int cost)
    {
        money -= cost;
        normalCars[ind].upgradeCar();
    }

    const char* getType() const
    {
        return racerType;
    }

    const int getMoney() const
    {
        return money;
    }

    const void printHumanRacer()
    {
        cout << "Money: " << money << endl
            << "Type: " << racerType << endl;
        Racer::printRacer();
    }
};

#endif
