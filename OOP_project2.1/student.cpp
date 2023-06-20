#include "student.h"

Student::Student() {}
Student::Student(std::string student)
{
    m_student = student;
}

void Student::getSchedule()
{
    m_courseList = courseList;
}

void Student::print()
{
    std::cout << "Student Name: " << m_student << std::endl;
    std::cout << "List of Courses" << std::endl;

    for (int i = 0; i < m_courseList.size(); i++)
    {
        if (m_courseList[i] == ',')
            std::cout << std::endl;
        else
            std::cout << m_courseList[i];
    }

    std::cout << std::endl;
}
