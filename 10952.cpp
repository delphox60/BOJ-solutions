#include <iostream>

int main()
{
    using namespace std;
    int a, b;
    while (cin >> a >> b)
        if (a != 0 || b != 0)
            cout << a + b << endl;
    return 0;
}