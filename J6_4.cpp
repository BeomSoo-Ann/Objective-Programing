#include <iostream>

using namespace std;

class Rectangle
{
private:
    int width = 0;
    int height = 0;

public:
    // 정적 변수 선언
    static int Vertex;

    // 멤버 변수와 이름이 같은 매개 변수를 가진 생성자(또는 멤버 함수)가 있는 경우: this를 사용해서 구분할 수 있다.
    int setWidth(int width)
    {
        this->width = width;
        return getArea();
    }
    int setHeight(int height)
    {
        this->height = height;
        return getArea();
    }
    int getArea()
    {
        return width * height;
    }
};

// 정적 변수 메모리 할당
int Rectangle::Vertex = 4;

int main(void)
{
    // Static 접근 1
    cout << "사각형의 꼭짓점은 " << Rectangle::Vertex << "개 입니다." << endl;

    Rectangle rect;
    // Static 접근 2
    cout << "사각형의 꼭짓점은 " << rect.Vertex << "개 입니다." << endl;

    rect.setHeight(30);
    rect.setWidth(40);

    cout << "높이가 30이고 너비가 40인 사각형의 넓이는 " << rect.getArea() << "입니다.";
}