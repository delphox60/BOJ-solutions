#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int, int>

using namespace std;

int arr[1000][1000];
bool to[1000][1000];
bool visited[1000][1000];

int n, m, k;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y)
{
    queue<pii> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!visited[nx][ny] && to[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, g, b;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> r >> g >> b;
            arr[i][j] = (r + g + b) / 3;
            visited[i][j] = false;
            to[i][j] = false;
        }

    cin >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= k)
                to[i][j] = true;
        }

    int result = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (to[i][j] && !visited[i][j])
            {
                bfs(i, j);
                result++;
            }
        }
    cout << result << endl;
}