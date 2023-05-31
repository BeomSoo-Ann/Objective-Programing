#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main()
{
    vector<int> vec_1;
    vector<int> vec_2;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        vec_1.push_back(rand() % 11);
        vec_2.push_back(rand() % 21);
    }

    vector<int>::iterator iter_1 = begin(vec_1);
    vector<int>::iterator iter_2 = end(vec_1);
    vector<int>::iterator iter_3 = begin(vec_2);
    vector<int>::iterator iter_4 = end(vec_2);

    cout << "<Vector 1>" << endl;
    for (const auto &elem : vec_1)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "<Vector 2>" << endl;
    for (const auto &elem : vec_2)
    {
        cout << elem << " ";
    }
    cout << endl;

    int max_v1 = 0;
    int min_v1 = 0;
    int max_v2 = 0;
    int min_v2 = 0;

    for (const auto &elem : vec_1)
    {
        if (min_v1 > elem)
            min_v1 = elem;
        if (max_v1 < elem)
            max_v1 = elem;
    }

    for (const auto &elem : vec_2)
    {
        if (min_v2 > elem)
            min_v2 = elem;
        if (max_v2 < elem)
            max_v2 = elem;
    }

    cout << endl
         << "최댓값 = " << max_v1 * max_v2 << endl;
    cout << "최솟값 = " << min_v1 * min_v2 << endl;
}
