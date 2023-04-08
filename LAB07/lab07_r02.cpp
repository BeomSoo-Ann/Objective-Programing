#include <iostream>
#include <string>

using namespace std;

int main()
{
    string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
    string input, result = "";

    cout << "키워드 : ";
    cin >> input;
    cout << endl;

    cin.ignore();

    while (data.find(",") != string::npos)
    {
        int pos = data.find(",");
        string word = data.substr(0, pos);

        if (word.find(input) != string::npos)
        {
            result += word + " ";
            data.erase(0, pos + 1);
        }
        else if (word.find(input) == string::npos)
        {
            data.erase(0, pos + 1);
        }
    }

    if (data.find(input) != string::npos)
    {
        result += data;
    }

    cout << "검색결과 : " << result << endl;

    return 0;
}