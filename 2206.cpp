#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int minDist = 20201254;

queue<pair<int, int>> wall;
queue<pair<int, pair<int, int>>> q;

int board[1005][1005];
int dist[2][1005][1005];
bool visited[2][1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string ip;
        cin >> ip;
        for (int j = 1; j <= M; j++)
        {
            board[i][j] = ip[j - 1] == '0' ? 0 : 1;
            visited[0][i][j] = false;
            visited[1][i][j] = false;
            dist[0][i][j] = 0;
            dist[1][i][j] = 0;
        }
    }
    q.push({0, {1, 1}});
    dist[0][1][1] = 1;
    dist[1][1][1] = 1;
    visited[1][1][1] = true;
    visited[1][1][1] = true;

    while (!q.empty())
    {
        bool breaked = q.front().first;
        int X = q.front().second.first;
        int Y = q.front().second.second;
        int BRD = breaked ? 1 : 0;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (X + dx[i] > N || X + dx[i] < 1 || Y + dy[i] > M || Y + dy[i] < 1 || visited[BRD][X + dx[i]][Y + dy[i]] || (board[X + dx[i]][Y + dy[i]] && breaked))
                continue;
            if (board[X + dx[i]][Y + dy[i]] && !breaked)
            {
                dist[1][X + dx[i]][Y + dy[i]] = dist[0][X][Y] + 1;
                q.push({1, {X + dx[i], Y + dy[i]}});
                visited[1][X + dx[i]][Y + dy[i]] = true;
                continue;
            }
            dist[BRD][X + dx[i]][Y + dy[i]] = dist[BRD][X][Y] + 1;
            q.push({BRD, {X + dx[i], Y + dy[i]}});
            visited[BRD][X + dx[i]][Y + dy[i]] = true;
        }
    }

    if (dist[0][N][M] && dist[1][N][M])
        cout << min(dist[0][N][M], dist[1][N][M]) << "\n";
    else if (!dist[0][N][M] && dist[1][N][M])
        cout << dist[1][N][M] << "\n";
    else if (dist[0][N][M] && !dist[1][N][M])
        cout << dist[0][N][M] << "\n";
    else
        cout << -1 << "\n";

    return 0;
}