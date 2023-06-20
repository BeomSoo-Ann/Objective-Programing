#include <iostream>
#include <string>

class Schedule
{
public:
    std::string courseList;

    Schedule() {}

    void addCourse(std::string course)
    {
        courseList += course + ",";
    }

    void print()
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
};

class Roster
{
public:
    std::string studentList;

    Roster() {}

    void addStudent(std::string student)
    {
        studentList += student + ",";
    }

    void print()
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
};

// 학생 정보 (이름, 수강 과목)
class Student : public Schedule
{
public:
    std::string m_courseList;
    std::string m_student;
    Student() {}
    Student(std::string student) : m_student(student) {}

    void getSchedule()
    {
        m_courseList = courseList;
    }

    void print()
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
};

// 코스 (과목명, 명단)
class Course : public Roster
{
public:
    std::string m_studentList;
    std::string m_course;
    int max;
    Course() {}
    Course(std::string course, int num) : m_course(course), max(num) {}

    void getRoster()
    {
        m_studentList = studentList;
    }

    void print()
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
};

// 등록 (학생 정보, 코스)
class Registrar
{
public:
    Student *m_student;
    Course *m_course;

    Registrar() {}

    void enroll(Student &student, Course &course)
    {
        m_student = &student;
        m_course = &course;

        m_student->addCourse(course.m_course);
        m_student->getSchedule();
        m_course->addStudent(student.m_student);
        m_course->getRoster();
    }
};

int main()
{
    // Registrar 객체 인스턴스화
    Registrar registrar;
    // Student 객체 인스턴스화
    Student student1("John");
    Student student2("Mary");
    Student student3("Ann");
    // Course 객체 3개 인스턴스화
    Course course1("CIS101", 4);
    Course course2("CIS102", 3);
    Course course3("CIS103", 3);
    // Registrar 객체를 기반으로 학생이 과목 수강 등록
    registrar.enroll(student1, course1);
    registrar.enroll(student1, course2);
    registrar.enroll(student2, course1);
    registrar.enroll(student2, course3);
    registrar.enroll(student3, course1);
    // Student 객체의 정보 출력
    student1.print();
    student2.print();
    student3.print();
    // Course 객체의 정보 출력
    course1.print();
    course2.print();
    course3.print();
    return 0;
}