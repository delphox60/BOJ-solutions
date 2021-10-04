#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int days[1002][1002];
    int board[1002][1002];

    for (int i = 0; i < 1002; i++)
    {
        for (int j = 0; j < 1002; j++)
        {
            days[i][j] = -1;
            board[i][j] = -1;
        }
    }

    int N, M;
    cin >> N >> M;
    queue<pair<int, int>> q;
    pair<int, int> cur;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                q.push({i, j});
                days[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        int day = days[cur.first][cur.second] + 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || board[nx][ny] == -1 || days[nx][ny] != -1)
                continue;

            days[nx][ny] = day;
            q.push({nx, ny});
        }
    }

    int max = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (days[i][j] == -1 && board[i][j] != -1)
            {
                cout << -1 << "\n";
                return 0;
            }
            if (max <= days[i][j])
            {
                max = days[i][j];
            }
        }
    }
    cout << max << "\n";
    return 0;
}