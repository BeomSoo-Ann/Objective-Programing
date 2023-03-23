#include <iostream>

using namespace std;

int gcd(int a, int b);
int gcd_euclid(int a, int b);

int main()
{
    int x, y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "gcd(" << x << ", " << y << ") = " << gcd(x, y) << endl;
    return 0;
}

int gcd(int a, int b)
{
    int i = 1;
    int gcd = 1;
    while (i <= a && i <= b)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
        i++;
    }
    return gcd;
}

int gcd_euclid(int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    else
    {
        return gcd_euclid(b, r);
    }
}