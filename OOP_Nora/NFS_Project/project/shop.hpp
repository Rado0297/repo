#include "libs.hpp"

#ifndef SHOP_HPP
#define SHOP_HPP

template <typename T>
class Showroom
{
private:
    int count; //count of cars in given Showroom
    T* list;
    int* prices;

public:
    Showroom()
    {
        count = 0;
        list = nullptr;
        prices = nullptr;
    }

    Showroom(T* _list, int _count)
    {
        count = _count;
        list = new T[count];
        prices = new int[count];
        assert(list != nullptr && prices != nullptr);
        for (size_t i = 0; i < count; i++) {
            list[i] = _list[i];
            prices[i] = _list[i].getPrice();
        }
    }

    ~Showroom()
    {
        delete[] list;
        delete[] prices;
    }

    T sellCar(int ind)
    {
        assert(ind <= count && ind > 0);

        int index = ind - 1;

        T car;
        car = list[index];

        T* l;
        l = new T[count - 1];
        int j = 0;
        assert(l != nullptr);

        for (size_t i = 0; i < count; i++) {
            if (i != index) {
                l[j] = list[i];
                j++;
            }
        }

        delete[] list;
        count--;
        list  = new T[count];
        for (size_t i = 0; i < count; i++) {
            list[i] = l[i];
        }

        return car;
    }

    const void printShowroom() const
    {
        cout << "Showroom information:\n"
            << "Count of cars: " << count << endl
            << "Cars:\n";

        for (size_t i = 0; i < count; i++) {
            cout << i+1 << ".";
            list[i].printCar();
            cout << endl;
        }
    }
};


#endif
