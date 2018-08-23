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

class Feeling
{
protected:
	char name[101]; //Love, Sadness, Pride
	double power;

public:
	Feeling(char* _name)
	{
		strcpy_s(name, _name);
		power = 0.1; //10%
	}
	
	void changePower(double _pow)
	{
		power = _pow;
	}

	const double getPower() const
	{
		return power;
	}

	const void print() const
	{
		cout << name << " " << power << endl;
	}
};

class Love : public Feeling
{
private:

public:
	Love() : Feeling("Love"){}

	const void printEmoji() const
	{
		cout << "  *     *  \n"
			<< "*   * *   *\n"
			<< " *   *   *\n"
			<< "  *     *\n"
			<< "   *   *\n"
			<< "     *\n";
	}
};

class Sadness : public Feeling
{
public:
	Sadness() : Feeling("Sadness") {}

	const void printEmoji() const
	{
		cout << ":(\n";
	}
};

class Proud : public Feeling
{
public:
	Proud() : Feeling("Proud"){}

	const void printEmoji() const
	{
		cout << "-----------\n";
		cout << "===========\n";
		cout << "***********\n";
	}
};

template <typename T>
class Spectator;

template <typename T>
class LivePerformance : public Love, public Sadness, public Proud
{
private:
	char entertainer[101];
	Spectator<T>** listOfSpecs;
	int countOfSpecs;

public:
	LivePerformance(char* _player, Spectator<T>** _listOfSpecs, int count)
	{
		strcpy_s(entertainer, _player);

		countOfSpecs = count;

		for (size_t i = 0; i < countOfSpecs; i++)
		{
			listOfSpecs[i] = _listOfSpecs[i];
		}
	}

	const void printPowers() const
	{
		int temp = 0;
		int i = 0;
		while (listOfSpecs[i] != nullptr)
		{
			temp += listOfSpecs[i]->getPower();

			i++;
		}

		cout << "Power of feelings: " << temp << endl;
	}
};

template <typename T>
class Spectator
{
private:
	Love l;
	Sadness ss;
	Proud pr;
	T ticket; //NormalTicket<T> or GroupTicket<T>

public:
	Spectator(char* feeling, T _ticket)
	{
		if (feeling)
		{

		}
	}
};

int main()
{
	Feeling f("Love");
	f.print();

	Love l;
	l.printEmoji();

	Sadness s;
	s.printEmoji();

	Proud p;
	p.printEmoji();

	system("PAUSE");
	return 0;
}