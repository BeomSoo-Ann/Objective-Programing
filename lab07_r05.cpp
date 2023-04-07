#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string line;
    int width, base;

    cout << "length = ";
    cin >> width;

    /*
    line.length() / width
    line.substr(width * i, width * (i + 1))

    */

    fin.close();
    fout.close();

    return 0;
}