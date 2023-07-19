#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Rectangle
{
private:
    T width;
    T height;

public:
    Rectangle(T w, T h) : width(w), height(h) {}

    T getArea() const
    {
        return width * height;
    }

    void printInfo() const
    {
        cout << "Rectangle (width: " << width << ", height: " << height << ")" << endl;
    }
};

template <typename T>
class Circle
{
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    T getArea() const
    {
        return 3.14159 * radius * radius;
    }

    void printInfo() const
    {
        cout << "Circle (radius: " << radius << ")" << endl;
    }
};

int main()
{
    vector<Rectangle<int>> rectangles;
    rectangles.push_back(Rectangle<int>(4, 6));

    vector<Rectangle<double>> otherRectangles;
    otherRectangles.push_back(Rectangle<double>(2.5, 5.4));

    vector<Circle<double>> circles;
    circles.push_back(Circle<double>(3.5));

    for (const auto &rectangle : rectangles)
    {
        rectangle.printInfo();
        cout << "Area: " << rectangle.getArea() << endl;
    }

    for (const auto &otherRectangle : otherRectangles)
    {
        otherRectangle.printInfo();
        cout << "Area: " << otherRectangle.getArea() << endl;
    }

    for (const auto &circle : circles)
    {
        circle.printInfo();
        cout << "Area: " << circle.getArea() << endl;
    }

    return 0;
}