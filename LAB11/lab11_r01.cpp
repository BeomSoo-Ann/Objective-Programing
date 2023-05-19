#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point operator-(const Point &pt1)
    {
        Point result(this->x - pt1.getX(), this->y - pt1.getY());
        return result;
    }

    Point operator*(const Point &pt2)
    {
        Point result(this->x * pt2.getX(), this->y * pt2.getY());
        return result;
    }

    void setPoint(int _x, int _y)
    {
        this->x = _x;
        this->y = _y;
    }

    Point operator=(const Point &pt)
    {
        this->x = pt.getX();
        this->y = pt.getY();
        return (*this);
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

int main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    Point *pP1, *pP2, *pP3;

    cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
    cin >> x1 >> y1;

    cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
    cin >> x2 >> y2;

    pP1 = new Point(x1, y1);
    pP2 = new Point(x2, y2);

    pP3 = new Point();

    *pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

    cout << "두 좌표 사이의 길이는 " << sqrt(pP3->getX() + pP3->getY()) << "입니다." << endl;

    delete pP1;
    delete pP2;
    delete pP3;

    return 0;
}