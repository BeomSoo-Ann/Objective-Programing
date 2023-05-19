#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    string name;
    string id;
    int balance;

public:
    Account(string _name, string _id, int _balance) : name(_name), id(_id), balance(_balance) {}
    string getName() const { return name; }
    string getId() const { return id; }
    int getBalance() const { return balance; }

    void operator+(Account &acnt)
    {
        this->balance += acnt.getBalance();
    }

    void operator-(Account &acnt)
    {
        this->balance -= acnt.getBalance();
    }
};

ostream &operator<<(ostream &cout, Account &acnt)
{
    cout << "학번: " << acnt.getId() << ", 이름: " << acnt.getName() << ", 잔액: " << acnt.getBalance();
    return cout;
}

int main()
{
    Account acnt[3] = {
        Account("장윤호", "2014", 10000),
        Account("김유민", "2019", 0),
        Account("박진배", "2013", 5000)};

    string id_out, id_in;

    while (1)
    {
        cout << "돈을 보낼 학생의 학번을 입력하세요: ";
        cin >> id_out;
        cout << "돈을 받을 학생의 학번을 입력하세요: ";
        cin >> id_in;

        if (id_out == "종료")
        {
            cout << "종료합니다." << endl;
            cout << acnt[0] << endl;
            cout << acnt[1] << endl;
            cout << acnt[2] << endl;
            break;
        }

        if (id_out == id_in)
        {
            continue;
        }

        int out_index = -1, in_index = -1;
        for (int i = 0; i < 3; i++)
        {
            if (acnt[i].getId() == id_out)
            {
                out_index = i;
            }
            if (acnt[i].getId() == id_in)
            {
                in_index = i;
            }
        }

        if (out_index == -1 || in_index == -1)
        {
            cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다.다시 입력해주세요." << endl;
            continue;
        }

        if (acnt[out_index].getBalance() == 0)
        {
            cout << "보내는 학생의 잔액이 부족합니다." << endl;
            continue;
        }

        acnt[in_index] + acnt[out_index];
        acnt[out_index] - acnt[out_index];
        cout << "보낸 학생의 잔액 => " << acnt[out_index] << endl;
        cout << "받은 학생의 잔액 => " << acnt[in_index] << endl;
    }
    return 0;
}
