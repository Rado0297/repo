#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

class Car
{
private:
    int productYear;
    char regNumber[16];
    char brandAndModel[31];
    char owner[31];

public:
    //Deafault Constructor
    //Car();

    //Constructor
    Car(int, char*, char*, char*);

    //Copy Constructor
    Car(const Car&);

    //Operator=
    Car& operator=(const Car&);

    //Destructor

    //Getters
    int getProductYear() const;
    const char* getRegNumber();
    const char* getBrandAndModel();
    const char* getOwner();

    //Setters
    void changeProductYear(int);
    void changeRegNumber(char*);
    void changeBrandAndModel(char*);
    void changeOwner(char*);

    //Others
    void print();
};

Car::Car(int _year = 0, char* _regnumber = "None", char* _model = "None", char* _owner = "None")
    : productYear(_year)
{
    strcpy(regNumber, _regnumber);
    strcpy(brandAndModel, _model);
    strcpy(owner, _owner);
}

Car::Car(const Car& c1)
{
    productYear = c1.productYear;
    strcpy(regNumber, c1.regNumber);
    strcpy(brandAndModel, c1.brandAndModel);
    strcpy(owner, c1.owner);
}

//Operator=
Car& Car::operator=(const Car& c1)
{
    productYear = c1.productYear;
    strcpy(regNumber, c1.regNumber);
    strcpy(brandAndModel, c1.brandAndModel);
    strcpy(owner, c1.owner);

    return *this;
}

//Getters
int Car::getProductYear() const
{
    return productYear;
}

const char* Car::getRegNumber()
{
    return regNumber;
}

const char* Car::getBrandAndModel()
{
    return brandAndModel;
}

const char* Car::getOwner()
{
    return owner;
}

//Setters
void Car::changeProductYear(int _year)
{
    productYear = _year;
}

void Car::changeRegNumber(char* _regnumber)
{
    strcpy(regNumber, _regnumber);
}

void Car::changeBrandAndModel(char* _mod)
{
    strcpy(brandAndModel, _mod);
}

void Car::changeOwner(char* _owner)
{
    strcpy(owner, _owner);
}

//Others
void Car::print()
{
    cout << "Brand and model: " << brandAndModel << endl;
    cout << "Year of product: " << productYear << endl;
    cout << "Registartion number: " << regNumber << endl;
    cout << "Owner: " << owner << endl;
}

//Tests for class Car
void test0()
{
    //Test for Default Constructors
    cout << "++++++++++++++++++++++++++++++ Test0 +++++++++++++++++++++++++++++++++++++\n";

    Car car0(2000);
    car0.print();

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}


void test1()
{
    //Test for Copy constructor
    cout << "++++++++++++++++++++++++++++++ Test1 +++++++++++++++++++++++++++++++++++++\n";

    Car car1(1967, "OB7777PP", "Shelby Mustang GT500", "Radoslav");
    Car car2 = car1;

    car1.print();
    cout << "--------------------------------------------------------------------------\n";
    car2.print();

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

void test2()
{
    //Test for Operator=
    cout << "++++++++++++++++++++++++++++++ Test2 +++++++++++++++++++++++++++++++++++++\n";

    Car car1(1967, "OB0770AP", "Shelby Mustang GT500", "Radoslav");
    Car car2(2001, "CA7887BH", "Nissan Sunny", "Ivan Ivan");

    Car car3 = car2;
    car3 = car1;
    car3.print();

    Car car5(2012, "OB7777BH", "Nissan GTR", "Rado"),
        car4(1988, "OB7953AM", "Nissan Sunny Florida", "Krasi");

    car5.print();
    car4.print();

    car5 = car4;
    car4.changeOwner("Azz");

    car5.print();
    car4.print();

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

void test3()
{
    //Test for Setters
    cout << "++++++++++++++++++++++++++++++ Test3 +++++++++++++++++++++++++++++++++++++\n";

    Car car1(1967, "OB0770AP", "Shelby Mustang GT500", "Radoslav");
    car1.changeProductYear(2001);
    car1.changeRegNumber("CA7887BH");
    car1.changeBrandAndModel("Nissan Sunny");
    car1.changeOwner("Krasimir");
    car1.print();

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

void test4()
{
    //Test for Getters
    cout << "++++++++++++++++++++++++++++++ Test4 +++++++++++++++++++++++++++++++++++++\n";

    Car car1(1967, "OB0770AP", "Shelby Mustang GT500", "Radoslav");
    cout << car1.getProductYear() << endl;
    cout << car1.getRegNumber() << endl;
    cout << car1.getBrandAndModel() << endl;
    cout << car1.getOwner() << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

void test5()
{
    //Test for dynamic memory
    cout << "++++++++++++++++++++++++++++++ Test5 +++++++++++++++++++++++++++++++++++++\n";

    //Allocating dynamic memory for matrix array
    int **array = new int*[10];
    assert(array != NULL);

    for (size_t i = 0; i < 10; i++) {
        array[i] = new int[5];
        assert(array[i] != NULL);
    }

    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 5; j++) {
            array[i][j] = j + 1;
        }
    }

    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 5; j++) {
            cout << array[i][j];

            if (i < 10) {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (size_t i = 0; i < 10; i++) {
        delete[] array[i];
    }
    delete[] array;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

int main() {
    //test0();
    //test1();
    test2();
    //test3();
    //test4();
    //test5();


    return 0;
}
