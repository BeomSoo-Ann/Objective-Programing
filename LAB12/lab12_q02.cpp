#include <iostream>
#include <string>

using namespace std;

// 함수 오버로딩: int sum(int x, int y),
//            double sum(double x, double y)
//            float sum(float x, float y, float z)
// 함수 오버라이딩 (상속의 특수한 경우 사용)
// void Text::append(string _extra)
// void Fancy::append(string _extra)

class Text
{
private:
    string text;

public:
    Text(string _t) : text(_t) {}
    // get() 함수 virtual로 선언
    virtual string get()
    {
        return text;
    }

    virtual void append(string _extra)
    {
        text += _extra;
    }
};

class FancyText : public Text
{
private:
    // string text;b접근이 안됨, Base Class에서 private
    string left_bracket;
    string right_bracket;
    string connector;

public:
    // initialization list는 생성자를 호출할 수 있게 해준다.
    FancyText(string _t, string _lb, string _rb, string _c) : Text::Text(_t), left_bracket(_lb), right_bracket(_rb), connector(_c) {}

    // override 키워드 사용한 get()함수 구현, main함수 참고하여 출력화면처럼 되도록 구현
    string get() override
    {
        return left_bracket + Text::get() + right_bracket;
    }

    // override 키워드 사용한 append()함수 구현
    void append(string _extra) override
    {
        Text::append(connector + _extra);
    }
};

class FixedText : public Text
{
public:
    FixedText() : Text::Text("FIXED") {}
    void append(const string _extra) override
    {
        // do nothing
    }
};

int main()
{
    Text t1("Plain");
    t1.append("A");
    cout << t1.get() << endl;

    FancyText t2("Fancy", "<<", ">>", "***");
    t2.append("A");
    cout << t2.get() << endl;

    FixedText t3;
    t3.append("A");
    cout << t3.get() << endl;
    t1 = t2; // Base <- Derived 가능
    // t2 = t1; //  Derived <- Base 불가능
    return 0;
}
