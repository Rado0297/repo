#include <iostream>

using namespace std;

void ToH(int dskToMv, int cLocation, int tmpLocation, int fLocation)
{
    if( dskToMv != 0 ) 
    {
        ToH( dskToMv-1, cLocation, fLocation, tmpLocation );
        cout << cLocation << "->" << fLocation << endl;
        ToH( dskToMv-1, tmpLocation, cLocation, fLocation );
    }
}

int main()
{
    int x;
    cout << "Enter number of disks: ";
    cin >> x;
    ToH(x, 1, 2, 3);
    return 0;
}