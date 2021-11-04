#include <iostream>

using namespace std;

int n, m;

int diceMove[7][5] = {
    {0, 0, 0, 0, 0},
    {0, 4, 3, 5, 2},
    {0, 4, 3, 1, 6},
    {0, 1, 6, 5, 2},
    {0, 6, 1, 5, 2},
    {0, 4, 3, 6, 1},
    {0, 4, 3, 2, 5}};

int dice[7];

int cmd[1005];

int board[23][23];

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

bool invalid = false;

int roll(int &x, int &y, int d, int &cur)
{
    if (x + dx[d] < 1 || x + dx[d] > n || y + dy[d] < 1 || y + dy[d] > m)
        return -1;

    x += dx[d];
    y += dy[d];

    cur = diceMove[cur][d];

    if (board[x][y] == 0)
        board[x][y] = dice[7 - cur];
    else
        dice[7 - cur] = board[x][y];

    return dice[cur];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    x++;
    y++;
    int k;
    cin >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];

    for (int i = 0; i < 7; i++)
        dice[i] = 0;

    int cur = 1;

    for (int i = 0; i < k; i++)
        cin >> cmd[i];

    for (int i = 0; i < k; i++)
    {
        int op = roll(x, y, cmd[i], cur);
        if (op >= 0)
            cout << op << '\n';
    }
    return 0;
}