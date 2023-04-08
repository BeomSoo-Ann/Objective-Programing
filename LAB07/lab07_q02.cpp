#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("example.txt");

    string s2 = "Objective Oriented programming";
    fout << s2 << endl;
    fout << "Random Variables" << endl;
    fout << "Linear Algebra" << endl;

    fout.close();

    ifstream fin;
    string s1;
    fin.open("example.txt");

    if (!fin)
    {
        cout << "Error, no such file exists" << endl;
        exit(100);
    }

    while (getline(fin, s1))
    {
        cout << s1 << endl;
    }

    /*
    while (1)
    {
        if (getline(fin, s1))
        {
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] == ' ')
                {
                    cout << endl;
                }
                else
                    cout << s1[i];
            }
            cout << endl;
        }
        else
            break;
    }
    */
    fin.close();
}