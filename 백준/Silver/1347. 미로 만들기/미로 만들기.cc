#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int d = 0;
vector<vector<bool>> board(101, vector<bool>(101, false));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int positionX = 50;
int positionY = 50;

void left()
{
    d += 3;
    d %= 4;
    return;
}

void right()
{
    d += 1;
    d %= 4;
    return;
}

void front()
{
    board[positionX][positionY] = true;
    positionX += dx[d];
    positionY += dy[d];
    board[positionX][positionY] = true;
    return;
}

bool checkRow(int r)
{
    for (int i = 0; i <= 100; i++)
        if (board[r][i])
            return true;
    return false;
}

bool checkCol(int c)
{
    for (int i = 0; i <= 100; i++)
        if (board[i][c])
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;

    cin >> n;
    cin >> s;

    board[positionX][positionY] = true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'F')
            front();
        else if (s[i] == 'R')
            right();
        else if (s[i] == 'L')
            left();
    }

    int sx = 0;
    int sy = 0;
    int ex = 100;
    int ey = 100;

    while (!checkRow(sx))
        sx++;
    while (!checkRow(ex))
        ex--;
    while (!checkCol(sy))
        sy++;
    while (!checkCol(ey))
        ey--;

    for (int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)
        {
            if (board[i][j])
                cout << ".";
            else
                cout << "#";
        }
        cout << endl;
    }
    return 0;
}