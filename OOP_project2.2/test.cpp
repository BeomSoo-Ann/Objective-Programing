#include <string>
#include <iostream>

using namespace std;
class Vacation
{
public:
    virtual void bookHotels(){};
    virtual void bookFlights(){};
    virtual void bookTours(){};
};

class Package1 : public Vacation
{
    void bookHotels()
    {
        cout << "Hotels are booked." << endl;
    }

    void bookFlights()
    {
        cout << "Flights are booked." << endl;
    }

    void bookTours()
    {
        cout << "Run:";
    };
};

class Package2 : public Vacation
{
    void bookHotels()
    {
        cout << "Hotels are booked." << endl;
    }

    void bookFlights(){};

    void bookTours()
    {
        cout << "Tours are booked.";
    }
};

class Package3 : public Vacation
{
    void bookHotels()
    {
        cout << "Hotels are booked." << endl;
    }

    void bookFlights()
    {
        cout << "Flights are booked." << endl;
    }

    void bookTours()
    {
        cout << "Tours are booked.";
    }
};

class Director
{
public:
    static Vacation *vacation;
    static void book(int type); // 클라이언트는 이 함수만 호출 가능
};

Vacation *Director::vacation = 0;
// 클라이언트가 호출할 정적 멤버 함수 정의
void Director::book(int packageType)
{
    if (packageType == 1)
    {
        vacation = new Package1();
    }
    else if (packageType == 2)
    {
        vacation = new Package2();
    }
    else if (packageType == 3)
    {
        vacation = new Package3();
    }
    cout << "This is information about your vacation: " << endl;
    vacation->bookHotels();
    vacation->bookFlights();
    vacation->bookTours();
    cout << endl;
}

int main()
{
    // 여행 유형 선택
    int type = 1;
    while (type >= 1 && type <= 3)
    {
        cout << "Enter the type of vacation (1, 2, 3): ";
        cin >> type;
        // 여행 계획 확인
        Director::book(type);
    }
    return 0;
}
