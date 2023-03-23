#include <iostream>

using namespace std;

int multiplication_table(int n);

int main()
{
    int count;

    while (true)
    {
        cout << "단 수를 입력하세요: ";
        cin >> count;

        if (count >= 1 && count <= 9)
        {
            multiplication_table(count);
            cout << endl;
        }

        else if (count == -1)
        {
            cout << "종료합니다." << endl;
            break;
        }

        else
        {
            cout << "1부터 9까지의 정수를 입력해주세요."
                 << "\n"
                 << endl;
        }
    }
    return 0;
}

int multiplication_table(int n)
{
    int i = 1;
    while (i <= 9)
    {
        cout << n << "*" << i << " = " << n * i << endl;
        i++;
    }
    return 0;
}