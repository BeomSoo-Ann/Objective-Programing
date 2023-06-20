#pragma once
#include "schedule.h"

class Student : public Schedule
{
public:
    std::string m_courseList;
    std::string m_student;

    Student();
    Student(std::string student);

    void getSchedule();
    void print();
};