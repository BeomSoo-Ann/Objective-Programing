#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    string name;
    string id;
    int balance;
    static int sum;

public:
    Account() : name(""), id(""), balance(0) {}
    Account(string _name, string _id, int _balance) : name(_name), id(_id), balance(_balance) {}
    void setName(string _name) { name = _name; }
    void setId(string _id) { id = _id; }
    void setBalance(int _balance)
    {
        balance = _balance;
        sum += _balance;
    }
    string getID() { return id; }
    static int getSum() { return sum; }
};

int Account::sum = 0;

int main()
{
    int n;
    cout << "총 학생수 입력: ";
    cin >> n;

    Account *acnt = new Account[n];

    for (int i = 0; i < n; i++)
    {
        string name, id;
        int balance;

        cout << i + 1 << "번째 학생 계좌 입력 : 학번 : ";
        cin >> id;
        cout << endl;

        cout << "이름 : ";
        cin >> name;
        cout << endl;

        cout << "잔액 : ";
        cin >> balance;
        cout << "============================" << endl
             << endl;

        for (int j = 0; j < n; j++)
        {
            if (acnt[j].getID() == id)
            {
                cout << "중복된 학번이 존재합니다." << endl;
                cout << "프로그램을 종료합니다." << endl;
                return 0;
            }
        }
        acnt[i].setId(id);
        acnt[i].setName(name);
        acnt[i].setBalance(balance);
    }

    cout << "회수된 금액 : " << Account::getSum() << endl;
    delete[] acnt;
    return 0;
}