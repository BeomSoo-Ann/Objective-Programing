#include <iostream>

using namespace std;

class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D() {}
    Vector2D(double _x, double _y) : x(_x), y(_y) {}

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    Vector2D operator+(Vector2D &pt1)
    {
        Vector2D pt2;
        pt2.x = this->x + pt1.getX();
        pt2.y = this->y + pt1.getY();
        return pt2;
    }

    Vector2D operator-(Vector2D &pt1)
    {
        Vector2D pt2;
        pt2.x = this->x - pt1.getX();
        pt2.y = this->y - pt1.getY();
        return pt2;
    }

    Vector2D operator*(double num)
    {
        Vector2D pt1;
        pt1.x = this->x * num;
        pt1.y = this->y * num;
        return pt1;
    }

    Vector2D &operator=(Vector2D &pt)
    {
        this->x = pt.getX();
        this->y = pt.getY();
        return *this;
    }

    friend ostream &operator<<(ostream &cout, Vector2D &pt);
};

ostream &operator<<(ostream &cout, Vector2D &pt)
{
    cout << "(" << pt.x << ", " << pt.y << ")";
    return cout;
}

int main()
{
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    Vector2D sum = v1 + v2;
    Vector2D difference = v1 - v2;
    Vector2D scaled = v1 * 2.5;

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v1 + v2: " << sum << endl;
    cout << "v1 - v2: " << difference << endl;
    cout << "v1 * 2.5: " << scaled << endl;

    return 0;
}
