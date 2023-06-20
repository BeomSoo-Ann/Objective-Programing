#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class FileNotFoundException : public exception
{
    string message; // Identifies the exception and filename
public:
    FileNotFoundException(const string &fname) : message("File \"" + fname + "\" not found") {}

    virtual const char *what() const throw()
    {
        return message.c_str();
    }
};
class CStudent
{
private:
    string m_Name;
    int m_Number;
    string m_Major;

public:
    CStudent() : m_Name(""), m_Number(0), m_Major("") {}

    ~CStudent() {}

    void setAll(string _name, int _num, string _maj)
    {
        m_Name = _name;
        m_Number = _num;
        m_Major = _maj;
    }
    void Display()
    {
        cout << "이름: " << m_Name << endl;
        cout << "학번: " << m_Number << endl;
        cout << "전공: " << m_Major << endl
             << endl;
    }
};

vector<CStudent> read_file(string &filename)
{
    ifstream fin;
    int num_member;
    string name;
    int stu_num;
    string major;
    vector<CStudent> stu_info;
    fin.open(filename);
    try
    {
        if (!fin)
        {
            throw filename;
        }

        fin >> num_member;
        for (int i = 0; i < num_member; i++)
        {
            fin >> name >> stu_num >> major;
            CStudent temp;
            temp.setAll(name, stu_num, major);
            stu_info.push_back(temp);
        }
        fin.close();
        return stu_info;
    }
    catch (string &filename)
    {
        fin.close();
        throw FileNotFoundException(filename);
    }
}

int main()
{
    string str;

    cout << "파일 이름 : ";
    cin >> str;

    try
    {
        vector<CStudent> numbers = read_file(str);
        for (CStudent value : numbers)
            value.Display();
    }
    catch (std::exception &e)
    {
        cout << e.what() << '\n';
    }

    return 0;
}
