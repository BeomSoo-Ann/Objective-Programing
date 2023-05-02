#include <iostream>
#include <iomanip>
#include <cmath>

void printMatrix(double **mat, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void swapRows()
{
}

void performGaussianElimination(double **mat, int size)
{
}

void backSubstitution(double **mat, int size, double *sol)
{
}

void solveSystem(double **matrix, int n)
{
    performGaussianElimination(matrix, n);
    double *solution = new double[n];
    backSubstitution(matrix, n, solution);

    std::cout << "The solution to the system of linear equation is:" << std::endl;
    std::cout << std::setprecision(6);
    for (int i = 0; i < n; i++)
    {
        std::cout << "x[" << i << "] = " << solution[i] << std::endl;
    }
    std::cout << std::endl;
    delete[] solution;
}

int main()
{
    int n = 3;
    double **A = new double *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n + 1];
    }

    A[0][0] = 2;
    A[0][1] = 3;
    A[0][2] = -1;
    A[0][3] = 1;
    A[1][0] = 4;
    A[1][1] = 4;
    A[1][2] = 3;
    A[1][3] = 3;
    A[2][0] = 2;
    A[2][1] = -3;
    A[2][2] = 1;
    A[2][3] = -1;

    std::cout << "The original matrix(the last column is augmented) is:" << std::endl;
    printMatrix(A, n);
    solveSystem(A, n);

    A[0][0] = 0;
    A[0][1] = 3;
    A[0][2] = -1;
    A[0][3] = 1;
    A[1][0] = 4;
    A[1][1] = 4;
    A[1][2] = 3;
    A[1][3] = 3;
    A[2][0] = 2;
    A[2][1] = -3;
    A[2][2] = 1;
    A[2][3] = -1;

    std::cout << "The original matrix(the last column is augmented) is:" << std::endl;
    printMatrix(A, n);
    solveSystem(A, n);

    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}