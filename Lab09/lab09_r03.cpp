#include <iostream>
#include <vector>

using namespace std;

void put_random_elem(int *mat, int &nlen);
void print(int *m, int &nlen);
bool find_same_elem(int *mat, int &nlen);

int main()
{
    int n;
    int *mat;

    while (1)
    {
        cout << "Please enter a number: ";
        cin >> n;
        if (n < 2)
        {
            cout << "Wrong number!!!" << endl;
            break;
        }
        cout << "Size of random array: " << n / 2 << endl;

        mat = new int[n / 2];

        put_random_elem(mat, n);

        cout << "[ Array ]" << endl;
        print(mat, n);

        if (find_same_elem(mat, n) == true)
        {
            cout << "Duplicates found.\n"
                 << endl;
            continue;
        }
        else
        {
            cout << "Duplicates not found.\n"
                 << endl;
        }
    }
}

void put_random_elem(int *mat, int &nlen)
{
    for (int i = 0; i < nlen / 2; i++)
    {
        mat[i] = rand() % nlen;
    }
}

void print(int *m, int &nlen)
{
    for (int i = 0; i < nlen / 2; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}

bool find_same_elem(int *mat, int &nlen)
{
    for (int i = 0; i < nlen / 2; i++)
    {
        for (int j = i + 1; j < nlen / 2; j++)
        {
            if (mat[i] == mat[j])
            {
                return true;
            }
        }
    }
    return false;
}