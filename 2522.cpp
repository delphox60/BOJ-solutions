#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
            cout << ' ';
        for (int j = 0; j < i; j++)
            cout << '*';
        cout << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << ' ';
        for (int j = 0; j < (n - i); j++)
            cout << '*';
        cout << '\n';
    }
}