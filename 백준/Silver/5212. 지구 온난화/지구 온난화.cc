#include <iostream>
#include <cstring>

using namespace std;

bool isIce[10][10];
bool willBeSolved[10][10];

bool isEmptyCol(int c)
{
    for (int i = 0; i < 10; i++)
    {
        if (isIce[i][c])
            return false;
    }
    return true;
}

bool isEmptyRow(int r)
{
    for (int i = 0; i < 10; i++)
    {
        if (isIce[r][i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    string ip;

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        cin >> ip;
        for (int j = 0; j < c; j++)
        {
            isIce[i][j] = (ip[j] == 'X');
            willBeSolved[i][j] = false;
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                if (i + dx[d] < 0 || j + dy[d] < 0 || i + dx[d] >= r || j + dy[d] >= c)
                {
                    cnt++;
                    continue;
                }
                if (!isIce[i + dx[d]][j + dy[d]])
                    cnt++;
            }
            if (cnt >= 3)
            {
                willBeSolved[i][j] = true;
            }
        }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (willBeSolved[i][j])
                isIce[i][j] = false;
        }

    int sx = 0;
    int sy = 0;
    int ex = r - 1;
    int ey = c - 1;

    while (isEmptyRow(sx))
    {
        sx++;
    }

    while (isEmptyRow(ex))
    {
        ex--;
    }

    while (isEmptyCol(sy))
    {
        sy++;
    }

    while (isEmptyCol(ey))
    {
        ey--;
    }

    for (int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)
        {
            cout << (isIce[i][j] ? "X" : ".");
        }
        cout << '\n';
    }
}