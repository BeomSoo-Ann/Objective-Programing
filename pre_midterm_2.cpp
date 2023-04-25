#include <iostream>

using namespace std;

int f(int a, int b)
{
    return a + b;
}

int g(/*fill in here*/ int (*f)(int, int), int x, int y)
{
    return 2 * (*f)(x, y);
}

int main()
{
    cout << g(f, 2, 3) << endl;
}
/* fill in here == int (*f)(int, int) */
/* output == 10 */