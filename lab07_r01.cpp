#include <iostream>
#include <string>

using namespace std;

int main()
{
    string city, area, street, building;

    cout << "시 : ";
    getline(cin, city);
    cout << "구 : ";
    getline(cin, area);
    cout << "동 : ";
    getline(cin, street);
    cout << "건물명 : ";
    getline(cin, building);

    cout << "집 주소 : " << city + area + street + building << endl;
}