#pragma once
#include <iostream>
#include <string>

class Schedule
{
public:
    std::string courseList;

    Schedule();

    void addCourse(std::string course);
    void print();
};