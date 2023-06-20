#pragma once
#include "roster.h"

class Course : public Roster
{
public:
    std::string m_studentList;
    std::string m_course;
    int max;

    Course();
    Course(std::string course, int num);

    void getRoster();
    void print();
};