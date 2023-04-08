#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream fin1("input1.txt");
    ifstream fin2("input2.txt");
    ofstream fout("output.txt");
    string line;

    while (getline(fin1, line))
    {
        fout << line << "\n";
    }

    fin1.close();

    fout << "\n";

    while (getline(fin2, line))
    {
        fout << line << "\n";
    }

    fin2.close();
    fout.close();

    return 0;
}