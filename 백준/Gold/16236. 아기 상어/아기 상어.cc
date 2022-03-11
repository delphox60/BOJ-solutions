#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int, int>
using namespace std;

int n;

int fish[21][21];
int dist[21][21];
int found[21][21];
bool visited[21][21];
int x, y;
int body = 2;
int eat = 0;

void initarr()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = 0;
            visited[i][j] = false;
            found[i][j] = -1;
        }
}

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

pair<int, int> find()
{
    initarr();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if ((cur.first != x || cur.second != y) && fish[cur.first][cur.second] > 0 && fish[cur.first][cur.second] < body)
            found[cur.first][cur.second] = dist[cur.first][cur.second];

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (!visited[nx][ny] && fish[nx][ny] <= body)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }
    }
    int rx, ry;
    int mind = 400;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (found[i][j] > 0 && found[i][j] < mind)
            {
                mind = found[i][j];
                rx = i;
                ry = j;
            }
        }
    if (mind == 400)
        return {-1, -1};
    return {rx, ry};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> fish[i][j];
            if (fish[i][j] == 9)
            {
                x = i;
                y = j;
                fish[i][j] = 0;
            }
        }

    int cost = 0;

    while (true)
    {
        pii cur = find();
        if (cur.first < 0)
            break;
        eat++;
        if (eat == body)
        {
            body++;
            eat = 0;
        }
        x = cur.first;
        y = cur.second;
        cost += dist[x][y];
        fish[x][y] = 0;
    }
    cout << cost << endl;
}