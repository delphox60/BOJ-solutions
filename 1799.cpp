#include <iostream>

using namespace std;

int board[10][10];
int N;
int cnt = 0;
int maxval = 0;
int cond1[20];
int cond2[20];
int lastx[2];
int lasty[2];

void func(int x, int y, int bw)
{
    if (x == lastx[bw] && y == lasty[bw])
    {
        if (maxval <= cnt)
            maxval = cnt;
        return;
    }

    for (int i = x; i < N; i++)
    {
        for (int j = (i == x ? y : 0); j < N; j++)
        {
            if (board[i][j] && cond1[i + j] && cond2[i - j + N - 1] && (i + j) % 2 == bw)
            {
                board[i][j] = 0;
                cond1[i + j] = 0;
                cond2[i - j + N - 1] = 0;
                cnt++;

                func(i, j, bw);

                board[i][j] = 1;
                cond1[i + j] = 1;
                cond2[i - j + N - 1] = 1;
                cnt--;
            }
        }
    }
    if (maxval <= cnt)
        maxval = cnt;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cond1[i] = 1;
        cond2[i] = 1;
        cond1[N + i] = 1;
        cond2[N + i] = 1;

        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
            {
                lastx[(i + j) % 2] = i;
                lasty[(i + j) % 2] = j;
            }
        }
    }
    int result = 0;

    func(0, 0, 1);
    result += maxval;

    maxval = 0;

    func(0, 0, 0);
    result += maxval;

    cout << result << "\n";
    return 0;
}