//* 0 0 0 0 0 0 0 0 0 0
//* 0 0 0 0 0 0 0 0 0 0
//* 0 0 2 0 0 0 0 0 2 0
//* 0 0 0 0 0 0 0 0 1 0
//* 0 0 0 0 0 0 0 0 0 0
//* 0 0 0 0 0 0 0 0 0 0
//* 0 0 0 0 0 0 0 0 0 0
//* 0 0 0 0 2 1 0 0 0 0
//* 0 0 0 0 0 0 0 0 0 0
//* 0 0 0 0 0 0 0 0 0 0

#include <iostream>

using namespace std;

int board[22][22];

bool check(int x1, int x2, int y1, int y2)
{
    int jew = 0;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (board[i][j] == 1)
                return false;
            else if (board[i][j] == 2)
                jew++;
        }
    }
    if (jew == 1)
    {
        // cout << x1 << "~" << x2 << ", " << y1 << "~" << y2 << "\n";
        return true;
    }
    return false;
}

bool checkCol(int r1, int r2, int x, int y)
{
    for (int i = r1; i <= r2; i++)
        if (board[i][y] == 2)
            return false;
    return true;
}

bool checkRow(int c1, int c2, int x, int y)
{
    for (int i = c1; i <= c2; i++)
        if (board[x][i] == 2)
            return false;
    return true;
}

int func(int x1, int x2, int y1, int y2, int dir)
{
    if (check(x1, x2, y1, y2))
        return 1;

    int countV = 0;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (board[i][j] == 1)
            {
                if (dir && checkCol(x1, x2, i, j))
                {
                    countV += func(x1, x2, y1, j - 1, 0) * func(x1, x2, j + 1, y2, 0);
                    //     cout << x1 << "~" << x2 << ", " << y1 << "~" << y2 << " " << countV << "\n";
                }

                if (!dir && checkRow(y1, y2, i, j))
                {
                    // cout << func(x1, x2, y1, j - 1) * func(x1, x2, j + 1, y2) << "\n";

                    countV += func(x1, i - 1, y1, y2, 1) * func(i + 1, x2, y1, y2, 1);
                    //     cout << x1 << "~" << x2 << ", " << y1 << "~" << y2 << " " << countV << "\n";
                }
            }
        }
    }
    return countV;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    int result = func(1, n, 1, n, 1) + func(1, n, 1, n, 0);
    if (result == 0)
        cout << -1 << "\n";
    else
        cout << result << "\n";

    return 0;
}