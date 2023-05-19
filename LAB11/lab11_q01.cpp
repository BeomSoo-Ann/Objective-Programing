#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
    static int numCreatedObjects;

public:
    Point() : x(0), y(0)
    {
        numCreatedObjects++;
    }

    // int _x와 int _y를 매개변수로 받는 생성자
    Point(int _x, int _y) : x(_x), y(_y)
    {
        numCreatedObjects++;
    }

    ~Point()
    {
        cout << "Destructed..." << endl;
    }

    void setXY(int _x, int _y)
    {
        // this-> 사용해서 초기화
        this->x = _x;
        this->y = _y;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    // *this + p2 ->
    Point operator+(Point &p2)
    {
        Point p3;
        p3.x = this->x + p2.getX();
        p3.y = this->y + p2.getY();
        return p3;
    }

    // operator overloading
    Point &operator=(Point &pt)
    {
        this->x = pt.getX();
        this->y = pt.getY();
        return *this;
    }

    static int getNumCreatedObject()
    {
        return numCreatedObjects;
    }

    friend void print(const Point &pt);
    friend ostream &operator<<(ostream &cout, Point &pt);
    friend class SpyPoint;
};

// static 멤버 변수 초기화 (numCreatedObjects)
int Point::numCreatedObjects = 0;

// 객체 call by reference시: const로 함수 입력시 const method만 함수에서 사용가능
// const: 객체 내부의 member data가 상수(변하지 않는다)

void print(const Point &pt)
{
    cout << pt.x << ", " << pt.y << endl;
}

// Point operator+(Point& pt1, Point& pt2)
// {
//     Point result(pt1.getX() + pt2.get(X), pt1.getY() + pt2.getY());
//     return result;
// }

ostream &operator<<(ostream &cout, Point &pt)
{
    cout << pt.x << ", " << pt.y;
    return cout;
}

class SpyPoint
{
public:
    // hack_all_info

    // Hacked by SpyPoint
    // x: 40
    // y: 60
    // numCreatedObj.: 10

    void hack_all_info(Point &pt)
    {
        cout << "Hacked by SpyPoint" << endl;
        cout << "x: " << pt.x << endl;
        cout << "y: " << pt.y << endl;
        cout << "numCreatedObj.: " << pt.numCreatedObjects << endl;
    }
};

int main()
{
    Point pt1(1, 2);
    cout << "pt1 : ";
    print(pt1);
    cout << endl;

    // 포인터
    Point *pPt1 = &pt1;
    // pPt1의 값을 통해 getX(), getY() 호출하여 출력
    cout << "pt1 : ";
    cout << pPt1->getX() << ", " << pPt1->getY() << endl;

    // pPt1을 통해 getX(), getY() 호출하여 출력
    cout << "pt1 : ";
    cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;

    cout << endl;

    Point *pPt2 = new Point(10, 20);

    cout << "pt2 : ";
    cout << pPt2->getX() << ", " << pPt2->getY() << endl;
    cout << endl;

    delete pPt2;

    cout << "pt1 NumCreatedObjects : ";
    cout << pt1.getNumCreatedObject() << endl;

    // 연산자 오버로딩
    // pt4 = pt2 + pt3

    Point pt2(10, 20), pt3(30, 40);
    Point pt4 = pt2 + pt3;

    cout << "pt2 : ";
    cout << pt2 << endl;
    cout << "pt3 : ";
    cout << pt3 << endl;
    cout << "pt4 : ";
    cout << pt4 << endl;

    cout << "pt1 NumCreatedObjects : ";
    cout << pt1.getNumCreatedObject() << endl
         << endl;

    // object array
    Point *ptAry = new Point[5];

    cout << "pt2 NumCreatedObjects : ";
    cout << pt2.getNumCreatedObject() << endl;
    cout << endl;

    delete[] ptAry;

    cout << endl;

    // friend class
    SpyPoint spy;
    cout << "pt1 info" << endl;
    spy.hack_all_info(pt1);
    cout << endl;

    cout << "pt4 info" << endl;
    spy.hack_all_info(pt4);
    cout << endl;

    return 0;
}