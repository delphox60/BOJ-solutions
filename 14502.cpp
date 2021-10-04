#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N,
    M;
int board[10][10];
int tmp[10][10];
int maxval = 0;
queue<pair<int, int>> q;

int countArea();

void wall(int cur, int k, int x, int y)
{
    if (cur == k)
    {
        maxval = max(countArea(), maxval);
        return;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if ((i > x || (i == x && j >= y)) && board[i][j] == 0)
            {
                board[i][j] = 1;
                wall(cur + 1, k, i, j);
                board[i][j] = 0;
            }
        }
    return;
}

void spread(int x, int y)
{
    q.push({x, y});
    while (!q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (X + dx[i] < 1 || X + dx[i] > N || Y + dy[i] < 1 || Y + dy[i] > M || tmp[X + dx[i]][Y + dy[i]] != 0)
                continue;

            q.push({X + dx[i], Y + dy[i]});
            tmp[X + dx[i]][Y + dy[i]] = -1;
        }
    }
    return;
}

int countArea()
{
    int result = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            tmp[i][j] = board[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (board[i][j] == 2)
                spread(i, j);
        }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (tmp[i][j] == 0)
                result++;
        }
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];

    wall(0, 3, 0, 0);

    cout << maxval << "\n";

    return 0;
}