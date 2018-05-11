#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

/*
Да се реализира клас Билет (за театрално представление), който поддържа
информация за името на представлението и цена.
*/
class Ticket
{
private:
    char* eventName;
    double price;

public:
    Ticket();
    Ticket(char*, double);
    Ticket(const Ticket&);
    Ticket& operator=(const Ticket&);
    ~Ticket();

    const void print() const;

    //Getters
    const char* getEventName() const;
    const double getPrice() const;

    //Setters
    void setPrice(double);
};

Ticket::Ticket()
{
    eventName = new char(2);
    eventName[0] = ' ';
    price = 0.0;
}

Ticket::Ticket(char* _eventName, double _price)
{
    eventName = new char(strlen(_eventName) + 1);
    assert(eventName != nullptr);

    strcpy(eventName, _eventName);
    price = _price;
}

Ticket::Ticket(const Ticket& t1)
{
    eventName = new char[strlen(t1.eventName) + 1];

    assert(eventName != nullptr);

    strcpy(eventName, t1.eventName);
    price = t1.price;
}

Ticket& Ticket::operator=(const Ticket& t1)
{
    delete eventName;
    eventName = new char[strlen(t1.eventName) + 1];
    assert(eventName != nullptr);

    strcpy(eventName, t1.eventName);
    price = t1.price;

    return *this;
}

Ticket::~Ticket()
{
    delete eventName;
}

const void Ticket::print() const
{
    cout << "Event: " << eventName << ", Price: " << price << endl;
}

const char* Ticket::getEventName() const
{
    return eventName;
}

const double Ticket::getPrice() const
{
    return price;
}

void Ticket::setPrice(double _price)
{
    price = _price;
}

class DiscountTicket : public Ticket
{
private:
    char* owner;

public:
    DiscountTicket(char*, char*, double);

    const void print() const;
};

/*
Съществува още билет с намаление, чиято цена е 50% от цената на нормалния.
Той е поименен и важи след предоставяне на подходящ документ за идентификация на името, в момента на закупуването.
*/
DiscountTicket::DiscountTicket(char* _owner, char* _event, double _price): Ticket(_event, (_price/2))
{
    owner = new char[strlen(_owner) + 1];
    assert(owner != nullptr);

    strcpy(owner, _owner);
}

const void DiscountTicket::print() const
{
    cout << "Owner: " << owner << endl;
    Ticket::print();
}

/*
Съществува и Групов билет, чиято цена се намаля с 2 лева за всеки
човек след 20-тия (ако са по-малко от 20 няма намаление).
*/
class GroupTicket : public Ticket
{
private:
    int countOfMembers;

public:
    GroupTicket(char*, double, int);
    const void print() const;
};

GroupTicket::GroupTicket(char* _event, double _price, int _countOfMembers): Ticket(_event, _price), countOfMembers(_countOfMembers)
{

    if (countOfMembers > 20) {
        setPrice(_price - (countOfMembers - 20)*2);
    }
}

const void GroupTicket::print() const
{
    cout << "Count of memebers: " << countOfMembers << endl;
    Ticket::print();
}

/*
Да се напише функция, която приема множество от билети (нормални, групови и с намаление)
за дадено театрално представление и извежда общата стойност на билетите.
*/
template<typename T>
double total(T* ticketList)
{
    double total = 0;

    for (size_t i = 0; i < 3; i++) {
        total += ticketList[i].getPrice();
    }

    return total;
}

int main() {
    Ticket t1("Rammstein", 90);

    Ticket t2(t1);

    Ticket t3;

    t3=t1;

    t1.print();
    t2.print();
    t3.print();

    DiscountTicket d1("Radoslav", "Rammstein", 90);
    d1.print();

    GroupTicket g1("Rammstein", 90, 25);
    g1.print();

    Ticket list[3];

    list[0]=t1;
    list[1]=t1;
    list[2]=t1;

    cout << total<Ticket>(list) << endl;

    return 0;
}
