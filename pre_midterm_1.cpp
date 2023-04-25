#include <iostream>

using namespace std;
/*
문제 1
One disadvantage of call (pass) -by-[ value ] is that if a large data item(for example, 1080 by 1920 double array)
is being passed, copying the data can take a considerable amount of execution time and memory space.


문제 2
The scope, or the variable lifespan of a [ local ] variable is within the function that variable is defined.
*/

// 문제 3
int main()
{
    int a[10];
    a[4] = 5; // a[4] = *(a + 4)
    cout << a[4] << endl;

    *(a + 4) = 7;
    cout << a[4] << endl;

    int b[5][10];
    b[3][4] = 5; // b[3][4] = *(*(b + 3) + 4)
    cout << b[3][4] << endl;

    *(*(b + 3) + 4) = 7;
    cout << b[3][4] << endl;
}
