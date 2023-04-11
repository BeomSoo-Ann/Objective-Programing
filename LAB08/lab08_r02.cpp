#include <iostream>
#include <string>

using namespace std;

void change_str(string *s);

int main()
{
    string str = "This is default value";
    cout << "기본값 출력> " << str << endl;
    change_str(&str);
    cout << "변환된 값 출력> " << str << endl;
    return 0;
}

void change_str(string *s)
{
    cout << "input> ";
    cin >> *s;
}