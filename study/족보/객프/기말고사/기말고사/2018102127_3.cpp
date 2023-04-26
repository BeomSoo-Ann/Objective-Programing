#include <iostream>
using namespace std;
int main() {
    int i, j, k;
    int*** a = new int** [2];
    

    for (i = 0; i < 2; i++) {
        a[i] = new int* [2];
        for (j = 0; j < 2; j++) {
            a[i][j] = new int[5];
            for (k = 0; k < 5; k++) {
                a[i][j][k] = i + j + k;
                cout << a[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}