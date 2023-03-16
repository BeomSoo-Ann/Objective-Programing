#include <iostream>

using namespace std;

int get_data(int &x, int &y);
void swap_call_by_value(int x, int y);
void swap_call_by_reference(int &x, int &y);

int main()
{
    int a, b;
    get_data(a, b);
    cout << "swap_call_by_value 함수 사용 전\n";
    cout << "x = " << a << ", y = " << b << endl;

    swap_call_by_value(a, b);
    cout << "swap_call_by_value 함수 사용 후\n";
    cout << "x = " << a << ", y = " << b << "\n"
         << endl;

    cout << "swap_call_by_reference 함수 사용 전\n";
    cout << "x = " << a << ", y = " << b << endl;

    swap_call_by_reference(a, b);
    cout << "swap_call_by_reference 함수 사용 후\n";
    cout << "x = " << a << ", y = " << b << endl;

    return 0;
}

int get_data(int &x, int &y)
{
    cout << "x 입력 : ";
    cin >> x;
    cout << "y 입력 : ";
    cin >> y;

    return 0;
}

void swap_call_by_value(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap_call_by_reference(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}