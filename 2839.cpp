#include <iostream>

int main()
{
    using namespace std;
    int N;
    int n_3, n_5;
    cin >> N;

    n_3 = N % 5;

    if (n_3 == 3)
    {
        n_5 = N - n_3;
        cout << n_5 / 5 + n_3 / 3 << endl;
    }
    else if (N >= 6 && n_3 == 1)
    {
        n_3 += 5;
        n_5 = N - n_3;
        cout << n_5 / 5 + n_3 / 3 << endl;
    }
    else if (N >= 12 && n_3 == 2)
    {
        n_3 += 10;
        n_5 = N - n_3;
        cout << n_5 / 5 + n_3 / 3 << endl;
    }
    else if (N >= 9 && n_3 == 4)
    {
        n_3 += 5;
        n_5 = N - n_3;
        cout << n_5 / 5 + n_3 / 3 << endl;
    }
    else if (n_3 == 0)
    {
        n_5 = N;
        cout << n_5 / 5 << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}