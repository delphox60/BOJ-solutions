#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int a[1005][1005];
int d[1005][1005];
int x[1005];
int y[1005];
vector<int> xList;
vector<int> yList;

int getResult(int x1, int y1)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int e = 0;

    a = d[x1 - 1][y1 - 1];
    b = d[N][y1 - 1] - a;
    c = d[x1 - 1][N] - a;
    e = d[N][N] - b - c - a;

    return max(max(a, b), max(c, e));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> x[i];
        cin >> y[i];

        xList.push_back(x[i]);
        yList.push_back(y[i]);
    }

    if (N == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    sort(xList.begin(), xList.end());
    sort(yList.begin(), yList.end());

    xList.erase(unique(xList.begin(), xList.end()), xList.end());
    yList.erase(unique(yList.begin(), yList.end()), yList.end());

    for (int i = 1; i <= N; i++)
    {
        x[i] = lower_bound(xList.begin(), xList.end(), x[i]) - xList.begin();
        y[i] = lower_bound(yList.begin(), yList.end(), y[i]) - yList.begin();
    }

    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= N + 1; j++)
        {
            a[i][j] = 0;
            d[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++)
        a[x[i] + 1][y[i] + 18] = 1;

    for (int i = 1; i <= N + 1; i++)
    {
        for (int j = 1; j <= N + 1; j++)
        {
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
        }
    }

    int minval = 1005;

    for (int i = 1; i <= N + 1; i++)
        for (int j = 1; j <= N + 1; j++)
            minval = min(getResult(i, j), minval);
    for (int i = 1; i <= N + 1; i++)
        for (int j = 0; j <= N + 1; j++)
            cout << a[i][j] << ' ';
    for (int i = 0; i <= N + 1; i++)
        for (int j = 1; j <= N + 1; j++)
            cout << d[i][j] << ' ';

    cout << minval << "\n";
    return 0;
}