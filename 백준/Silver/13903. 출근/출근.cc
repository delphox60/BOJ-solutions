#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int, int>

using namespace std;

int n, m, r;
int dx[10];
int dy[10];
bool visited[1000][1000];
bool sero[1000][1000];
int result = -1;

queue<pair<pii, int>> q;

void bfs()
{
    int nx, ny;

    while (!q.empty())
    {
        pii cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (cur.first == n - 1)
        {
            result = time;
            return;
        }

        for (int i = 0; i < r; i++)
        {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] || !sero[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push({{nx, ny}, time + 1});
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> sero[i][j];
            visited[i][j] = false;
        }

    cin >> r;
    for (int i = 0; i < r; i++)
        cin >> dx[i] >> dy[i];

    for (int i = 0; i < m; i++)
        if (!visited[0][i] && sero[0][i])
        {
            q.push({{0, i}, 0});
            visited[0][i] = true;
        }
    bfs();

    cout << result;
}