#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverse_string(string str)
{
    string answer = "";
    for (int i = 1; i <= str.length(); i++)
    {
        answer += str[str.length() - i];
    }
    return answer;
}

int main()
{
    string input;
    string input_palin;

    while (1)
    {
        cout << "문자열 하나를 입력해주세요 : ";
        cin >> input;
        if (input == "q")
        {
            break;
        }
        input_palin = reverse_string(input);
        cout << "입력하신 문자열의 역순 : " << input_palin << endl;

        [](string input, string input_palin)
        {
            if (input == input_palin)
                cout << "이 문자는 회문입니다." << endl;
            else
                cout << "이 문자는 회문이 아닙니다." << endl;
        }(input, input_palin);
        cout << endl;
    }
    return 0;
}
