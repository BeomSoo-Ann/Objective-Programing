#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void get_command(string &line); // command 입력 받음
void get_size(int &n);          // enter the size 출력 후 size 입력 받음
int **gen_matrix(int n);        // n x n matrix 생성 후 각 elem에 0-100 사이의 random int 저장
void swap(int *a, int *b);
void sort_array(int *arr, int size);
void sort_matrix_row(int **mat, int n); // 행렬의 각 열을 오름차순 정렬 후 Completed 출력
void print_matrix(int **mat, int n);    // 화면에 row의 각 원소를 출력
void save_matrix(int **mat, int n);     // matrix.txt에 저장 후 Saved 출력
void free_matrix(int **mat, int n);     // 행렬 할당 해제

int main()
{
    ofstream temp;
    string command;
    int **matrix = NULL;
    int size = 0;

    while (1)
    {
        get_command(command);

        if (command == "1")
        {
            get_size(size);
            matrix = gen_matrix(size);
        }
        else if (command == "2")
        {
            print_matrix(matrix, size);
        }
        else if (command == "3")
        {
            sort_matrix_row(matrix, size);
        }
        else if (command == "4")
        {
            save_matrix(matrix, size);
        }
        else if (command == "0")
        {
            free_matrix(matrix, size);
            cout << "Exit the program.." << endl;
            exit(104);
        }
        else
        {
            cout << "Wrong command" << endl
                 << endl;
        }
    }
    return 0;
}

void get_command(string &line)
{
    cout << "1. Enter the size of matrix" << endl;
    cout << "2. Print the matrix" << endl;
    cout << "3. Sort the matrix row" << endl;
    cout << "4. Save the matrix" << endl;
    cout << "0. Exit" << endl;
    cout << "Command: ";
    getline(cin, line);
}

void get_size(int &n)
{
    cout << "Enter the size of matrix: ";
    cin >> n;
    cin.ignore();
}

int **gen_matrix(int n)
{
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = rand() % 101;
        }
    }
    return mat;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int *ary, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (ary[j] > ary[j + 1])
            {
                swap(&ary[j], &ary[j + 1]);
            }
        }
    }
}

void sort_matrix_row(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        sort_array(mat[i], n);
    }
    cout << "Completed" << endl
         << endl;
}

void print_matrix(int **mat, int n)
{
    cout << "Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void save_matrix(int **mat, int n)
{
    ofstream fout;
    fout.open("matrix.txt");
    fout << "Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        fout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            fout << setw(4) << mat[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
    cout << "Saved" << endl
         << endl;
}

void free_matrix(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}