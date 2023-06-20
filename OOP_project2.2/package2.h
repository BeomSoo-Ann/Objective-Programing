#pragma once
#include "vacation.h"

using namespace std;

class Package2 : public Vacation
{
public:
    void bookHotels();
    void bookFlights();
    void bookTours();
};