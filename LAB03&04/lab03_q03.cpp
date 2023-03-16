#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double value;
    value = 5;
    cout << sqrt(value) << endl;
    cout << exp(value) << endl;
    cout << log(value) << endl;
    // 문제에서는 밑이 10인 로그를 구하라고 했는데 문제의 output을 보면 자연로그 값을 반환함
    cout << cos(value) << endl;

    return 0;
}