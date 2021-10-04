#include <iostream>

using namespace std;

int prmd[505][505];
int sum[505][505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >> prmd[i][j];
    }
    sum[1][1] = prmd[1][1];
    int maxval = sum[1][1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                sum[i][j] = sum[i - 1][j] + prmd[i][j];
            else if (j == i)
                sum[i][j] = sum[i - 1][j - 1] + prmd[i][j];
            else
                sum[i][j] = max(sum[i - 1][j], sum[i - 1][j - 1]) + prmd[i][j];
            if (sum[i][j] >= maxval)
                maxval = sum[i][j];
        }
    }
    cout << maxval << "\n";

    return 0;
}