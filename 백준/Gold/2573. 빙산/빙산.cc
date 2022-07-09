#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int willBeSolved[301][301];
int board[301][301];
bool visited[301][301];

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void check(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = cr + dir[i][0];
            int nc = cc + dir[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if (board[nr][nc] != 0 && !visited[nr][nc])
                {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
}
void meltIce()
{
    memset(willBeSolved, 0, sizeof(willBeSolved));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (board[nx][ny] == 0)
                {
                    cnt++;
                }
            }
            int val = board[i][j] - cnt;
            if (val > 0)
                willBeSolved[i][j] = val;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = willBeSolved[i][j];
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int time = 0;
    while (true)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j] != 0)
                {
                    check(i, j);
                    cnt++;
                }
            }
        }

        if (cnt == 0)
        {
            cout << 0;
            break;
        }

        else if (cnt >= 2)
        {
            cout << time;
            break;
        }

        time++;

        meltIce();
        memset(visited, false, sizeof(visited));
    }
}