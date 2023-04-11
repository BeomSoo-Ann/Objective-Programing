#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void reverse(vector<int> *v);

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "기본 Vector 값 :" << endl;

    for (int elem : vec)
        cout << ' ' << elem;
    cout << endl;

    reverse(&vec);

    cout << "함수 실행 후 Vector 값 :" << endl;

    for (int elem : vec)
        cout << ' ' << elem;
    cout << endl;

    return 0;
}

void reverse(vector<int> *v)
{
    int temp;

    for (int i = 0; i < v->size() / 2; i++)
    {
        temp = v->at(i);
        v->at(i) = v->at(v->size() - 1 - i);
        v->at(v->size() - 1 - i) = temp;
    }
}