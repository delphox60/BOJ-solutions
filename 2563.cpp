
#include <iostream>

using namespace std;

bool board[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            board[i][j] = false;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int i = x; i < x + 10; i++)
            for (int j = y; j < y + 10; j++)
                board[i][j] = true;
    }

    int cnt = 0;

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            cnt += board[i][j];
    cout << cnt << '\n';
    return 0;
}