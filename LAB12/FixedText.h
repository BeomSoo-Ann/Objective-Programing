#pragma once
#include "Text.h"

using namespace std;

class FixedText : public Text
{
public:
    FixedText();
    void append(const string _extra) override;
};
