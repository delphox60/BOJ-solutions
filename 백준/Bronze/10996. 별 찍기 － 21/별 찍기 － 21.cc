#include <iostream>

using namespace std;

void draw(int x)
{
    for (int i = 1; i <= x; i++)
    {
        if (i % 2)
            cout << '*';
        else
            cout << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= x; i++)
    {
        if (i % 2)
            cout << ' ';
        else
            cout << '*';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        draw(n);
}