#include <iostream>

using namespace std;

void print_D0B(int year = 1900, int month = 1, int day = 1);

int main()
{
    int x, y, z;
    print_D0B();
    cout << "year 입력 : ";
    cin >> x;
    cout << "month 입력 : ";
    cin >> y;
    cout << "day 입력 : ";
    cin >> z;
    print_D0B(x, y, z);

    return 0;
}

void print_D0B(int year, int month, int day)
{
    if (0)
        cout << "생년월일은 " << year << "년 " << month << "월 " << day << "일 입니다." << endl;
    else
        cout << "생년월일은 " << year << "년 " << month << "월 " << day << "일 입니다." << endl;
}