#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N;
char board[105][105];
bool checked[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
            checked[i][j] = 0;
        }
    }

    int rgbArea = 0;
    int rbArea = 0;

    for (int k = 1; k <= N; k++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!checked[k][j])
            {
                rgbArea++;
                q.push({k, j});
                checked[k][j] = 1;
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        if (!checked[cur.first + dx[i]][cur.second + dy[i]] &&
                            cur.first + dx[i] > 0 &&
                            cur.first + dx[i] <= N &&
                            cur.second + dy[i] > 0 &&
                            cur.second + dy[i] <= N &&
                            board[cur.first][cur.second] == board[cur.first + dx[i]][cur.second + dy[i]])
                        {
                            q.push({cur.first + dx[i], cur.second + dy[i]});
                            checked[cur.first + dx[i]][cur.second + dy[i]] = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (board[i][j] == 'R')
                board[i][j] = 'G';
            checked[i][j] = 0;
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!checked[k][j])
            {
                rbArea++;
                q.push({k, j});
                checked[k][j] = 1;
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        if (!checked[cur.first + dx[i]][cur.second + dy[i]] &&
                            cur.first + dx[i] > 0 &&
                            cur.first + dx[i] <= N &&
                            cur.second + dy[i] > 0 &&
                            cur.second + dy[i] <= N &&
                            board[cur.first][cur.second] == board[cur.first + dx[i]][cur.second + dy[i]])
                        {
                            q.push({cur.first + dx[i], cur.second + dy[i]});
                            checked[cur.first + dx[i]][cur.second + dy[i]] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << rgbArea << " "
         << rbArea << "\n";

    return 0;
}