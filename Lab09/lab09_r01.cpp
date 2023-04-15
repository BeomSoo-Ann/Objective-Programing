#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using Matrix = vector<vector<int>>;

void put_random_elem(Matrix &mat);
void print(const Matrix &mat);
Matrix multiply_matrix(const Matrix mat1, const Matrix mat2);

int main()
{
    int nRow1, nCol1, nRow2, nCol2;
    cout << "A의 행, 열의 크기를 입력해주세요 : ";
    cin >> nRow1 >> nCol1;

    cout << "B의 행, 열의 크기를 입력해주세요 : ";
    cin >> nRow2 >> nCol2;
    cout << endl;

    if (nCol1 == 0 || nCol2 == 0 || nRow1 == 0 || nRow2 == 0)
    {
        cout << "행렬을 생성할 수 없습니다." << endl;
        return 0;
    }

    Matrix mat1(nRow1, vector<int>(nCol1));
    Matrix mat2(nRow2, vector<int>(nCol2));

    put_random_elem(mat1);
    put_random_elem(mat2);

    cout << "A 행렬 : " << endl;
    print(mat1);

    cout << endl;

    cout << "B 행렬 : " << endl;
    print(mat2);

    cout << endl;

    if (nCol1 != nRow2)
    {
        cout << "두 행렬을 곱할 수 없습니다." << endl;
        return 0;
    }

    cout << "AB 곱행렬 : " << endl;
    print(multiply_matrix(mat1, mat2));

    return 0;
}

void put_random_elem(Matrix &mat)
{
    for (auto &row : mat)
    {
        for (int &col : row)
        {
            col = rand() % 17 + (-9);
        }
    }
}

void print(const Matrix &mat)
{
    for (auto row : mat)
    {
        for (int col : row)
        {
            cout << setw(4) << col;
        }
        cout << endl;
    }
}

Matrix multiply_matrix(const Matrix mat1, const Matrix mat2)
{
    Matrix mat3(mat1.size(), vector<int>(mat2[0].size()));

    for (int i = 0; i < mat1.size(); i++)
    {
        for (int j = 0; j < mat2[0].size(); j++)
        {
            for (int k = 0; k < mat2.size(); k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return mat3;
}
