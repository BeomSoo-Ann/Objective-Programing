#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool isPrime(int n);
vector<int> primes(int lower, int upper);

int main()
{
    int lower = 10, upper = 100;
    vector<int> vec = primes(lower, upper);

    for (int elem : vec)
        cout << elem << setw(5);

    cout << endl;

    return 0;
}

bool isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

vector<int> primes(int lower, int upper)
{
    vector<int> v;
    for (int i = lower; i <= upper; i++)
    {
        if (isPrime(i))
            v.push_back(i);
    }
    return v;
}