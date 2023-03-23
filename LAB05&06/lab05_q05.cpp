#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter n for n x m matrix: ";
    cin >> n;
    cout << "Enter m for n x m matrix: ";
    cin >> m;

    int row = 1, column = 1;
    while (row <= n)
    {
        while (column <= m)
        {
            int product = row * column;
            cout << setw(4) << product;
            column++;
        }
        cout << endl;
        row++;
        column = 1;
    }
    return 0;
}