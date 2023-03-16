#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    cout << "Rounding up number of " << x << " is " << ceil(x) << endl;
    cout << "Rounding down number of " << x << " is " << floor(x) << endl;
    cout << "Rounding number of " << x << " is " << round(x) << endl;
    cout << "Maximum number of " << x << " and " << y << " is " << max(x, y) << endl;
    cout << y << "-th root of " << x << " is " << pow(x, 1 / y) << endl;
    cout << "|" << x << " - " << y << "| is " << abs(x - y) << endl;

    return 0;
}