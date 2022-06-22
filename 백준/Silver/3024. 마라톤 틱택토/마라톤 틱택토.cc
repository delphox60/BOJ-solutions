#include <iostream>
#include <cstring>

using namespace std;

int n;
char board[31][31];
char winner = '.';

void search(int x, int y)
{
    char cur = board[x][y];

    if (x + 2 < n)
    {
        if (cur == board[x + 1][y] && board[x + 1][y] == board[x + 2][y])
        {
            winner = cur;
            return;
        }
    }

    if (y + 2 < n)
    {
        if (cur == board[x][y + 1] && board[x][y + 1] == board[x][y + 2])
        {
            winner = cur;
            return;
        }
    }

    if (x + 2 < n && y + 2 < n)
    {
        if (cur == board[x + 1][y + 1] && board[x + 1][y + 1] == board[x + 2][y + 2])
        {
            winner = cur;
            return;
        }
    }

    if (x - 2 >= 0 && y + 2 < n)
    {
        if (cur == board[x - 1][y + 1] && board[x - 1][y + 1] == board[x - 2][y + 2])
        {
            winner = cur;
            return;
        }
    }
}

bool checkRow(int r)
{
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (board[r][i] == board[r][i - 1])
            cnt++;
        else
            cnt = 1;
        if (board[r][i] == '.')
            cnt = 1;
        if (cnt >= 3)
        {
            winner = board[r][i];
            return true;
        }
    }
    return false;
}

bool checkCol(int c)
{
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (board[i][c] == board[i - 1][c])
            cnt++;
        else
            cnt = 1;
        if (board[i][c] == '.')
            cnt = 1;
        if (cnt >= 3)
        {
            winner = board[i][c];
            return true;
        }
    }
    return false;
}

bool checkCross(int x, int y)
{
    int cnt = 1;
    for (int i = x + 1; i < n; i++)
        for (int j = y + 1; j < n; j++)
        {
            if (board[i][j] == board[i - 1][j - 1])
                cnt++;
            else
                cnt = 1;
            if (board[i][j] == '.')
                cnt = 1;
            if (cnt >= 3)
            {
                winner = board[i][j];
                return true;
            }
        }

    cnt = 1;
    for (int i = x - 1; i >= 0; i--)
        for (int j = y + 1; j < n; j++)
        {
            if (board[i][j] == board[i + 1][j - 1])
                cnt++;
            else
                cnt = 1;
            if (board[i][j] == '.')
                cnt = 1;
            if (cnt >= 3)
            {
                winner = board[i][j];
                return true;
            }
        }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < n; j++)
            board[i][j] = str[j];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     checkCol(i);
    //     checkRow(i);
    //     checkCross(0, i);
    //     checkCross(i, 0);
    //     checkCross(n - 1, i);
    // }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            search(i, j);
            if (winner != '.')
                goto b;
        }
b:
    if (winner == '.')
        cout << "ongoing";
    else
        cout << winner;
}