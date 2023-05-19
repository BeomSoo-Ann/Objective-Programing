#include "FancyText.h"

FancyText::FancyText(string _t, string _lb, string _rb, string _c) : Text::Text(_t), left_bracket(_lb), right_bracket(_rb), connector(_c) {}

string FancyText::get()
{
    return left_bracket + Text::get() + right_bracket;
}

void FancyText::append(string _extra)
{
    Text::append(connector + _extra);
}