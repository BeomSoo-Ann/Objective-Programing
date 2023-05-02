#include <iostream>
#include <cmath>

int distance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int dot_product(int v1[], int v2[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += v1[i] * v2[i];
    }

    return sum;
}

int compute(int &a, int &b, int &c, int &d, int (*f)(int, int, int, int))
{
    return f(a, b, c, d);
}

int compute2(int l1[], int l2[], int &n, int (*f)(int *, int *, int))
{
    return f(l1, l2, n);
}

int main()
{
    int x1 = 1;
    int y1 = 2;
    int x2 = 4;
    int y2 = 6;

    int v1[] = {1, 2, 3};
    int v2[] = {4, 5, 6};
    int size = sizeof(v1) / sizeof(v1[0]);

    int result1 = compute(x1, y1, x2, y2, distance);
    int result2 = compute2(v1, v2, size, dot_product);

    std::cout << "The distance between (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is " << result1 << std::endl;
    std::cout << "The dot product of [" << v1[0] << "," << v1[1] << "," << v1[2] << "] and [" << v2[0] << "," << v2[1] << "," << v2[2] << "] is " << result2 << std::endl;

    return 0;
}