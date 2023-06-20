#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
using namespace std;

int main()
{
    ofstream ofs;
    ifstream ifs;
    string file_name;
    int output_row, output_col;

    ofs.open("temp.txt");

    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            ofs << rand() % 101 << " ";
        }
        ofs << endl;
    }

    ofs.close();

    try
    {
        cout << "파일 이름 : ";
        cin >> file_name;
        // 파일이름 입력
        ifs.open(file_name);
        if (!ifs.is_open())
        {
            throw file_name;
        }
    }
    catch (string &file_name)
    {
        cout << endl
             << "File " << '"' << file_name << '"' << " not found" << endl;
        return 0;
    }

    try
    {
        cout << "출력할 행 크기 : ";
        cin >> output_row;

        cout << "출력할 열 크기 : ";
        cin >> output_col;

        if (output_row > 10 or output_col > 10)
        {
            throw 0;
        }

        vector<vector<int>> vect(10, vector<int>(10, 0));
        for (int row = 0; row < 10; row++)
        {
            for (int col = 0; col < 10; col++)
            {
                ifs >> vect[row][col];
            }
        }

        for (int row = 0; row < output_row; row++)
        {
            for (int col = 0; col < output_col; col++)
            {
                cout << vect[row][col] << " ";
            }
            cout << endl;
        }
    }

    catch (int num)
    {
        cout << endl
             << "Invalid vector<T> subscript" << endl;
        return 0;
    }
    // 입력받은 파일이름에 맞는 파일을 읽어와 vector로 입력 후, 출력 구현

    return 0;
}
