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
    char ch;
    int width, point = 0;

    cout << "length = ";
    cin >> width;

    while (fin.get(ch))
    {
        if (ch == '\n')
        {
            continue;
        }

        if (ch != '\n' && point < width)
        {
            fout.put(ch);
            point++;
        }
        else if (point == width)
        {
            fout << endl;
            fout.put(ch);
            point = 1;
        }
    }
    fin.close();
    fout.close();

    return 0;
}