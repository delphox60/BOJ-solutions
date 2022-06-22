#include <iostream>

using namespace std;

int zero = 0;
int one = 0;
int minusOne = 0;
int board[2200][2200];

bool check(int x1, int x2, int y1, int y2)
{
    int std = board[x1][y1];
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (board[i][j] != std)
                return false;
        }
    }
    return true;
}

void update(int x)
{
    if (x == 0)
        zero++;
    else if (x == 1)
        one++;
    else if (x == -1)
        minusOne++;
    return;
}

void func(int x1, int x2, int y1, int y2, int k)
{
    if (check(x1, x2, y1, y2) || k == 1)
        update(board[x1][y1]);
    else
    {
        k /= 3;

        func(x1, x2 - 2 * k, y1, y2 - 2 * k, k);
        func(x1 + k, x2 - k, y1, y2 - 2 * k, k);
        func(x1 + 2 * k, x2, y1, y2 - 2 * k, k);
        func(x1, x2 - 2 * k, y1 + k, y2 - k, k);
        func(x1 + k, x2 - k, y1 + k, y2 - k, k);
        func(x1 + 2 * k, x2, y1 + k, y2 - k, k);
        func(x1, x2 - 2 * k, y1 + 2 * k, y2, k);
        func(x1 + k, x2 - k, y1 + 2 * k, y2, k);
        func(x1 + 2 * k, x2, y1 + 2 * k, y2, k);
    }
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
            cin >> board[i][j];
    }

    func(1, n, 1, n, n);

    cout << minusOne << "\n";
    cout << zero << "\n";
    cout << one << "\n";

    return 0;
}