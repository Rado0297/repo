#include <iostream>
#include <cstring>
#include <cassert>
using std::cout;

template<typename T>
class Ticket {
private:
	char* name;
	T id;
	void del();
	void copy(const Ticket<T>& other);
public:
	static int cnt;
	double price;

	Ticket();
	Ticket(char* _name,double _price,T id);
	Ticket(const Ticket<T>& other);
	Ticket<T>& operator=(const Ticket<T>& other);
	~Ticket();
	char* getName()const;
	virtual double getPrice()const = 0;
	virtual int getSeatNum()const = 0;
	T getId()const;
	void setName(char* _name);
	void setPrice(double _price);
	void setId(T _id);
	void printTicket();

};

int Ticket<int>::cnt = 0;

template <typename T>
class NormalTicket : public Ticket<T>
{
public:
	NormalTicket();
	NormalTicket(char* , double,T  );
	NormalTicket(const NormalTicket& other);
	NormalTicket<T>& operator=(const NormalTicket&);
	double getPrice()const ;
	int getSeatNum()const;

};

template<typename T>
class GroupTicket :public Ticket<T>
{
private:
	int numofpeople;
	void copy(const GroupTicket<T>&);
public:
	GroupTicket();
	GroupTicket(char*, double, T,int);
	GroupTicket(const GroupTicket<T>&);
	 GroupTicket<T>& operator=(const GroupTicket<T>&);
	void printTicket();
	double getPrice()const;
	int getSeatNum()const;

};

template<typename T>
void printAllPricesandSeats(Ticket<T>**,int);

template<typename T>
void Ticket<T>::copy(const Ticket<T>& other) {
	int size = strlen(other.name) + 1;
	name = new char[size ];
	strcpy_s(name, size, other.name);
	price = other.price;
	id = other.id;
}

template<typename T>
void Ticket<T>::del() {
	delete [] name;
}

template<typename T>
Ticket<T>::Ticket():name(nullptr), price(0),id(0) {}

template<typename T>
Ticket<T>& Ticket<T>::operator=(const Ticket<T>& other) {
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

template<typename T>
Ticket<T>::Ticket<T>(char* _name, double _price, T _id) {
	assert(_name != NULL);
	int size = strlen(_name) + 1;
	name = new char[size];
	strcpy_s(name,size,_name);
	price = _price;
	id = _id;
	cnt++;
}

template<typename T>
Ticket<T>::Ticket(const Ticket<T>& other)
{
	copy(other);
}

template<typename T>
Ticket<T>::~Ticket() {
	del();
}

template<typename T>
char* Ticket<T>::getName()const {
	return name;
}

template<typename T>
double Ticket<T>::getPrice()const {
	return price;
}

template<typename T>
T Ticket<T>::getId()const {
	return id;
}

template<typename T>
void Ticket<T>::setName(char* _name) {
	int size = strlen(_name) + 1;
	name = new char[size];
	strcpy_s(name, size, _name);
}

template<typename T>
void Ticket<T>::setPrice(double _price) {
	price = _price;
}

template<typename T>
void Ticket<T> ::setId(T _id) {
	id = _id;
}

template<typename T>
void Ticket<T>::printTicket() {
	cout << "Name of the performance: ";
	int size = strlen(name);
	for (int i = 0; i <size; i++) {
		cout << name[i];
	}
	cout << "\nPrice of the performance: " << price << "\n";
	cout << "Id: " << id<<"\n";
}

template<typename T>
NormalTicket<T>::NormalTicket():Ticket<T>::Ticket() {

}

template<typename T>
NormalTicket<T>::NormalTicket(const NormalTicket<T>& other): Ticket<T>::Ticket<T>(other)
{}



template<typename T>
 NormalTicket<T>& NormalTicket<T>::operator=(const NormalTicket<T>& other)
{
	Ticket<T>::operator=(other);
}

template<typename T>
NormalTicket<T>::NormalTicket(char* _name, double _price, T _id) : Ticket<T>::Ticket(_name, _price, _id)
{}

template<typename T>
double NormalTicket<T>::getPrice()const {
	return price;
}

template<typename T>
int NormalTicket<T>::getSeatNum()const {
	return 1;
}

template<typename T>
GroupTicket<T>::GroupTicket<T>(): Ticket<T>::Ticket(),numofpeople(20)
{
	price = price*(numofpeople - 1);
	cnt++;
}

template<typename T>
void GroupTicket<T>::copy(const GroupTicket<T>& other){
	numofpeople = other.numofpeople;
}



template<typename T>
 GroupTicket<T>& GroupTicket<T>::operator=(const GroupTicket<T>& other)  {
	 if (this != &other) {
		Ticket<T>::operator=(other);
		numofpeople = other.numofpeople;
	 }
	 return *this;
 }



template<typename T>
GroupTicket<T>::GroupTicket(char* _name, double _price, T _id, int _numpeople): Ticket<T>::Ticket(_name, _price, _id)
{
	numofpeople = _numpeople;
	double	price1 = price*(_numpeople - 1);
	price = price1;

}

template<typename T>
GroupTicket<T>::GroupTicket(const GroupTicket<T>& other) {
	copy();
}

template<typename T>
void GroupTicket<T>::printTicket() {
	cout << "Num oF People: " << numofpeople<<"\n";
	cout << "Price:" << getPrice();
}

template<typename T>
double GroupTicket<T>::getPrice()const {
	return price;
}

template<typename T>
int GroupTicket<T>::getSeatNum()const {
	return numofpeople;
}


template<typename T>
void printAllPricesandSeats(Ticket<T>** arr,int n) {
	double price = 0;
	double seats = 0;
	for (int i = 0; i < n; i++)
	{
		price += arr[i]->getPrice();
		seats += arr[i]->getSeatNum();
	}
	cout << "\nFinal price: " << price;
	cout << "\nNum of seats: " << seats<<"\n";
}

// int main() {
// 	GroupTicket<int> first("Sofia",20,2,50);
// 	NormalTicket<int> second("sd",20,434);
// 	first.printTicket();
// 	Ticket<int>** arr;
// 	arr = new Ticket<int>*[1];
// 	arr[0] = &first;
// 	arr[1] = &second;
// 	printAllPricesandSeats(arr,2);
// 	cout << "Counter: " << Ticket<int>::cnt<<"\n";
// 	system("pause");
// 	return 0;
// }
//
//
