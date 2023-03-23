#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0, count = 1;
    cout << "number : ";
    cin >> n;

    while (count <= n)
    {
        if (count % 2 == 0 || count % 3 == 0)
        {
            count++;
            continue;
        }
        else
        {
            sum += count;
            count++;
        }
    }
    cout << "sum : " << sum << endl;
    return 0;
}