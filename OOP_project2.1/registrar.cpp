#include "registrar.h"

Registrar::Registrar() {}

void Registrar::enroll(Student &student, Course &course)
{
    m_student = &student;
    m_course = &course;

    m_student->addCourse(course.m_course);
    m_student->getSchedule();
    m_course->addStudent(student.m_student);
    m_course->getRoster();
}