#ifndef CAR_HPP
#define  CAR_HPP

class Car
{
protected:
    int horsePowers;
    int handling;
    int acceleration;
    int topSpeed;
    int price;
    char* brand;

public:
    //Constructors and operators;
    Car()
    {
        horsePowers = 100;
        handling = 1;
        topSpeed = 200;
        acceleration = 1;
        brand = new char[7];
        assert(brand != nullptr);
        strcpy(brand, "Nissan");

        cout << "Car()\n";
    }

    //handling - 1 to 13
    //acceleration - 1 to 11
    //handling + acceleration
    //13 + 11 = 24
    //1 + 1 = 2
    //100 hp
    //topSpeed = hp + (handling + acceleration + 1) * 15
    //airflow resistance = 2 * ( handling + acceleration)

    Car(const char* _brand, int _hp, int _handling, int _acc)
    {
        horsePowers = _hp;
        handling = _handling;
        acceleration = _acc;
        //we use airResistance to calculate almost real speed of
        //the car based on horse powers, acceleration, handling
        int airResistance = 3 * ( handling + acceleration); //air flow against car
        topSpeed = (2 * horsePowers - airResistance) / pow(handling * acceleration, (1/3));
        price = horsePowers * 110;

        brand = new char[strlen(_brand) + 1];
        assert(brand != nullptr);
        strcpy(brand, _brand);

        cout << "Car(const char*, int, int, int)\n";
    }

    Car(const Car& c1)
    {
        horsePowers = c1.horsePowers;
        handling = c1.handling;
        acceleration = c1.acceleration;
        topSpeed = c1.topSpeed;
        price = c1.price;
        brand = c1.brand;

        cout << "Car(const Car&)\n";
    }

    Car& operator=(const Car& c1)
    {
        if (this != &c1) {
            delete brand;
            horsePowers = c1.horsePowers;
            handling = c1.handling;
            acceleration = c1.acceleration;
            topSpeed = c1.topSpeed;
            price = c1.price;
            brand = c1.brand;
        }

        cout << "Car& operator=(const Car&)\n";

        return *this;
    }

    ~Car()
    {
        cout << "~Car()\n";
        delete brand;
    }

    //Setters
    void changeHP(int _hp)
    {
        horsePowers = _hp;
    }

    void changeHandling(int _hnd)
    {
        handling = _hnd;
    }

    void changeAcceleration(int _acc)
    {
        acceleration = _acc;
    }

    void changeTopSpeed(int _topSpeed)
    {
        topSpeed = _topSpeed;
    }

    void changePrice(int newPrice)
    {
        price = newPrice;
    }

    void upgradeCar()
    {
        horsePowers += 10;
        handling += 1;
        acceleration += 1;
        topSpeed += 10;
        price += 100;
    }

    //Getters
    const int getHP() const
    {
        return horsePowers;
    }

    const int getHandling() const
    {
        return handling;
    }

    const int getAcceleration() const
    {
        return acceleration;
    }

    const int getTopSpeed() const
    {
        return topSpeed;
    }

    const int getPrice() const
    {
        return price;
    }

    const char* getBrand() const
    {
        return brand;
    }

    //Methods
    const void printCar() const
    {
        cout << "Car properties:\n"
            << "HP: " << horsePowers << endl
            << "Handling: " << handling << endl
            << "Acceleration: " << acceleration << endl
            << "Top speed: " << topSpeed << endl
            << "Price: " << price << endl;
    }
};

class NormalCar : public Car
{
private:
    char* carType;

public:
    //Big 4 and default constructor
    NormalCar()
    {
        Car();
        carType = new char[7];
        assert(carType != nullptr);
        strcpy(carType, "Normal");
        cout << "NormalCar()\n";
    }

    NormalCar(const char* _brand, int _hp = 100, int _handling = 1, int _acc = 1)
     : Car(_brand, _hp, _handling, _acc)
    {
        carType = new char[7];
        assert(carType != nullptr);
        strcpy(carType, "Normal");
        cout << "NormalCar(const char*, int, int, int)\n";
    }

    NormalCar(const NormalCar& nc)
     : Car(nc)
    {
        carType = new char[7];
        assert(carType != nullptr);
        strcpy(carType, "Normal");
        cout << "NormalCar(const NormalCar&)\n";
    }

    NormalCar& operator=(const NormalCar& nc)
    {
        if (this != &nc) {
            Car::operator=(nc);
        }

        cout << "NormalCar& operator=(const NormalCar&)\n";

        return *this;
    }

    // NormalCar& operator[](int ind)
    // {
    //     return *this;
    // }

    ~NormalCar()
    {
        cout << "~NormalCar()\n";
        delete carType;
    }

    const char* getCarType() const
    {
        return carType;
    }

    //Methods
    const void printCar() const
    {
        Car::printCar();
        cout << "Type: " << carType << endl;
    }
};

class NitroCar : public Car
{
private:
    char* carType;
    int bonusPoints;
    int numRaces; //Count how many times this car had a participation in race

public:
    //Big 4 and default constructor
    NitroCar()
    {
        Car();
        carType = new char[6];
        assert(carType != nullptr);
        strcpy(carType, "Nitro");
        cout << "NitroCar()\n";
    }

    NitroCar(const char* _brand, int _hp = 150, int _handling = 1, int _acc = 2)
     : Car(_brand, _hp, _handling, _acc)
    {
        carType = new char[6];
        assert(carType != nullptr);
        strcpy(carType, "Nitro");
        bonusPoints = 0;
        numRaces = 0;
        cout << "NitroCar(const char*, int, int, int)\n";
    }

    NitroCar(const NitroCar& nt)
     : Car(nt)
    {
        carType = new char[6];
        assert(carType != nullptr);
        strcpy(carType, "Nitro");
        bonusPoints = nt.bonusPoints;
        numRaces = nt.numRaces;
        cout << "NitroCar(const NitroCar&)\n";
    }

    NitroCar& operator=(const NitroCar& nt)
    {
        if (this != &nt) {
            Car::operator=(nt);
            bonusPoints = nt.bonusPoints;
            numRaces = nt.numRaces;
        }

        cout << "NitroCar& operator=(const NitroCar&)\n";

        return *this;
    }

    ~NitroCar()
    {
        cout << "~NitroCar()\n";
        delete carType;
    }

    //Setters
    void addBonusPoints(int _points)
    {
        bonusPoints += _points;
    }

    void addRace()
    {
        numRaces++;
    }

    //Getters
    const int getBonusPointsVal() const
    {
        return bonusPoints;
    }

    const int getNumRaces() const
    {
        return numRaces;
    }

    const char* getCarType() const
    {
        return carType;
    }

    //Methods
    const void printCar() const
    {
        Car::printCar();
        cout << "Type: " << carType << endl;
    }
};

#endif
