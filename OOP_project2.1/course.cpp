#include "course.h"

Course::Course() {}
Course::Course(std::string course, int num)
{
    m_course = course;
    max = num;
}

void Course::getRoster()
{
    m_studentList = studentList;
}

void Course::print()
{
    std::cout << "Course Name: " << m_course << std::endl;
    std::cout << "Number of Units: " << max << std::endl;
    std::cout << "List of Students" << std::endl;

    for (int i = 0; i < m_studentList.size(); i++)
    {
        if (m_studentList[i] == ',')
            std::cout << std::endl;
        else
            std::cout << m_studentList[i];
    }

    std::cout << std::endl;
}