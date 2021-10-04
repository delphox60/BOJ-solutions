#include <iostream>
#include <cstring>

using namespace std;

bool isFull(int n, int x, int y, int board[64][64])
{
    bool result = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[x + i][y + j] != board[x + i][y + j - 1])
                return false;
        }
        if (i > 0 && board[x + i][y] != board[x + i - 1][y])
            return false;
    }
    return true;
}

void func(int n, int x, int y, int board[64][64])
{
    if (isFull(n, x, y, board) || n == 1)
    {
        cout << board[x][y];
        return;
    }
    cout << "(";
    func(n / 2, x, y, board);
    func(n / 2, x, y + n / 2, board);
    func(n / 2, x + n / 2, y, board);
    func(n / 2, x + n / 2, y + n / 2, board);
    cout << ")";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int board[64][64];

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++)
            board[i][j] = (input[j]) - 48;
    }

    func(n, 0, 0, board);
    return 0;
}