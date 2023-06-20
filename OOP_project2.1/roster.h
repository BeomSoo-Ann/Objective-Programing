#pragma once
#include <iostream>
#include <string>

class Roster
{
public:
    std::string studentList;

    Roster();

    void addStudent(std::string student);
    void print();
};