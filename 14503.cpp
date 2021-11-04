#include <iostream>

using namespace std;

int board[52][52];
int clean[52][52];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            clean[i][j] = 0;

    int n, m;
    cin >> n >> m;

    int x, y, dir;
    cin >> x >> y >> dir;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            clean[i][j] = 0;
        }

    int cnt = 0;

    while (true)
    {
        if (clean[x][y] == 0)
        {
            clean[x][y] = 1;
            cnt++;
        }
        for (int i = 0; i < 4; i++)
        {
            dir = (dir + 3) % 4;
            if (clean[x + dx[dir]][y + dy[dir]] == 0 && board[x + dx[dir]][y + dy[dir]] == 0)
                break;
        }

        if (clean[x + dx[dir]][y + dy[dir]] == 0 && board[x + dx[dir]][y + dy[dir]] == 0)
        {
            x += dx[dir];
            y += dy[dir];
            continue;
        }
        else
        {
            dir = (dir + 1) % 4;
            if (board[x - dx[dir]][y - dy[dir]] == 1)
                break;
            else
            {
                x -= dx[dir];
                y -= dy[dir];
                continue;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
