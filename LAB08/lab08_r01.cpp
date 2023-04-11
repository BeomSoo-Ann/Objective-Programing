#include <iostream>

using namespace std;

void square(int *x);

int main()
{
    int a;
    cout << "input> ";
    cin >> a;
    square(&a);
    cout << "제곱값> " << a << endl;
    return 0;
}

void square(int *x)
{
    *x = *x * *x;
}