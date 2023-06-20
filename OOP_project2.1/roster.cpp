#include "roster.h"

Roster::Roster() {}

void Roster::addStudent(std::string student)
{
    studentList += student + ",";
}

void Roster::print()
{
    std::cout << "List of Students" << std::endl;

    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i] == ',')
            std::cout << std::endl;
        else
            std::cout << studentList[i];
    }

    std::cout << std::endl;
}