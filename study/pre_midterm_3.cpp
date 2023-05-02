/*
다음 프로그램에서 function create_integer_matrix()는 parameter로 정수 n을 입력받아
(1) nxn 2차원 array를 만들고,
(2) [i][j]번째 원소에 i+j값을 넣고,
(3) 그 array의 pointer를 return하는 함수이다.
그러므로 아래의 main에서는 다음과 같은 값이 화면에 프린트 된다.

0 1 2

1 2 3

2 3 4

free_integer_matrix()는 생성된 2차원 array의 메모리를 해제하는 함수이다.

create_integer_matrix() 및 destroy_integer_matrix()를 작성하라. [30점]
([시작코드]를 변경하지 말 것) Function의 declaration, definition 모두 작성할 것.
작성한 프로그램은 시작코드를 포함한 하나의 <학번_문제>.cpp 파일 형태로 업로드 하시오.
파일명에 한글이나 특수문자는 사용하지 마시오.
*/

#include <iostream>

using namespace std;

int **create_integer_matrix(int N);
void destroy_integer_matrix(int **Mat, int N);

int main()
{
    int i, j, **M;
    M = create_integer_matrix(3);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    destroy_integer_matrix(M, 3);
    return 0;
}

int **create_integer_matrix(int N)
{
    int **Mat = new int *[N];
    for (int i = 0; i < N; i++)
    {
        Mat[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            Mat[i][j] = i + j;
        }
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