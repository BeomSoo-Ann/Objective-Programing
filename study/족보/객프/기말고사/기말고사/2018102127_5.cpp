#include <iostream> 
#include<string>
#include<algorithm>
using namespace std;

template<class T>
class Point {

public:
    T x;
    T y;

    Point(T _x, T _y) : x(_x), y(_y) {}

    void display() {
        cout << "x: " << x << "y: " << y << endl;
    }
};

void get_command(string& command) {
    cout << "Enter your command: ";
    string input;
    cin >> input;
    command = input;
}

template <typename Iter, typename T>
void count_val(Iter iter_begin, Iter iter_end, const T& seek) {
    int cnt = 0;
    for (auto cursor = iter_begin; cursor != iter_end; cursor++)
        if (*cursor == seek)
            cnt++;
    cout << "number of the values: " << cnt << endl;
}
int main() {

    Point<int> myPoints[] = { {1, 2}, {-1, 5}, {3, 7}, {2, 4}, {1, 10}, {1, 2} };

    string command;



    while (1) {

        get_command(command);

        if (command == "1")    for_each(begin(myPoints), end(myPoints), [](Point x) {x.display(); });

        else if (command == "2")    count_val<int>(myPoints);

        else if (command == "0")      break;

    }

    cout << "Exit program.." << endl;

    return 0;

}