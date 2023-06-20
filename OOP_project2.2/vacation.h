#pragma once
#include <iostream>
#include <string>

class Vacation
{
public:
    virtual void bookHotels();
    virtual void bookFlights();
    virtual void bookTours();
};