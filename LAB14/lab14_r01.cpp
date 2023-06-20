#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main()
{
    vector<int> list;
    // vector를 1~100 사이의 random한 크기로 만들고 채우는 코드 구현
    int size = rand() % 101;
    list.resize(size);

    int cnt = -1;
    while (1)
    {
        cnt++;
        try
        {
            list.at(cnt) = cnt;
        }
        catch (exception &e)
        {
            cout << "현재 리스트는 " << cnt << "의 크기를 가지고 있다.";
            break;
        }
    }
    return 0;
}
