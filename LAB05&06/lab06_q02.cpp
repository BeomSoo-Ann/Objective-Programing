#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0, count = 1;
    cout << "number : ";
    cin >> num;

    while (true)
    {
        sum += count;
        count++;
        if (count == num + 1)
        {
            cout << "Sum of 1 to " << num << " is " << sum << endl;
            break;
        }
    }
    return 0;
}