#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int *aPointer = &a;
    /*Constant pointer
    int *const aPointer = &a;
    */

    cout << *aPointer << endl;
    cout << &aPointer << endl;

    int b = 10;
    aPointer = &b; //If we have constast pointer

    cout << *aPointer << endl;

    cout << &aPointer << endl;

    return 0;
}
