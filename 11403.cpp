#include <iostream>

using namespace std;

int N;
bool board[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (board[i][k] && board[k][j])
                    board[i][j] = true;
            }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}