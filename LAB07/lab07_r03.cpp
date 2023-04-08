#include <iostream>
#include <iomanip>

using namespace std;

int randomInt();

int main()
{
    for (int j = 0; j <= 10; j++)
    {
        for (int i = 0; i <= 10; i++)
        {
            cout << setw(4) << randomInt();
        }
        cout << endl;
    }
}

// random int between 0 and 100
int randomInt()
{
    return rand() % 101;
}