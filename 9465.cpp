#include <iostream>

using namespace std;
int N;
int sticker[2][100005];
int d[2][100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M;

    cin >> M;
    for (int t = 0; t < M; t++)
    {
        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            cin >> sticker[0][i];
        }
        for (int i = 1; i <= N; i++)
        {
            cin >> sticker[1][i];
        }

        d[0][0] = sticker[0][0];
        d[0][1] = sticker[0][1] + sticker[1][0];
        d[1][0] = sticker[1][0];
        d[1][1] = sticker[1][1] + sticker[0][0];

        for (int i = 2; i <= N; i++)
        {
            d[0][i] = sticker[0][i] + max(d[1][i - 1], d[1][i - 2]);
            d[1][i] = sticker[1][i] + max(d[0][i - 1], d[0][i - 2]);
        }

        cout << max(max(d[0][N], d[0][N - 1]), max(d[1][N], d[1][N - 1])) << "\n";
    }
    return 0;
}