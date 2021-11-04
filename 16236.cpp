#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int board[22][22];
bool visited[22][22];
int n;
int dist = 0;
int bs_size = 2;
int bs_onaka = 0;
int x, y;
int result = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void set_vstd()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;
    return;
}

bool search(int &x, int &y)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({dist, {x, y}});
    visited[x][y] = true;
    bool ret = false;

    while (!q.empty())
    {
        int local_dist = q.front().first;
        pair<int, int> cur = q.front().second;
        q.pop();

        if (board[cur.first][cur.second] > 0 && board[cur.first][cur.second] < bs_size)
        {
            result += local_dist;
            x = cur.first;
            y = cur.second;
            bs_onaka++;
            if (bs_size == bs_onaka)
            {
                bs_size++;
                bs_onaka = 0;
            }
            board[x][y] = 0;
            ret = true;
            break;
        }

        dist++;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (!visited[nx][ny] && board[nx][ny] <= bs_size)
            {
                visited[nx][ny] = true;
                q.push({dist, {nx, ny}});
            }
        }
    }
    set_vstd();
    dist = 0;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                x = i;
                y = j;
                board[i][j] = 0;
            }
        }
    while (true)
    {
        if (!search(x, y))
            break;
    }
    cout << result << '\n';
    return 0;
}
