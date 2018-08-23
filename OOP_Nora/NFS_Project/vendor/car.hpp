#ifndef CAR_HPP
#define  CAR_HPP

class Car
{
private:
    //char carType[9];
    int horsePowers; //power of engine in horse powers
    int handling; //number in the range [1,..,13]. Колкото е по-голяма числото, толкова по-добра за управление е колата (стабилност, завиване, спиране и т.н.)
    double topSpeed; //The highest possible speed, that can reaches
    int acceleration; //number that shows how many seconds it takes to the car to accelarate from 0-100, the lower the better!

public:
    //The Big Four
    Car()
    {
        horsePowers = 100;
        handling = 1;
        topSpeed = 200;
        acceleration = 1; // value between 0 and 1
        cout << acceleration << endl;
    }

    //Car(int, int, int, double);
    //Car(const Car&);

    //Getters

    //Setters

    //Redefined operator << >>

    //Functionalities
    const int getAcceleration() const
    {
        return acceleration;
    }

    const void print() const
    {
        cout << "Car horse powers: " << horsePowers << endl
            << "Car handling:" << handling << endl
            << "Car top speed: " << topSpeed << endl
            << "Car acceleration from 0 to 100: " << acceleration << " seconds\n";
    }
};

class NormalCar
{
private:
    char carType[7];
    int horsePowers; //power of engine in horse powers
    int handling; //number in the range [1,..,13]. Колкото е по-голяма числото, толкова по-добра за управление е колата (стабилност, завиване, спиране и т.н.)
    double topSpeed; //The highest possible speed, that can reaches
    int acceleration;

public:
    NormalCar(int, int, int, double)
    {
        horsePowers = 100;
        handling = 1;
        topSpeed = 200;
        acceleration = 1; // value between 0 and 1
        cout << acceleration << endl;
    }

    const void print() const
    {
        cout << "Car horse powers: " << horsePowers << endl
            << "Car handling:" << handling << endl
            << "Car top speed: " << topSpeed << endl
            << "Car acceleration from 0 to 100: " << acceleration << " seconds\n";
    }
};

#endif
