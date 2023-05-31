#include <iostream>
#include <functional> // function object
using namespace std;

//[closure]: 외부 변수를 lambda함수 내부로 전달
//[a]: 변수 a를 call by value로 lambda함수에 전달
//[&a]: 변수 a를 call by reference로 전달
//[=]: 모든 외부 변수를 call by value로 전달
//[&]: 모든 외부 변수를 call by ref.로 전달
//  - 사용시 주의할 점: closure를 사용할 경우 function객체로 assign 받을 것
int evaluate2(function<int(int, int)> f, int x, int y)
{
    return f(x, y);
}

int main()
{
    int a = 10, b = 20;

    //[a]: 변수 a를 call by value로 lambda함수에 전달
    /* a + x + y 람다 함수 구현 */
    cout << evaluate2([a](int x, int y)
                      { return a + x + y; },
                      2, 3)
         << endl;

    //[&]: 모든 외부 변수를 call by ref.로 전달
    /* a = 20; a * x 람다 함수 구현 */
    cout << evaluate2([&](int x, int y)
                      { a = 20; return a * x; },
                      10, 3)
         << endl;

    cout << "a: " << a << endl;
    return 0;
}
