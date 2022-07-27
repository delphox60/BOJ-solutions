#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int m, n, k;
int g_cnt = 0;

bool board[101][101];

void marker(int r1, int r2, int c1, int c2)
{
    for (int i = r1 + 1; i <= r2; i++)
        for (int j = c1 + 1; j <= c2; j++)
            board[i][j] = false;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int x, int y)
{
    g_cnt++;
    queue<pii> q;
    q.push({x, y});
    int cnt = 0;
    board[x][y] = false;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        cnt++;

        for (int d = 0; d < 4; d++)
        {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (!board[nx][ny])
                continue;

            q.push({nx, ny});
            board[nx][ny] = false;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            board[i][j] = true;

    for (int i = 0; i < 101; i++)
    {
        board[i][0] = false;
        board[0][i] = false;
    }

    for (int i = 0; i < k; i++)
    {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        marker(r1, r2, c1, c2);
    }

    vector<int> v;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!board[i][j])
                continue;
            v.push_back(bfs(i, j));
        }

    cout << g_cnt << endl;

    sort(v.begin(), v.end());

    for (int i : v)
        cout << i << ' ';
}