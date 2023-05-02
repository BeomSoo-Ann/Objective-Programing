#include <iostream>
#include <string>

using namespace std;

class CStudent
{
private:
    int id;
    string name;
    string major;

public:
    CStudent()
    {
        id = 2018000000;
        name = "홍길동";
        major = "컴퓨터공학과";
    }

    CStudent(int _id, string _name, string _major)
    {
        id = _id;
        name = _name;
        major = _major;
    }

    void setNumber(int _id)
    {
        id = _id;
    }

    void setName(string _name)
    {
        name = _name;
    }

    void setMajor(string _major)
    {
        major = _major;
    }

    int getNumber()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getMajor()
    {
        return major;
    }

    void Display()
    {
        cout << "학번 :" << id << endl;
        cout << "이름 :" << name << endl;
        cout << "전공 :" << major << endl;
        cout << endl;
    }
};

int main()
{
    CStudent s[3];
    int inputNumber;
    string inputName, inputMajor;
    int length = 0;

    while (1)
    {
        if (length == 3)
        {
            break;
        }

        cout << length + 1 << " 번째 학생 입력" << endl;
        cout << "학번 : ";
        cin >> inputNumber;
        cout << "이름 : ";
        cin >> inputName;
        cout << "전공 : ";
        cin >> inputMajor;

        if (length == 0)
        {
            s[length].setNumber(inputNumber);
            s[length].setName(inputName);
            s[length].setMajor(inputMajor);
            cout << "※입력 완료" << endl;
            cout << endl;
            length++;
            continue;
        }

        else if (length > 0)
        {
            for (int i = 0; i <= length - 1; i++)
            {
                if (s[i].getNumber() == inputNumber)
                {
                    cout << "※중복된 학번이 존재합니다" << endl;
                    cout << endl;
                    break;
                }
                else if (i == length - 1)
                {
                    s[length].setNumber(inputNumber);
                    s[length].setName(inputName);
                    s[length].setMajor(inputMajor);
                    cout << "※입력 완료" << endl;
                    cout << endl;
                    length++;
                    break;
                }
            }
        }
    }

    cout << "----모든입력이 완료되었습니다----" << endl;

    cout << "1학생정보" << endl;
    s[0].Display();

    cout << "2학생정보" << endl;
    s[1].Display();

    cout << "3학생정보" << endl;
    s[2].Display();

    return 0;
}