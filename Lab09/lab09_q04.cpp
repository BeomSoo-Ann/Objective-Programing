#include <iostream>
#include <vector>

using namespace std;

// static array vs dynamic array

int main()
{
    const int size = 3;
    int list[size] = {10, 20, 30}; // static array

    int length = 3;
    cin >> length;
    int *list2 = new int[length]; // dynamic array

    int *begin = list2;
    int *end = list2 + length;

    for (int *curr = begin; curr != end; curr++)
    {
        cin >> *curr;
    }

    for (int *curr = begin; curr != end; curr++)
    {
        cout << *curr << '\t';
    }
    cout << endl;

    delete[] list2;

    return 0;
}