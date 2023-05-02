#include <iostream>

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *ptr = &arr[0][0];
    int **pptr = new int *[3];

    for (int i = 0; i < 3; i++)
    {
        pptr[i] = &arr[i][0];
    }

    std::cout << "Using pointer arithmetic:" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << /*fill in the blank*/ *(*(arr + i) + j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Using array notation:" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << /*fill in the blank*/ pptr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Using pointer of pointers:" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << /*fill in the blank*/ *(*(arr + i) + j) << " ";
        }
        std::cout << std::endl;
    }

    delete[] pptr;

    return 0;
}