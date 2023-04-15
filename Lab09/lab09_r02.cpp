#include <iostream>

using namespace std;

int *make_arr(int n);
int sum_arr(int *a, int n);
void print_arr(int *a, int n);

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int *arr = make_arr(n);
    print_arr(arr, n);

    int sum = sum_arr(arr, n);
    cout << "\nSum of the array: " << sum << endl;

    delete[] arr;
    return 0;
}

int *make_arr(int n)
{
    int *result = new int[n];
    int *begin = result;
    int *end = result + n;

    result[0] = 1;

    for (int *curr = begin + 1; curr != end; curr++)
    {
        *curr = *(curr - 1) + 2;
    }

    return result;
}

int sum_arr(int *a, int n)
{
    int s = 0;

    while (n--)
    {
        s += *a++;
    }

    return s;
}

void print_arr(int *a, int n)
{
    cout << "\nOdd number Array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}