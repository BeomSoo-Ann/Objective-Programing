#include <iostream>

using namespace std;

int main()
{
    int num;
    int count = 1;

    while (count <= 5)
    {
        cout << count << "번째 정수 : ";
        cin >> num;

        if (num % 2 == 0)
        {
            cout << num << "은(는) 짝수입니다." << endl;
        }
        else
        {
            cout << num << "은(는) 홀수입니다." << endl;
        }

        count++;
    }
    return 0;
}