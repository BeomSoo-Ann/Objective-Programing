#pragma once
#include "Text.h"

using namespace std;

class FancyText : public Text
{
private:
    // string text;b접근이 안됨, Base Class에서 private
    string left_bracket;
    string right_bracket;
    string connector;

public:
    // initialization list는 생성자를 호출할 수 있게 해준다.
    FancyText(string _t, string _lb, string _rb, string _c);
    // override 키워드 사용한 get()함수 구현, main함수 참고하여 출력화면처럼 되도록 구현
    string get() override;

    // override 키워드 사용한 append()함수 구현
    void append(string _extra) override;
};
