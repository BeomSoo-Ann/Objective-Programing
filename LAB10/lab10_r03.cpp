#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    int id;
    string name;
    string major;

    vector<string> subjects;
    vector<char> grades;

public:
    Student(string _name, int _id, string _major) : name(_name), id(_id), major(_major) {}
    Student() : name("default"), id(0), major("depart") {}

    void setName(string _name)
    {
        name = _name;
    }

    void setID(int _id)
    {
        id = _id;
    }

    void setDpt(string _major)
    {
        major = _major;
    }

    void print()
    {
        cout << getName() << " " << getID() << " " << getDpt() << endl;
    }

    void addGrade(string subject, char grade)
    {
        subjects.push_back(subject);
        grades.push_back(grade);
    }

    void printGrades()
    {
        for (int i = 0; i < subjects.size(); i++)
        {
            cout << subjects[i] << " " << grades[i] << endl;
        }
        cout << "GPA: " << getGPA();
    }

    void getYear(int year)
    {
        int grade = year - (getID() / 1000000) + 1;

        if (grade == 1)
        {
            cout << "Freshman(1학년)" << endl;
        }
        else if (grade == 2)
        {
            cout << "Sophomore(2학년)" << endl;
        }
        else if (grade == 3)
        {
            cout << "Junior(3학년)" << endl;
        }
        else if (grade == 4)
        {
            cout << "Senior(4학년)" << endl;
        }
        else
        {
            cout << "About to graduate(" << grade << "학년)" << endl;
        }
    }

    float getGPA()
    {
        float sum = 0;
        float result;
        for (int i = 0; i < grades.size(); i++)
        {
            if (grades[i] == 'A')
            {
                sum += 4;
            }
            else if (grades[i] == 'B')
            {
                sum += 3;
            }
            else if (grades[i] == 'C')
            {
                sum += 2;
            }
            else if (grades[i] == 'D')
            {
                sum += 1;
            }
            else if (grades[i] == 'F')
            {
                sum += 0;
            }
        }
        result = sum / grades.size();
        return result;
    }

    int getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getDpt()
    {
        return major;
    }
};

int main()
{
    Student Harry("Harry", 2017310973, "CS");
    Harry.print();
    Harry.getYear(2019);
    Harry.addGrade("programming", 'A');
    Harry.addGrade("Basic Circuit", 'B');
    Harry.printGrades();
    cout << "\n\n";

    Student Ron;
    Ron.print();
    cout << "\n";
    Ron.setName("Ron");
    Ron.setID(2014103959);
    Ron.setDpt("EE");
    Ron.print();
    Ron.getYear(2019);
    Ron.addGrade("Computer Architecture", 'B');
    Ron.addGrade("Maching Learning", 'B');
    Ron.addGrade("Computer Vision", 'C');
    Ron.printGrades();
    cout << "\n\n";
    return 0;
}