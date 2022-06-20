#include <iostream>

using namespace std;

bool star[2200][2200];

void func(int x, int y, int d)
{
    if (d <= 1)
    {
        star[x][y] = true;
    }

    if (d < 1)
        return;

    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
        {
            if (i == 1 && j == 1)
                continue;
            func(x + d * i, y + d * j, d / 3);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            star[i][j] = false;

    func(0, 0, n / 3);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << (star[i][j] ? "*" : " ");
        cout << '\n';
    }
}