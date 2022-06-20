#include <iostream>

using namespace std;

int b = 0;
int w = 0;

bool paper[130][130];

bool isBlue(int x, int y, int d)
{
    for (int i = x; i < x + d; i++)
        for (int j = y; j < y + d; j++)
            if (!paper[i][j])
                return false;
    b++;
    return true;
}

bool isWhite(int x, int y, int d)
{
    for (int i = x; i < x + d; i++)
        for (int j = y; j < y + d; j++)
            if (paper[i][j])
                return false;
    w++;
    return true;
}

void func(int x, int y, int d)
{
    if (d < 1)
        return;

    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
        {
            if (isBlue(x + i * d, y + j * d, d) || isWhite(x + i * d, y + j * d, d))
                continue;
            func(x + i * d, y + j * d, d / 2);
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
            cin >> paper[i][j];

    if (!(isBlue(0, 0, n) || isWhite(0, 0, n)))
        func(0, 0, n / 2);

    cout << w << '\n'
         << b;
}
