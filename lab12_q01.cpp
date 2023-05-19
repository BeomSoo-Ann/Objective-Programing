#include <iostream>
#include <string>

using namespace std;

class Base
{
protected:
    void print_base()
    {
        cout << "Base" << endl;
    }
};

// Base type | 상속 type | Derived type
// private | 상관없음 | 접근 불가( Base함수로 접근)
// protected | 상관없음 | private
// public | private/protected | private
// public | public | public

class Derived : public Base
{
public:
    void print_derived()
    {
        // 구현 //
        print_base();
        cout << "Derived" << endl;
    }
};

int main()
{
    Base base;
    Derived derived;

    // base.print_base(); // 접근 불가
    derived.print_derived();

    return 0;
}