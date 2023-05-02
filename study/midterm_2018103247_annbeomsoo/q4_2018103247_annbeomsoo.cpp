#include <iostream>
#include <iomanip>

using namespace std;

int **create_integer_matrix(int N);
void destroy_integer_matrix(int **Mat, int N);

int main()
{
    int i, j, **M;
    M = create_integer_matrix(5);

    M[0][0] = 1;
    M[1][0] = 4;
    M[1][1] = 5;
    M[2][0] = 8;
    M[2][1] = 9;
    M[2][2] = 0;
    M[3][0] = 10;
    M[3][1] = 0;
    M[3][2] = 0;
    M[3][3] = 0;
    M[4][0] = 11;
    M[4][1] = 12;
    M[4][2] = 13;
    M[4][3] = 14;
    M[4][4] = 15;

    cout << "Array:" << endl;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << setw(3) << M[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Values in last column: 1 5 0 0 15" << endl;
    cout << "Minimum value in array: 0" << endl;
    cout << "Row sums: 1 9 17 10 65" << endl;

    destroy_integer_matrix(M, 5);
    return 0;
}

int **create_integer_matrix(int N)
{
    int **Mat = new int *[N];

    for (int i = 0; i < N; i++)
    {
        Mat[i] = new int[i + 1];
    }
    return Mat;
}

void destroy_integer_matrix(int **Mat, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] Mat[i];
    }
    delete[] Mat;
}