#include <iostream>

using namespace std;

int board[20][20];

bool checkNext(int r, int c, int i, int j)
{
    int cur = board[r][c];

    if (r + i < 1 || r + i > 19 || c + j < 1 || c + j > 19)
        return true;

    if (cur == board[r + i][c + j])
        return false;

    return true;
}

int check(int r, int c)
{
    int cur = board[r][c];

    if (cur == 0)
        return 0;

    for (int i = 1; i <= 4; i++)
    {
        if (r + i > 19)
            break;

        if (cur != board[r + i][c])
            break;

        if (i == 4 && checkNext(r, c, -1, 0) && checkNext(r + i, c, 1, 0))
            return cur;
    }

    for (int i = 1; i <= 4; i++)
    {
        if (c + i > 19)
            break;

        if (cur != board[r][c + i])
            break;

        if (i == 4 && checkNext(r, c, 0, -1) && checkNext(r, c + i, 0, 1))
            return cur;
    }

    for (int i = 1; i <= 4; i++)
    {
        if (r + i > 19 || c + i > 19)
            break;

        if (cur != board[r + i][c + i])
            break;

        if (i == 4 && checkNext(r, c, -1, -1) && checkNext(r + i, c + i, 1, 1))
            return cur;
    }

    for (int i = 1; i <= 4; i++)
    {
        if (r - i < 1 || c + i > 19)
            break;

        if (cur != board[r - i][c + i])
            break;

        if (i == 4 && checkNext(r, c, 1, -1) && checkNext(r - i, c + i, -1, 1))
            return cur;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
        {
            cin >> board[i][j];
        }

    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
        {
            if (check(i, j) != 0)
            {
                cout << check(i, j) << endl;
                cout << i << ' ' << j;
                return 0;
            }
        }
    cout << 0 << endl;
}
