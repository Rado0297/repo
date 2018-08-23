#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int &aReference = a;

    int b = 10;
    aReference = b;

    cout << aReference << endl;

    return 0;
}
