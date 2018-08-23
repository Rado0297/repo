#include <iostream>

using namespace std;

class Rat
{
private:
    int num;
    int denom;

public:
    Rat(int n = 0, int d = 0)
    {
        num = n;
        denom = d;
    }

    const void print() const
    {
        cout << num << "/" << denom << endl;
    }
};

int main() {
    Rat a;
    Rat b = Rat(4,5);
    Rat c(6,7);

    Rat list[11];

    char aa = 'a';

    cout << (int)aa << endl;

    a.print();
    b.print();
    c.print();


    return 0;
}
