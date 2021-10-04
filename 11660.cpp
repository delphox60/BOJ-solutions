#include <iostream>

using namespace std;

int a[1030][1030];
int d[1030][1030];
int N;
int M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= N; i++)
        d[i][1] = a[i][1];

    d[1][0] = 0;
    d[0][1] = 0;
    d[0][0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
            d[i][j] = d[i][j - 1] + a[i][j];
        d[i][0] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;

        for (int i = x1; i <= x2; i++)
        {
            result += d[i][y2] - d[i][y1 - 1];
        }

        cout << result << "\n";
    }

    return 0;
}