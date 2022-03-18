#include <iostream>
#include <vector>

using namespace std;

int n, m;

int he[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> dp(501, vector<int>(501, -1));

int get_roots(int x, int y)
{
    int &ret = dp[x][y];
    if (ret >= 0)
        return ret;

    if (x == 0 && y == 0)
        return dp[x][y] = 1;

    dp[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (he[nx][ny] > he[x][y])
            dp[x][y] += get_roots(nx, ny);
    }
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> he[i][j];

    cout << get_roots(n - 1, m - 1) << '\n';
}