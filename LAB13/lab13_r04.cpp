#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int size;
    cout << "홀수 숫자를 하나 입력해 주세요 : ";
    cin >> size;

    int row = 0;
    int col = size / 2;
    int rest;

    int **magic_number = new int *[size];
    for (int i = 0; i < size; i++)
    {
        magic_number[i] = new int[size];
    }

    for (int k = 1; k <= size * size; k++)
    {
        magic_number[row][col] = k;
        rest = k % size;
        if (rest == 0)
        {
            row++;
        }
        else
        {
            if (--row < 0)
                row = size - 1;
            if (++col == size)
            {
                col = 0;
            }
        }
    }

    for (int _row = 0; _row < size; _row++)
    {
        for (int _col = 0; _col < size; _col++)
        {
            cout << setw(4) << magic_number[_row][_col];
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++)
    {
        delete[] magic_number[i];
    }
    delete[] magic_number;
}
