#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int arr[100][100];

    for (size_t i = 0; i < 100; i++) {
        for (size_t j = 0; j < 100; j++) {
            arr[i][j] = 0;
        }
    }

    int counter = 1;

    int n;
    cin >> n;

    int i = n - 1, j = 0;

    for (; i >= 0; i--) {
        for (j = 0; j < n - i; j++) {
            arr[i + j][j] = counter;
            counter++;
        }
    }

    i = 0;
    j = 1;

    for (; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            arr[i][i + j] = counter;
            counter++;
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
