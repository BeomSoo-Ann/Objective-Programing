#include <iostream>
using namespace std;

template <typename T>
class CList
{
public:
    CList() { m_Length = 0; }
    ~CList() {}

    bool IsEmpty()
    {
        if (m_Length == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool IsFull()
    {
        if (m_Length == 5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Add(T data)
    {
        if (IsFull() == 0)
        {
            for (int i = 0; i < m_Length; i++)
            {
                if (m_Array[i] == data)
                {
                    cout << endl;
                    cout << "중복된 데이터가 존재합니다.";
                    return;
                }
            }
            m_Array[m_Length] = data;
            m_Length++;
            for (int i = 0; i < m_Length - 1; i++)
            {
                for (int a = 0; a < m_Length - 1; a++)
                {
                    if (m_Array[a] > m_Array[a + 1])
                    {
                        T temp = m_Array[a];
                        m_Array[a] = m_Array[a + 1];
                        m_Array[a + 1] = temp;
                    }
                }
            }
        }
        else if (IsFull() == 1)
        {
            cout << "List is full.";
        }
    }

    void Delete(T data)
    {
        if (IsEmpty() == 0)
        {
            for (int i = 0; i < m_Length; i++)
            {
                if (m_Array[i] == data)
                {
                    m_Length--;
                    for (int a = i; i < m_Length; a++)
                    {
                        m_Array[a] = m_Array[a + 1];
                    }
                    break;
                }
            }
        }
        else if (IsEmpty() == 1)
        {
            cout << "List is Empty";
        }
    }

    void Print()
    {
        cout << "※ Current List" << endl;
        for (auto elem : m_Array)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

private:
    T m_Array[5];
    int m_Length;
};

int command()
{
    int num;

    cout << "\n\t---- menu ----" << endl;
    cout << "\t1. 리스트 추가" << endl;
    cout << "\t2. 리스트 삭제" << endl;
    cout << "\t3. 리스트 출력" << endl;
    cout << "\t4. 프로그램 종료" << endl;
    cout << "\n\t입력 --> ";
    cin >> num;
    return num;
}

int main()
{
    CList<int> list;
    int input;
    int com;
    while (1)
    {
        com = command();
        switch (com)
        {
        case 1:
            cout << "\n추가할 데이터 : ";
            cin >> input;
            list.Add(input);
            break;
        case 2:
            cout << "\n삭제할 데이터 : ";
            cin >> input;
            list.Delete(input);
            break;
        case 3:
            list.Print();
            break;
        case 4:
            cout << "\n\t프로그램을 종료합니다\n";
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
