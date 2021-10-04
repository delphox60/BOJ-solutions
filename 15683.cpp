#include <iostream>

using namespace std;

int board[8][8];
int n, m;
int dksd;
int minval = 0;

void func1(int x, int y, int type)
{
    switch (type)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
}

void func(int x, int y)
{
    if (x == m && y == n)
    {
        if (minval <= dksd)
            minval = dksd;
        return;
    }

    switch (board[x][y])
    {
    case 1:

        break;

    default:
        break;
    }

    if (y == m)
        func(x + 1, 0);
    else
        func(x, y + 1);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[n][m];
        }
    }
}