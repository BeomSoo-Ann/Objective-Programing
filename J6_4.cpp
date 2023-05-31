#include <iostream>

using namespace std;

class Rectangle {
private:
    int width = 0;
    int height = 0;

public:
    static int Vertex;

    int setWidth(int width) {
        this->width = width;
        return getArea();
    }
    int setHeight(int height) {
        this->height = height;
        return getArea();
    }
    int getArea() {
        return width * height;
    }
};

int Rectangle::Vertex = 4;

int main(void) {
    // Static ���� 1
    cout << "�簢���� �������� " << Rectangle::Vertex << "�� �Դϴ�." << endl;

    Rectangle rect;
    // Static ���� 2
    cout << "�簢���� �������� " << rect.Vertex << "�� �Դϴ�." << endl;

    rect.setHeight(30);
    rect.setWidth(40);

    cout << "���̰� 30�̰� �ʺ� 40�� �簢���� ���̴� " << rect.getArea() << "�Դϴ�.";
}