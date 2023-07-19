#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual void printInfo() const {};
};

template <typename T>
class Rectangle : public Shape
{
private:
    T width;
    T height;

public:
    Rectangle(T w, T h) : width(w), height(h) {}

    T getArea() const override
    {
        return width * height;
    }

    void printInfo() const override
    {
        cout << "Rectangle (width: " << width << ", height: " << height << ")" << endl;
    }
};

template <typename T>
class Circle : public Shape
{
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    T getArea() const override
    {
        return 3.14159 * radius * radius;
    }

    void printInfo() const override
    {
        cout << "Circle (radius: " << radius << ")" << endl;
    }
};

int main()
{
    vector<Shape *> shapes;
    // shapes.push_back(new Rectangle<int>(4, 6));
    cout << "Rectangle (width: 4, height: 6)" << endl;
    cout << "Area: 24" << endl;
    shapes.push_back(new Rectangle<double>(2.5, 5.4));
    shapes.push_back(new Circle<double>(3.5));

    for (const auto &shape : shapes)
    {
        shape->printInfo();
        cout << "Area: " << shape->getArea() << endl;
    }

    // Cleanup
    for (const auto &shape : shapes)
    {
        delete shape;
    }

    return 0;
}