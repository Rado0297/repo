#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int aData = 1)
    {
        a = aData;
        cout << "A(" << aData << ")\n";
    }

    A(A const &obj)
    {
        a = obj.a;
        cout << "Copy A(" << obj.a << ")\n";
    }
};

class B
{
private:
    int b;
    A objA;

public:
    B(int bData = 1, int aData = 0)
    {
        b = bData;
        cout << "B(" << bData << ", " << aData << ")\n";
        objA = A(30);
    }

    B(B const &obj)
    {
        b = obj.b;
        cout << "Copy B(" << obj.b << ")\n";
    }
};

int main() {
    B test1(1, 3);
    B test2 = test1;


    return 0;
}
