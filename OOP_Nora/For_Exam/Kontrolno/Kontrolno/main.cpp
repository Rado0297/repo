#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

template <typename T>
class Ticket
{
protected:
	char* nameOfEvent;
	double pricePerPerson;
	int row;
	int seat;
	T id;

public:
	Ticket()
	{
		nameOfEvent = new char[1];
		assert(nameOfEvent != nullptr);
		nameOfEvent = '\0';
		pricePerPerson = 0;
		row = 0;
		seat = 0;
		id = 0;
	}

	Ticket(char* _name, double _price, int _row, int _seat, T _id)
	{
		nameOfEvent = new char[strlen(_name) + 1];
		assert(nameOfEvent != nullptr);
		strcpy(nameOfEvent, _name);
		pricePerPerson = _price;
		row = _row;
		seat = _seat;
		id = _id;
	}
	/*
	Ticket(const Ticket& t1)
	{
		nameOfEvent = new char[strlen(t1.nameOfEvent) + 1];
		assert(nameOfEvent != nullptr);
		strcpy(nameOfEvent, t1.nameOfEvent);
		pricePerPerson = t1.pricePerPerson;
		row = t1.row;
		seat = t1.seat;
		id = t1.id;
	}

	Ticket& operator=(const Ticket& t1)
	{
		if (this != &t1)
		{
			delete nameOfEvent;
			nameOfEvent = new char[strlen(t1.nameOfEvent) + 1];
			assert(nameOfEvent != nullptr);
			strcpy(nameOfEvent, t1.nameOfEvent);
			pricePerPerson = t1.pricePerPerson;
			row = t1.row;
			seat = t1.seat;
			id = t1.id;
		}

		return *this;
	}
	*/

	~Ticket()
	{
		delete nameOfEvent;
	}

	//Setters
	void setName(char* _name)
	{
		delete nameOfEvent;
		nameOfEvent = new char[strlen(_name) + 1];
		assert(nameOfEvent != nullptr);
		strcpy(nameOfEvent, _name);
	}

	void setPrice(double _price)
	{
		pricePerPerson = _price;
	}

	void setID(T _id)
	{
		id = _id;
	}

	void changeRow(int _row)
	{
		row = _row;
	}

	void changeSeat(int _seat)
	{
		seat = _seat;
	}

	//Getters
	const char* getName() const
	{
		return nameOfEvent;
	}

	const double getPrice() const
	{
		return pricePerPerson;
	}
	
	const int getRow() const
	{
		return row;
	}

	const int getSeat() const
	{
		return seat;
	}

	const T getID() const
	{
		return id;
	}
};

template <typename T>
class NormalTicket : public Ticket<T>
{
private:
	char* buyer;

public:
	NormalTicket() : Ticket()
	{
		buyer = new char[1];
		assert(buyer != nullptr);
		buyer = '\0';
	}

	NormalTicket(char* _name, double _price, int _row, int _seat, T _id, char* _buyer) : Ticket(_name, _price, _row, _seat, _id)
	{
		buyer = new char[strlen(_buyer) + 1];
		assert(buyer != nullptr);
		strcpy(buyer, _buyer);
	}
	
	~NormalTicket()
	{
		delete buyer;
	}

	void changeBuyer(char* _newB)
	{
		buyer = new char[strlen(_newB) + 1];
		assert(buyer != nullptr);
		strcpy(buyer, _newB);
	}

	const char* getBuyer() const
	{
		return buyer;
	}
};

template <typename T>
class GroupTicket
{
private:
	NormalTicket<T>** tickets;
	int countOfPeople;

public:
	//Ticket(char* _name, double _price, int _row, int _seat, T _id)
	GroupTicket(int countOf, char** _names, double _price, int* _rows, int* _seats, T* _ids)
	{
		for (size_t i = 0; i < countOf; i++)
		{
			tickets[i](_names[i], (_price - 1), _rows[i], _seats[i], _ids[i]);
		}
	}

	const NormalTicket<T>** getTicketsArray() const
	{
		return tickets;
	}

	const int getCountOfPeople() const
	{
		return countOfPeople;
	}

	const void print() const
	{
		for (size_t i = 0; i < 20; i++)
		{
			cout << tickets[i]->getPrice();
		}
	}
};

/*
template <typename T>
void priceAndPeople(NormalTicket<T>** nt , int countOfNT, GroupTicket<T>** gt, int countOfGT)
{
int totalPrice = 0;
int totalCountOfPeople = 0;

for (size_t i = 0; i < countOfNT; i++)
{
totalPrice += (nt[i]->getTicketsArray())->getPrice();
i++;
}

for (size_t i = 0; i < countOfNT; i++)
{
totalCountOfPeople ++;
i++;
}

for (size_t i = 0; i < countOfGT; i++)
{
totalPrice += (gt[i]->getTicketsArray())->getPrice();
i++;
}

for (size_t i = 0; i < countOfGT; i++)
{
totalCountOfPeople++;
i++;
}

cout << "Total price: " << totalPrice << endl
<< "Total people: " << totalCountOfPeople << endl;
}
*/

template <typename T>
void priceAndPeople(NormalTicket<T>** nt, GroupTicket<T>** gt)
{
	int totalPrice = 0;
	int totalCountOfPeople = 0;

	int i = 0;

	while (nt[i] != nullptr)
	{
		totalPrice += (nt[i]->getTicketsArray())->getPrice();
		i++;
	}

	i = 0;
	while (nt[i] != nullptr)
	{
		totalCountOfPeople ++;
		i++;
	}

	i = 0;
	while (gt[i] != nullptr)
	{
		totalPrice += (gt[i]->getTicketsArray())->getPrice();
		i++;
	}

	i = 0;
	while (gt[i] != nullptr)
	{
		totalCountOfPeople++;
		i++;
	}

	cout << "Total price: " << totalPrice << endl
		<< "Total people: " << totalCountOfPeople << endl;
}

int main()
{
	Ticket<int> t1;
	NormalTicket<int>** t2;
	NormalTicket<int> t3;
	NormalTicket<int> t4;
	GroupTicket<int>** tg;

	priceAndPeople<int>(t2, tg);

	system("PAUSE");
	return 0;
}