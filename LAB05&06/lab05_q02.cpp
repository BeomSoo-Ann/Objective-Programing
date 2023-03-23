#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int num = 1;
    int count = 1;
    cout.imbue(locale("")); // for comma

    while (count <= 20 && count >= 0)
    {
        num = num * 2;
        cout << count << "\t" << setw(10) << num << endl;
        count++;
    }

    return 0;
}