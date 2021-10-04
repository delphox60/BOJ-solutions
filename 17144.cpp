#include <iostream>
#include <utility>
#include <queue>

#define X first
#define Y second

using namespace std;

int N, M;
int T;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> ac1, ac2;

int board[55][55];
int sprd[55][55];

long long countDirt()
{
    long long result = 2;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            result += board[i][j];
    return result;
}

void setSprd()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            sprd[i][j] = 0;
    return;
}

void spread()
{
    setSprd();

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (board[i][j] >= 5)
            {
                int sp = board[i][j] / 5;
                for (int dir = 0; dir < 4; dir++)
                {
                    if (i + dx[dir] >= 1 && i + dx[dir] <= N && j + dy[dir] >= 1 && j + dy[dir] <= M && board[i + dx[dir]][j + dy[dir]] != -1)
                    {
                        sprd[i + dx[dir]][j + dy[dir]] += sp;
                        board[i][j] -= sp;
                    }
                }
            }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (sprd[i][j])
                board[i][j] += sprd[i][j];
        }
}

void circulate()
{
    int tmpX = ac1.X - 1;
    int tmpY = ac1.Y;

    while (tmpX != 1)
    {
        board[tmpX][tmpY] = board[tmpX - 1][tmpY];
        tmpX--;
    }
    while (tmpY != M)
    {
        board[tmpX][tmpY] = board[tmpX][tmpY + 1];
        tmpY++;
    }
    while (tmpX != ac1.X)
    {
        board[tmpX][tmpY] = board[tmpX + 1][tmpY];
        tmpX++;
    }
    while (tmpY != ac1.Y)
    {
        board[tmpX][tmpY] = board[tmpX][tmpY - 1];
        tmpY--;
    }
    board[ac1.X][ac1.Y + 1] = 0;

    tmpX = ac2.X + 1;
    tmpY = ac2.Y;

    while (tmpX != N)
    {
        board[tmpX][tmpY] = board[tmpX + 1][tmpY];
        tmpX++;
    }
    while (tmpY != M)
    {
        board[tmpX][tmpY] = board[tmpX][tmpY + 1];
        tmpY++;
    }
    while (tmpX != ac2.X)
    {
        board[tmpX][tmpY] = board[tmpX - 1][tmpY];
        tmpX--;
    }
    while (tmpY != ac2.Y + 1)
    {
        board[tmpX][tmpY] = board[tmpX][tmpY - 1];
        tmpY--;
    }
    board[ac2.X][ac2.Y + 1] = 0;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -1 && board[i - 1][j] == -1)
            {
                ac1.X = i - 1;
                ac1.Y = j;
                ac2.X = i;
                ac2.Y = j;
            }
        }
    for (int i = 0; i < T; i++)
    {
        spread();
        circulate();
    }
    cout << countDirt() << "\n";

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //         cout << board[i][j] << ' ';
    //     cout << '\n';
    // }

    return 0;
}