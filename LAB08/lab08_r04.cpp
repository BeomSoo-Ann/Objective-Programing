#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int inputGrade(float grade);
int topGrade(const vector<int> &grades);

int main()
{
    vector<int> grades;
    float _grade = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Input" << i << "-th grade(0~100):";
        int grade = inputGrade(_grade);
        grades.push_back(grade);
    }

    int max = topGrade(grades);

    cout << "Top Grade: " << max << endl;

    return 0;
}

int inputGrade(float grade)
{
    cin >> grade;
    if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100)
    {
        cout << "invalid input!!!" << endl;
        exit(EXIT_FAILURE);
    }

    else
        return (int)grade;
}

int topGrade(const vector<int> &grades)
{
    int max = 0;
    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i] > max)
            max = grades[i];
    }
    return max;
}