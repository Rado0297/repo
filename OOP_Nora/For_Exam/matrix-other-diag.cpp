#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int arr[100][100];

    int n;
    cin >> n;

    int counter = 1;

    int i = 0, j = n - 1;

    for (; j >= 0; j--) {
        for (i = 0; i < n - j; i++) {
            arr[i][j + i] = counter;
            counter++;
        }
    }

    i = 1, j = 0;

    for (; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            arr[i + j][j] = counter;
            counter++;
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << setw(3) << arr[i][j];
        }

        cout << endl;
    }

    return 0;
}
