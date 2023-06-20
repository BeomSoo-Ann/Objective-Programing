#pragma once
#include "student.h"
#include "course.h"

class Registrar
{
public:
    Student *m_student;
    Course *m_course;

    Registrar();

    void enroll(Student &student, Course &course);
};