#include <iostream>

using namespace std;

class rat
{
private:
    int numer;
    int denom;

public:
    rat(); //Deafault Constructor
    rat(int, int); //Constructor
    rat(const rat&); //Copy Constructor

    int getNumer() const;
    int getDenom() const;

    inline int rec(rat&);

    void multRats(const rat& r1, const rat& r2);

    void print();
};

rat::rat()
{
    numer = 0;
    denom = 1;
}

rat::rat(int x, int y): numer(x), denom(y)
{}

rat::rat(const rat& r)
{
    numer = r.numer;
    denom = r.denom;
}

int rat::getNumer() const
{
    return numer;
}

int rat::getDenom() const
{
    return denom;
}

inline int rat::rec(rat& r)
{
    int temp = numer;
    numer = denom;
    denom = temp;
}

void rat::multRats(const rat& r1, const rat& r2)
{
    numer = r1.getNumer() * r2.getNumer();
    denom = r1.getDenom() * r2.getDenom();
}

void rat::print()
{
    cout << numer << "/" << denom << endl;
}

int main() {
    rat numbers[60];

    for (size_t i = 0; i < 3; i++) {
        numbers[i]=rat(i, i+1);
    }

    for (size_t i = 0; i < 3; i++) {
        numbers[i].print();
    }

    return 0;
}
