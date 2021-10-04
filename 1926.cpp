#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
    cin >> m >> n;

    bool board[502][502];
    bool visited[502][502];

    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            board[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int max = 0;
    int count = 0;

    int nx, ny;
    int S;

    queue<pair<int, int>> Q;
    pair<int, int> cur;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && board[i][j])
            {
                count++;
                S = 0;

                Q.push({i, j});
                visited[i][j] = 1;

                while (!Q.empty())
                {
                    cur = Q.front();
                    Q.pop();
                    S++;

                    for (int k = 0; k < 4; k++)
                    {
                        nx = cur.X + dx[k];
                        ny = cur.Y + dy[k];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if (visited[nx][ny] || !board[nx][ny])
                            continue;

                        Q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }

                if (max <= S)
                    max = S;
            }
        }
    }
    cout << count << "\n"
         << max << "\n";
    return 0;
}