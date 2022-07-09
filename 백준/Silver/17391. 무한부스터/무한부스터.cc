#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int, int>

using namespace std;

// bool visited[300][300];
int dp[300][300];
int arr[300][300];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }

    dp[0][0] = 0;

    queue<pii> q;

    q.push({0, 0});

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= arr[cur.first][cur.second]; j++)
            {
                int nx = cur.first + dx[i] * j;
                int ny = cur.second + dy[i] * j;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (dp[nx][ny] >= 0)
                    continue;

                dp[nx][ny] = dp[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
    }

    cout << dp[n - 1][m - 1];
}