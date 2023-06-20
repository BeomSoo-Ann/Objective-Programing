#include "schedule.h"

Schedule::Schedule() {}

void Schedule::addCourse(std::string course)
{
    courseList += course + ",";
}

void Schedule::print()
{
    std::cout << "List of Courses" << std::endl;

    for (int i = 0; i < courseList.size(); i++)
    {
        if (courseList[i] == ',')
            std::cout << std::endl;
        else
            std::cout << courseList[i];
    }

    std::cout << std::endl;
}