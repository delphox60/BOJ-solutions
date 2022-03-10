#include <iostream>
#include <queue>

using namespace std;

int n, k, l;
bool apple[101][101];
bool snake[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> r;
queue<pair<int, int>> body;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            apple[i][j] = false;
            snake[i][j] = false;
        }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        apple[x][y] = true;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int t;
        char d;
        cin >> t >> d;
        r.push({t, d == 'D' ? 1 : 3});
    }

    int time = 0;
    int curx = 1;
    int cury = 1;
    int dir = 0;
    body.push({curx, cury});
    while (true)
    {
        if (r.front().first == time)
        {
            dir += r.front().second;
            dir %= 4;
            r.pop();
        }

        time++;

        curx += dx[dir];
        cury += dy[dir];

        if (curx < 1 || curx > n || cury < 1 || cury > n)
            break;

        if (snake[curx][cury])
            break;

        snake[curx][cury] = true;
        body.push({curx, cury});

        if (apple[curx][cury])
        {
            apple[curx][cury] = false;
        }
        else
        {
            snake[body.front().first][body.front().second] = false;
            body.pop();
        }
    }
    cout << time << '\n';
}