#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> list{10, 20, 30, 40, 50};
    int num;

    while (1)
    {
        cout << "출력할 숫자의 수 : ";
        cin >> num;

        if (num < 0)
        {
            break;
        }

        try
        {
            for (int i = 0; i < num; i++)
            {
                cout << list.at(i) << " ";
            }
            cout << endl;
        }

        catch (out_of_range &e)
        {
            cout << endl;
            cout << "Index is out of range. Please try again." << endl;
        }
    }

    cout << endl;
    cout << "Program exit..." << endl;

    return 0;
}