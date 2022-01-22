#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int j = 0; j < (n - 1); j++)
        cout << ' ';
    cout << '*';
    cout << '\n';
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
            cout << ' ';
        cout << '*';
        for (int j = 0; j < ((i - 1) * 2 - 1); j++)
            cout << ' ';
        cout << '*';

        cout << '\n';
    }
    if (n != 1)
    {
        for (int i = 0; i < (2 * n) - 1; i++)
            cout << '*';
        cout << '\n';
    }
}