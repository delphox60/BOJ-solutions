#include <iostream>

using namespace std;

int n, m;
int r, c;
bool wall[50][50];
bool clean[50][50];
int dir;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;

void exe(int x, int y, int d)
{
    int nd, nx, ny;
    if (!clean[x][y])
    {
        clean[x][y] = true;
        result++;
    }

    for (int i = 1; i <= 4; i++)
    {
        nd = (d + 3 * i) % 4;
        nx = x + dx[nd];
        ny = y + dy[nd];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (wall[nx][ny] || clean[nx][ny])
            continue;
        exe(nx, ny, nd);
        return;
    }
    nx = x - dx[d];
    ny = y - dy[d];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || wall[nx][ny])
        return;
    exe(nx, ny, d);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> dir;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> wall[i][j];
            clean[i][j] = false;
        }
    exe(r, c, dir);
    cout << result;
}