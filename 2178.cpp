#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool board[102][102];
    int distance[102][102];

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < M + 1; j++)
        {
            board[i][j] = 0;
            distance[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < M; j++)
        {
            if (row[j] == '1')
                board[i][j] = 1;
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    int dist = 1;
    pair<int, int> cur;

    distance[0][0] = dist;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        dist = distance[cur.first][cur.second] + 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || !board[nx][ny] || distance[nx][ny] != -1)
                continue;

            distance[nx][ny] = dist;
            q.push({nx, ny});
        }
    }
    cout << distance[N - 1][M - 1] << "\n";
    return 0;
}