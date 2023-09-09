#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    int tmp;

    while (true)
    {
        cin >> a >> b >> c;

        if (a < b)
        {
            tmp = a;
            a = b;
            b = tmp;
        }

        if (a < c)
        {
            tmp = a;
            a = c;
            c = tmp;
        }

        if (b < c)
        {
            tmp = b;
            b = c;
            c = tmp;
        }

        if (a == 0)
        {
            break;
        }

        if (a >= b + c)
        {
            cout << "Invalid\n";
            continue;
        }

        else if (a == b || b == c || a == c)
        {
            if (a == b && b == c)
            {
                cout << "Equilateral\n";
                continue;
            }
            cout << "Isosceles\n";
            continue;
        }

        cout << "Scalene\n";
    }
}